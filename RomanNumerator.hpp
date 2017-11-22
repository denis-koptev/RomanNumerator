//
// Created by Koptev Denis
// Peter the Great St.Petersburg Polytechnic University
// Saint Petersburg, 2017
//

#ifndef ROMAN_NUMERATOR_HPP
#define ROMAN_NUMERATOR_HPP

#include <string>

class RomanNumerator {

public:

    int toArabic(const std::string & roman);

private:

    int parseThousands();
    int parseHundreds();
    int parseDozens();
    int parseUnits();

    int digitTemplate(char high, char med, char low);

    std::string currentRoman;

};


#endif //ROMAN_NUMERATOR_HPP
