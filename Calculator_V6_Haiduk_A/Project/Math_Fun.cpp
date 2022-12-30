#include <iostream>
#include <vector>
#include <string>

#include "Check_Fun.h"
#include "Calc_Fun.h"
using namespace std;
#define all_math_functions

double Add(double a, double b) {
    return a + b;
}

double Substract(double a, double b) {
    return a - b;
}

double Multiply(double a, double b) {
    return a * b;
}

double Divide(double a, double b) {
  if (b == 0) {
    cout << "ERROR: division by 0 exeption." << endl;
    return 0;
  }
    return a / b;
}

double Power(double a, double b) {
    return pow(a, b);
}

double Part(double a) {
  return a * 0.05;
}

double SqareRoot(double a) {
  return sqrt(a);
}

double CubicRoot(double a) {
  return cbrt(a);
}

double BaseTenLog(double a) {
  return log10(a);
}

double ELog(double a) {
  return log(a);
}

double Sine(double a) {
  return sin(a);
}

double Cosine(double a) {
  return cos(a);
}

double Tangent(double a) {
  return tan(a);
}

double Cotangent(double a) {
  return 1 / tan(a);
}

double Factorial(double a) {
  if (a != round(a)) {
    cout << "ERROR: real number exeption." << endl;
    return 0;
  }
  int inA = static_cast<int>(a);
  int res = 1;
  for (int i = 0; i < inA; ++i) {
    res *= inA - i;
  }
  return res;
}

double Round(double a) {
    return round(a);
}

double Floor(double a) {
    return floor(a);
}

double Ceil(double a) {
    return ceil(a);
}

double Calculate(double a, char oper, double b) {  // binary operations
  switch (oper) {
    case '+':
      return Add(a, b);
    case '-':
      return Substract(a, b);
    case '*':
      return Multiply(a, b);
    case '/':
      return Divide(a, b);
    case '^':
      return Power(a, b);

    default:
      cout << "ERROR: the operation is not exist or the wrong format is used."
           << endl;
      return 0;
  }
}

double Calculate(char oper, double a) {  // unary operations
  switch (oper) {
    case '%':
      return Part(a);
    case 'q':
      return SqareRoot(a);
    case 'b':
      return CubicRoot(a);
    case 'g':
      return BaseTenLog(a);
    case 'n':
      return ELog(a);

    case 's':
      return Sine(a);
    case 'c':
      return Cosine(a);
    case 't':
      return Tangent(a);
    case 'o':
      return Cotangent(a);
    case 'f':
      return Factorial(a);
    case 'r':
      return Round(a);
    case 'l':
      return Floor(a);
    case 'i':
      return Ceil(a);

    default:
      cout << "ERROR: the operation is not exist or the wrong format is used."
           << endl;
      return 0;
  }
}

double CutAndDo(string expression) {
  vector<double> nums;      // container of operands
  vector<char> operations;  // container of operations(symbols)
  string operand;           // temporal string for writing

  if (EmptyExpressionExeption(expression) == true)
      return 0;
  OneTokenExeption(expression, operand);  // case +a..., -a...
  for (int i = 0; i < expression.length(); i) {
    if (ReadNumberMath(expression, operand, i)) {
      double x;  // temporal variable for writing
      x = stod(operand);
      nums.push_back(x);
      operand.clear();
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
      return Calculate(operations[0], nums[0]);
    default:
      if (MoreOperationTokensExeption(nums.size(), operations.size()))
          return 0;  // exeptions a+-b, a*b**, sa-b, /a-b
      for (int i = 0; i < operations.size() - 1; ++i) {
        if (EqualTokensCheck(nums, operations, i))
          nums[i + 1] = Calculate(nums[i], operations[i], nums[i + 1]);
        else
          return 0;
      }
      return nums[nums.size() - 1];  // the final result with 2 or more
  }
}