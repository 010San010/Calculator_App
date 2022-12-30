#include <iostream>
#include <vector>
#include <string>

#include "Check_Fun.h"
using namespace std;
#define all_math_functions

long int ToBinary(long int decNum) {
  string binNum;

  if (SizeCheckDec(decNum) == true)
      return 0;
  if (decNum < 0) {
    decNum = abs(decNum);
    for (int i = 0; i < 10; ++i) {
      binNum.insert(0, 1, decNum % 2 + '0');
      decNum = decNum / 2;
    }
    string negBinNum = "1111111111";
    for (int i = 0; i < 10; ++i) {
      if (negBinNum[i] == binNum[i]) negBinNum[i] = '0';
    }
    return stoi(negBinNum);
  }
  while (decNum >= 1) {
    binNum.insert(0, 1, decNum % 2 + '0');
    decNum = decNum / 2;
  }
  return stoi(binNum);
}

int ToDecimal(long int binNum) {
  int decNum = 0;
  int minus = 1;
  string binInvert;

  if (binNum > 100000000) {
    minus = -1;
    binNum = abs(binNum - 1111111111);
  }
  int temp = binNum;
  while (temp) {
    if (temp % 10 != 0 && temp % 10 != 1) {
      cout << "ERROR: function needs a binary number." << endl;
      return 0;
    }
    binInvert += temp % 10 + '0';
    temp = temp / 10;
  }

  for (int i = 0; i < binInvert.length(); ++i) {
    decNum += static_cast<int>(pow(2, i)) * (binInvert[i] - '0');
  }
  return decNum * minus;
}

long int Add(long int a, long int b) {
  return a + b;
}

long int Substract(long int a, long int b) {
  return a - b;
}

long int Multiply(long int a, long int b) {
  return a * b;
}

long int Divide(long int a, long int b) {
  return a / b;
}

long int And(long int a, long int b) {
  return a & b;
}

long int Or(long int a, long int b) {
  return a | b;
}

long int Xor(long int a, long int b) {
  return a ^ b;
}

long int RShift(long int a, long int b) {
  return a >> b;
}

long int LShift(long int a, long int b) {
  return a << b;
}

long int Not(long int a) {
  return ~a;
}

long int Calculate(long int a, char oper, long int b) {
  switch (oper) {
    case '+':
      return Add(a, b);
    case '-':
      return Substract(a, b);
    case '*':
      return Multiply(a, b);
    case '/':
      return Divide(a, b);

    case 'a':
      return And(a, b);
    case 'o':
      return Or(a, b);
    case 'x':
      return Xor(a, b);
    case 'r':
      return RShift(a, b);
    case 'l':
      return LShift(a, b);

    default:
      cout << "ERROR: the operation is not exist or the wrong format is used."
           << endl;
      return 0;
  }
}

long int Calculate(char oper, long int a) {
  switch (oper) {
    case 'n':
      return Not(a);

    default:
      cout << "ERROR: the operation is not exist or the wrong format is used."
           << endl;
      return 0;
  }
}

int CutAndDoBin(string expression) {
  vector<long int> nums;    // container of operands
  vector<char> operations;  // container of operations(symbols)
  string operand;           // temporal string for writing

  OneTokenExeption(expression, operand);  // case +a..., -a...
  for (int i = 0; i < expression.length(); i) {
    while (('0' <= expression[i]) &&  // checking for NUMBERS
           (expression[i] <= '9')) {
      operand += expression[i];
      ++i;
    }
    if (operand != "") {  // writing
      if ((operand != "+") && (operand != "-")) {  // exeption ++a, --a
        if (SizeCheckBin(operand) == true)
            return 0;
        long int x;
        x = stoi(operand);
        nums.push_back(x);
        operand.clear();
      }
    }
    if (expression[i] == 'b') {  // checking & converting binary numbers
      if (nums.size() == 0) {
        cout << "ERROR: the wrong format is used." << endl;
        return 0;
      }
      nums.back() = ToDecimal(nums.back());
      ++i;
    }
    operations.push_back(expression[i]);
    ++i;
  }
  if (SingleNumberExeption(operations[0]) == true)  // case a
    return nums[0];
  switch (nums.size()) {
    case 0:  // exeption -, +, etc.
      cout << "ERROR: the wrong format is used." << endl;
      return 0;
    case 2:  // final results
      return Calculate(nums[0], operations[0], nums[1]);
    case 1:
      return Calculate(operations[0], nums[0]);

    default:
      cout << "ERROR: the wrong format is used." << endl;
      return 0;
  }
}