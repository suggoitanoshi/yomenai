#include<iostream>
#include "parser.hpp"

void parse(std::string line, std::vector<std::string> *names){
  int curPos = 0;
  line = line.substr(0, line.size()-1); // abaikan '.'
  int delimPos = line.find(DELIM, curPos);
  while(delimPos != std::string::npos){
    names->push_back(stripWhitespace(line.substr(curPos, delimPos - curPos)));
    curPos = delimPos+1;
    delimPos = line.find(DELIM, curPos);
  }
  names->push_back(stripWhitespace(line.substr(curPos, line.length() - curPos)));
}

std::string stripWhitespace(std::string s){
  int start, end;
  start = s.find_first_not_of(' ');
  end = s.find_last_not_of(' ');
  return s.substr(start, end-start+1);
}