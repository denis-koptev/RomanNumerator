//
// Created by Koptev Denis
// Peter the Great St.Petersburg Polytechnic University
// Saint Petersburg, 2017
//

#include <stdexcept>
#include "RomanNumerator.hpp"

int RomanNumerator::toArabic(const std::string &roman) {
    currentRoman = roman;

    int thousands = parseThousands();
    int hundreds = parseHundreds();
    int dozens = parseDozens();
    int units = parseUnits();

    if (currentRoman.size() != 0) {
        throw std::invalid_argument("Wrong input roman number");
    }

    return thousands * 1000 + hundreds * 100 + dozens * 10 + units;
}

int RomanNumerator::parseThousands() {
    int thousands = 0;

    while (currentRoman.size() != 0 &&
            currentRoman.front() == 'M' && thousands < 3) {
        thousands++;
        currentRoman.erase(currentRoman.begin());
    }

    return thousands;
}

int RomanNumerator::parseHundreds() {
    return digitTemplate('M', 'D', 'C');
}

int RomanNumerator::parseDozens() {
    return digitTemplate('C', 'L', 'X');
}

int RomanNumerator::parseUnits() {
    return digitTemplate('X', 'V', 'I');
}

// Parsers for hundreds, dozens and units have equal structures

int RomanNumerator::digitTemplate(char high, char med, char low) {
    if (currentRoman.size() == 0) {
        return 0;
    }

    int num = 0;

    bool medWas = false;

    if (currentRoman.front() == med) {
        num += 5;
        medWas = true;
        currentRoman.erase(currentRoman.begin());
    }

    int countX = 0;

    while (currentRoman.size() != 0 &&
           currentRoman.front() == low && countX < 3) {
        num++;
        countX++;
        currentRoman.erase(currentRoman.begin());
    }

    if (currentRoman.size() != 0 && countX == 1 && !medWas) {
        if (currentRoman.front() == med) {
            num += 3;
            currentRoman.erase(currentRoman.begin());
        } else if (currentRoman.front() == high) {
            num += 8;
            currentRoman.erase(currentRoman.begin());
        }
    }

    return num;
}
