#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <stdlib.h>

struct DataLine {
	float value;
	std::string date;
};

class BitcoinExchange {
    private:
        std::map<std::string, float> btcData;
        DataLine LineData;

        void fillData(std::string &string);
        std::string trim(const std::string& str);
        void printBadInput(const std::string& line);
        void checkValues(float value);
        void checkDate(int year, int month, int day);
        bool isLeapYear(int year);
        void findDateAndCalculate();
        
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &original);
        BitcoinExchange& operator=(const BitcoinExchange &original);
        ~BitcoinExchange();

        const std::map<std::string, float> &getBtcData() const;
        const DataLine &getLineData() const;
        
        void handleInputFile(std::string &fileName);
};

#endif