#define DELIM ','

#include<vector>
#include<string>

#ifndef _PARSER_HPP
#define _PARSER_HPP

void parse(std::string, std::vector<std::string>*);

std::string stripWhitespace(std::string);

#endif