#pragma once
#include <vector>
#include <string>

template <typename T>
bool EqualTokensCheck(std::vector<T> &nums, std::vector<char> &operations,
                      int i);
bool ReadNumberMath(std::string expression, std::string &operand, int &i);
bool ReadNumber(std::string expression, std::string &operand, int &i);