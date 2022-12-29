#include <iostream>
#include <vector>
#include <string>

#include "Check_Fun.h"
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

double Calculate(double a, char oper, double b) {
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

double Calculate(char oper, double a) {
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

  OneTokenExeption(expression, operand);  // case +a..., -a...
  for (int i = 0; i < expression.length(); i) {
    while ((('0' <= expression[i]) &&
            (expression[i] <= '9')) ||  // checking for NUMBERS
           expression[i] == '.') {
      operand += expression[i];
      ++i;
    }
    if (operand != "") {                           // writing
      if ((operand != "+") && (operand != "-")) {  // exeption ++a, --a
        double x;
        x = stod(operand);
        nums.push_back(x);
        operand.clear();
      }
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
      if (operations.size() > nums.size()) {
        cout << "ERROR: the wrong format is used."
             << endl;  // exeptions a+-b, a*b**, sa-b, /a-b
        return 0;
      }
      bool equal;
      for (int i = 0; i < operations.size() - 1; i++) {
        equal =
            ((operations[i] == '+') ||
             (operations[i] == '-')) ==  // check for equal operations
            ((operations[i + 1] == '+') ||
             (operations[i + 1] == '-'));  // in 3 or more operands expressions
        if (equal == true || operations[i + 1] == '\0') {
          if (i + 1 < nums.size())
            nums[i + 1] = Calculate(nums[i], operations[i], nums[i + 1]);
          else {
            cout << "ERROR: the wrong format is used."
                 << endl;  // exeptions a+-b, a*b**, sa-b, /a-b;
            return 0;
          }
        } else {
          cout << "ERROR: calculations with 2 or more operands must have "
                  "the "
                  "SAME priority."
               << endl;
          return 0;
        }
      }
      return nums[nums.size() - 1];  // the final result
  }
}