#include <iostream>
#include <string>
#include <vector>

#include "RomanNumerator.hpp"

std::vector<std::string> positiveTests = {
        "V", "X", "II", "I", "IV", "III", "IX", "VI",  // units
        "XV", "XVI", "L", "XL", "XXX", "XVI", "LXVI",  // dozens
        "CCC", "CD", "DCXLIV", "CM", "CMXCIX", "CXI",  // hundreds
        "MMMCMXCIX", "MCXI", "MMCCCXLVII", "MMCCXXII"  // thousands
};

std::vector<std::string> negativeTests = {
        "VIIII", "VX", "IIII", "VVX",  // units
        "XLL", "IIIIC", "LVV", "VIV",  // dozens
        "CLL", "DVVXXX", "XDD", "DMI", // hundreds
        "MMMCMXCX", "XIMXVMMM", "DDC"  // thousands
};

int main() {

    RomanNumerator romanNumerator;

    int positiveErrors = 0; // must be 0
    int negativeErrors = 0; // must be size of negativeTests

    std::cout << "POSITIVE TESTS\n" << std::endl;

    for (int i = 0; i < positiveTests.size(); ++i) {
        try {
            std::cout << positiveTests[i]
                      << " ~ "
                      << romanNumerator.toArabic(positiveTests[i])
                      << std::endl;
        } catch (const std::exception &e) {
            positiveErrors++;
        }
    }

    std::cout << "\nNEGATIVE TESTS\n" << std::endl;

    for (int i = 0; i < negativeTests.size(); ++i) {
        try {
            std::cout << negativeTests[i]
                      << " ~ "
                      << romanNumerator.toArabic(negativeTests[i])
                      << std::endl;
        } catch (const std::exception &e) {
            negativeErrors++;
        }
    }

    std::cout << "\nErrors with positive tests: "
              << positiveErrors
              << " / "
              << positiveTests.size()
              << "\nErrors with negative tests: "
              << negativeErrors
              << " / "
              << negativeTests.size()
              << std::endl;

    return 0;
}