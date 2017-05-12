cmake_minimum_required(VERSION 3.7)
project(RomanNumerator)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp RomanNumerator.cpp RomanNumerator.hpp)
add_executable(RomanNumerator ${SOURCE_FILES})