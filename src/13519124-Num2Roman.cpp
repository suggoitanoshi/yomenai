#include<iostream>
#include<string>
#include "13519124-Num2Roman.hpp"

std::string Num2Roman(int number){
  int i, j, k = number, l;
  std::string roman = "";
  i = 0;
  while(k > 0){
    // std::cout << k << std::endl;
    // std::cout << k/vals[i] << std::endl;
    l = k/vals[i];
    for(j = 0; j < l; j++){
      roman += roms[i];
      k -= vals[i];
    }
    i++;
  }
  return roman;
}