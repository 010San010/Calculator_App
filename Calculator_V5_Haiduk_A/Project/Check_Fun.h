#pragma once
#include <string>
#include <vector>

void OneTokenExeption(std::string& expression, std::string& operand);
bool EmptyExpressionExeption(std::string expression);
bool SingleNumberExeption(char operations);
bool MoreOperationTokensExeption(int numsSize, int operationsSize);

bool SizeCheckBin(std::string operand);
bool SizeCheckDec(long int operand);

bool NotIntSymbolsExeption(std::string &expression);