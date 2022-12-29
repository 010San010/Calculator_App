#pragma once
#include <string>
#include <vector>

long int ToBinary(long int decNum);
bool SizeCheckBin(std::string operand);
bool SizeCheckDec(long int operand);
int Calculate(int a, char oper, int b);
int Calculate(int a, char oper);
int CutAndDoBin(std::string expression);