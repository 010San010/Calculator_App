#include <iostream>
#include <string>
#include <vector>

#include "Check_Fun.h"
using namespace std;

int Add(vector<int> years, vector<int> months, vector<int> days) {
  for (int i = 0; i < 2; ++i) {
    switch (months[i]) {
      case 1:  // January
        break;
      case 2:  // February
        if (days[0] > 28) {
          bool isLeap = years[i] % 4 == 0;  // leap year checking
          days[0] = 28 + isLeap;
          cout << "The month date was automatically changed to " << days[0]
               << "." << endl;
        }
        break;

      default:
        bool isLeap = years[i] % 4 == 0;
        days[i] -= 2 - isLeap;  // substracting waste days
        break;
    }
    if (months[0] > 12) {  // checking year limit
      months[0] = 12;
      cout << "The month date was automatically changed to "
              "12(December)."
           << endl;
    }
    if (days[0] > (months[0] % 2) + 30) {  // checking month limit
      days[0] = (months[0] % 2) + 30;
      cout << "The day date was automatically changed to " << days[0] << "."
           << endl;
    }
  }
  int averageDays = (years[0] + years[1]) * 365;
  averageDays += ((years[0] + years[1]) / 4) -
                 (years[0] / 4);  // adding leap years' days

  averageDays += (months[0] + months[1]) * 30;
  averageDays += ((months[0] + months[1]) / 2) -
                 (months[0] / 2);  // adding waste months' days

  averageDays += days[0] + days[1];
  return averageDays;
}

int Substract(vector<int> years, vector<int> months, vector<int> days) {
  int averageDays = 0;

  for (int i = 0; i < 2; ++i) {
    switch (months[i]) {
      case 1:  // January
        break;
      case 2:  // February
        if (days[0] > 28) {
          bool isLeap = years[i] % 4 == 0;  // leap year checking
          days[0] = 28 + isLeap;
          cout << "The month date was automatically changed to " << days[0]
               << "." << endl;
        }
        break;

      default:
        bool isLeap = years[i] % 4 == 0;
        days[i] -= 2 - isLeap;  // substracting waste days
        break;
    }
    if (months[0] > 12) {  // checking year limit
      months[0] = 12;
      cout << "The month date was automatically changed to "
              "12(December)."
           << endl;
    }
    if (days[0] > (months[0] % 2) + 30) {  // checking month limit
      days[0] = (months[0] % 2) + 30;
      cout << "The day date was automatically changed to " << days[0] << "."
           << endl;
    }
  }
  averageDays += (years[0] - years[1]) * 365;  //needs improvements
  averageDays += ((years[0] + years[1]) / 4) -
                 (years[0] / 4);  // adding leap years' days

  averageDays += (months[0] - months[1]) * 30;
  averageDays += ((months[0] + months[1]) / 2) -
                 (months[0] / 2);  // adding waste months' days

  averageDays += days[0] - days[1];
  return averageDays;
}

int Difference(vector<int> years, vector<int> months, vector<int> days) {
  for (int i = 0; i < 2; ++i) {
    switch (months[i]) {
      case 1:  // January
        break;
      case 2:  // February
        if (days[i] > 28) {
          bool isLeap = years[i] % 4 == 0;  // leap year checking
          days[i] = 28 + isLeap;
          cout << "The month date was automatically changed to " << days[i]
               << "." << endl;
        }
        break;

      default:
        bool isLeap = years[i] % 4 == 0;
        days[i] -= 3 - isLeap;  // substracting waste days
        break;
    }
    if (months[i] > 12) {  // checking year limit
      months[i] = 12;
      cout << "The month date was automatically changed to "
              "12(December)."
           << endl;
    }
    if (days[i] > (months[i] % 2) + 30) {  // checking month limit
      days[i] = (months[i] % 2) + 30;
      cout << "The day date is uncorrect. It was automatically changed to "
           << days[i] << "." << endl;
    }
  }
  int averageDays = 0;
  averageDays += (years[1] - years[0]) * 365;
  averageDays +=
      (years[1] / 4) - (years[0] / 4);  // substracting leap years' days

  averageDays += (months[1] - months[0]) * 30;
  averageDays +=
      (months[1] / 2) - (months[0] / 2);  // substracting waste months' days

  averageDays += days[1] - days[0];
  return abs(averageDays);
}

int Calculate(vector<int> years, vector<int> months, vector<int> days,
              char operation) {
  switch (operation) {
    case '/':
      return Difference(years, months, days);
    case '+':
      return Add(years, months, days);
    case '-':
      return Substract(years, months, days);

    default:
      cout << "ERROR: the operation is not exist or the wrong format is used.";
      return 0;
  }
}

int CutAndDoDate(string expression) {
  vector<int> nums;  // date values
  vector<int> days,  // container of date days
              months, // container of date months
              years; // container of date years
  char operation;
  string num;  // temporal string for writing

  if (NotIntSymbolsExeption(expression) == true)   // exeptions +++12.12..., a
      return 0;
  int i = 0;
  for (int n = 0; n < 2; ++n) {
    for (int h = 0; h < 3; ++h) {
      while (('0' <= expression[i]) &&
             (expression[i] <= '9')) {  // checking for NUMBERS
        num += expression[i];
        ++i;
      }
      if (num != "") {  // writing
        int x;
        x = stoi(num);
        nums.push_back(x);
        num.clear();
      }
      ++i;
    }
    if (expression[i - 1] != '\0')  // doing till the end symbol
      operation = expression[i - 1];
    days.push_back(nums[3 * n]);
    months.push_back(nums[1 + (3 * n)]);
    years.push_back(nums[2 + (3 * n)]);
  }
  return Calculate(years, months, days, operation);  // the final result.
}