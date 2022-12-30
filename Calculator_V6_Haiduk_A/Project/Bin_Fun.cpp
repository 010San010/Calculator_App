#include <iostream>
#include <vector>
#include <string>

#include "Check_Fun.h"
#include "Calc_Fun.h"
using namespace std;
#define all_math_functions

long ToBinary(long decNum) {
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

int ToDecimal(long binNum) {
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

long Add(long a, long b) {
  return a + b;
}

long Substract(long a, long b) {
  return a - b;
}

long Multiply(long a, long b) {
  return a * b;
}

long Divide(long a, long b) {
  return a / b;
}

long And(long a, long b) {
  return a & b;
}

long Or(long a, long b) {
  return a | b;
}

long Xor(long a, long b) {
  return a ^ b;
}

long RShift(long a, long b) {
  return a >> b;
}

long LShift(long a, long b) {
  return a << b;
}

long Not(long a) {
  return ~a;
}

long Calculate(long a, char oper, long b) {
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

long Calculate(char oper, long a) {
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
  vector<long> nums;    // container of operands
  vector<char> operations;  // container of operations(symbols)
  string operand;           // temporal string for writing

  OneTokenExeption(expression, operand);  // case +a..., -a...
  for (int i = 0; i < expression.length(); i) {
    if (ReadNumber(expression, operand, i)) {
      long x;  // temporal variable for writing
      x = stol(operand);
      nums.push_back(x);
      operand.clear();
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
    case 1:
      return Calculate(operations[0], nums[0]);  // the final result with 1 number
    default:
      if (MoreOperationTokensExeption(nums.size(), operations.size())) return 0;
      for (int i = 0; i < operations.size() - 1; ++i) {
        if (EqualTokensCheck(nums, operations, i))
          nums[i + 1] = Calculate(nums[i], operations[i], nums[i + 1]);
        else
          return 0;
      }
      return nums[nums.size() - 1];  // the final result with 2 or more

    
      cout << "ERROR: the wrong format is used." << endl;
      return 0;
  }
}