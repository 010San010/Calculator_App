#pragma once
#include <string>
#include <vector>

int ToYears(int &days);
int ToMonths(int &days);
int Calculate(std::vector<int> years, std::vector<int> months,
              std::vector<int> days, char operation);
int CutAndDoDate(std::string expression);