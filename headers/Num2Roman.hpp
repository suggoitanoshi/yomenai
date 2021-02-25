#include <string>
#ifndef _NUM2ROMAN_HPP 
#define _NUM2ROMAN_HPP 

const int vals[] = {50, 40, 10, 9, 5, 4, 1};
const std::string roms[] = {"L", "XL", "X", "IX", "V", "IV", "I"};
std::string Num2Roman(int);

#endif