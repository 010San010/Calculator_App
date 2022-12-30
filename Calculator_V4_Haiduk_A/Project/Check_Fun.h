#pragma once
#include <string>
#include <vector>

void OneTokenExeption(std::string& expression, std::string& operand);
bool SingleNumberExeption(char operations);

bool SizeCheckBin(std::string operand);
bool SizeCheckDec(long int operand);

bool NotIntSymbolsExeption(std::string &expression);