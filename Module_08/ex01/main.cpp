#include "Span.hpp"
#include <iostream>
#include <cstdlib>      // rand(), srand()
#include <ctime>        // time()
#include <vector>

int main() {
    // Inicializar semilla para números aleatorios
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    try {
        std::cout << "===== Test subject =====" << std::endl;
        Span sp = Span(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "[EXCEPCIÓN]: " << e.what() << std::endl;
    }

    try {
        std::cout << "===== Test básico =====" << std::endl;
        Span sp(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        // Esto debería lanzar una excepción (Span lleno)
        std::cout << "Añadiendo número extra..." << std::endl;
        sp.addNumber(42);
    }
    catch (const std::exception &e) {
        std::cerr << "[EXCEPCIÓN]: " << e.what() << std::endl;
    }

    try {
        std::cout << "\n===== Test con 10.000 números aleatorios =====" << std::endl;
        Span bigSpan(10000);

        for (int i = 0; i < 10000; ++i) {
            bigSpan.addNumber(std::rand());
        }

        std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "[EXCEPCIÓN]: " << e.what() << std::endl;
    }

    try {
        std::cout << "\n===== Test con rango de iteradores =====" << std::endl;
        Span rangeSpan(10);

        std::vector<int> vec;
        for (int i = 0; i < 10; ++i) {
            vec.push_back(i * 3);
        }

        rangeSpan.addNumber(vec.begin(), vec.end());

        std::cout << "Shortest span: " << rangeSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << rangeSpan.longestSpan() << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "[EXCEPCIÓN]: " << e.what() << std::endl;
    }

    try {
        std::cout << "\n===== Test sin valores suficientes =====" << std::endl;
        Span empty(2);
        empty.addNumber(5);
        std::cout << "Shortest span: " << empty.shortestSpan() << std::endl; // Debe lanzar
    }
    catch (const std::exception &e) {
        std::cerr << "[EXCEPCIÓN]: " << e.what() << std::endl;
    }

    return 0;
}
