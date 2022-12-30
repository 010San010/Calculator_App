#pragma once
#include <vector>
#include <string>

template <typename T>
bool EqualTokensCheck(std::vector<T> &nums, std::vector<char> &operations,
                      int i);
template <typename T>
void WriteNumber(std::vector<T> &nums, std::string expression,
                 std::string &operand,
                 int &i);