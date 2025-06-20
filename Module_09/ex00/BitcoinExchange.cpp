#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    std::ifstream data("data.csv");
	if (!data.is_open())
		throw(std::string) "could not open file.";

	std::string line;
	getline(data, line);
	while (getline(data, line)) {
		fillData(line);
	}

	data.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &original) {
	for (std::map<std::string, float>::const_iterator it = original.btcData.begin(); it != original.btcData.end(); ++it) {
		this->btcData[it->first] = it->second;
	}
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &original) {
    if (this != &original) {
		this->btcData.clear();
		for (std::map<std::string, float>::const_iterator it = original.btcData.begin(); it != original.btcData.end(); ++it) {
            this->btcData[it->first] = it->second;
        }
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::fillData(std::string &string) {
	std::stringstream ss(string);
	std::string token;
	std::string dateToken;
	std::string valueToken;
	int tokenCount = 0;

	while (getline(ss, token, ',')) {
		if (tokenCount == 0)
			dateToken = token;
		else if (tokenCount == 1)
			valueToken = token;
		tokenCount++;
	}

	if (tokenCount != 2 || dateToken.empty() || valueToken.empty())
		throw(std::string) "wrong line configuration.";

	this->btcData.insert(std::make_pair(dateToken, atof(valueToken.c_str())));
}

void BitcoinExchange::handleInputFile(std::string& fileName) {
	std::ifstream file(fileName.c_str());
	if (!file.is_open())
		throw(std::string) "could not open file.";

	std::string line;
	if (!std::getline(file, line) || line != "date | value")
		throw(std::string) "invalid first line in data file. Expected 'date | value'.";

	int lineCount = 0;

	while (std::getline(file, line)) {
		++lineCount;

		if (line.empty()) {
			printBadInput(line);
			continue;
		}

		size_t sepPos = line.find('|');
		if (sepPos == std::string::npos || sepPos < 10 || sepPos > 13) {
			printBadInput(line);
			continue;
		}

		std::string dateStr = trim(line.substr(0, sepPos));
		std::string valueStr = trim(line.substr(sepPos + 1));

		int year, month, day;
		if (sscanf(dateStr.c_str(), "%d-%d-%d", &year, &month, &day) != 3) {
			printBadInput(line);
			continue;
		}

		float value;
		char extra;
		if (sscanf(valueStr.c_str(), "%f%c", &value, &extra) != 1) {
			printBadInput(line);
			continue;
		}

		try {
			checkDate(year, month, day);
			checkValues(value);
		} catch (const std::string& err) {
			std::cout << "Error: " << err << std::endl;
			continue;
		}

		this->LineData.date = dateStr;
		this->LineData.value = value;
		findDateAndCalculate();
	}

	if (lineCount == 0)
		throw(std::string) "file is empty.";
}

std::string BitcoinExchange::trim(const std::string& str) {
	size_t first = str.find_first_not_of(" \t");
	size_t last = str.find_last_not_of(" \t");
	if (first == std::string::npos || last == std::string::npos)
		return "";
	return str.substr(first, (last - first + 1));
}

void BitcoinExchange::printBadInput(const std::string& line) {
	std::cout << "Error : bad input => " << line << std::endl;
}

void BitcoinExchange::checkValues(float value) {
    if (value > 1000)
		throw(std::string) "too large a number.";
	if (value < 0)
		throw(std::string) "not a positive a number.";
}

void BitcoinExchange::checkDate(int year, int month, int day) {
	if (month < 1 || month > 12)
		throw std::string("Invalid date: month out of range");

	if (day < 1)
		throw std::string("Invalid date: day out of range");

	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (month == 2 && isLeapYear(year))
		daysInMonth[1] = 29;

	if (day > daysInMonth[month - 1])
		throw std::string("Invalid date: day exceeds days in month");

	if (year < 2009 || (year == 2009 && month == 1 && day < 2))
		throw std::string("Invalid date: minimum supported date is 2009-01-02");

	if (year > 2022 || (year == 2022 && (month > 3 || (month == 3 && day > 29))))
	    throw std::string("Invalid date: maximum supported date is 2022-03-29");
}


bool BitcoinExchange::isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void BitcoinExchange::findDateAndCalculate() {
	std::map<std::string, float>::iterator it = btcData.lower_bound(LineData.date);

	if (it == btcData.end()) {
		--it;
		std::cout << LineData.date << " => " << LineData.value << " = " << LineData.value * it->second << std::endl;
		return;
	}
	if (it->first != LineData.date)
		--it;

	std::cout << LineData.date << " => " << LineData.value << " = " << LineData.value * it->second << std::endl;
}