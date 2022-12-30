#include <vector>
#include <string>
#include <iostream>

#include "Calc_Fun.h"
using namespace std;

template<typename T>
bool EqualTokensCheck(vector<T> &nums, vector<char> &operations, int i) {
  bool equal;
  equal = ((operations[i] == '+') ||
           (operations[i] == '-')) ==     // check for equal operations
          ((operations[i + 1] == '+') ||  // in 3 or more operands expressions
           (operations[i + 1] == '-'));
  if (equal == true || operations[i + 1] == '\0') {
    if (i + 1 < nums.size())
      return true;
    else {
      cout << "ERROR: the wrong format is used."
           << endl;  // exeptions a+-b, a*b**, sa-b, /a-b;
      return false;
    }
  } else {
    cout << "ERROR: calculations with 2 or more tokens must have "
            "the "
            "SAME priority."
         << endl;
    return false;
  }
}
template bool EqualTokensCheck(vector<double> &nums, vector<char> &operations,
                               int i);
template bool EqualTokensCheck(vector<long> &nums, vector<char> &operations,
                               int i);
template bool EqualTokensCheck(vector<int> &nums, vector<char> &operations,
                               int i);

bool ReadNumberMath(string expression, string &operand, int &i) {
  while ((('0' <= expression[i]) &&
          (expression[i] <= '9')) ||  // checking for NUMBERS
         expression[i] == '.') {
    operand += expression[i];
    ++i;
  }
  if (operand != "") {                           // writing
    if ((operand != "+") && (operand != "-")) {  // exeption ++a, --a
      return true;
    }
  }
  return false;
}

bool ReadNumber(string expression, string &operand, int &i) {
  while (('0' <= expression[i]) &&
          (expression[i] <= '9')) {  // checking for NUMBERS
    operand += expression[i];
    ++i;
  }
  if (operand != "") {                           // writing
    if ((operand != "+") && (operand != "-")) {  // exeption ++a, --a
      return true;
    }
  }
  return false;
}