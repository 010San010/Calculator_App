#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define all_math_functions ;

double Calculate(double a, char oper, double b) {  
  switch (oper) {
    case '+':
      return a + b;
    case '-':
      return a - b;
    case '*':
      return a * b;
    case '/':
      if (b == 0) {
        cout << "ERROR: division by 0 exeption." << endl;
        break;
      }
      return a / b;
    case '^':
      return pow(a, b);

    default:
      cout << "ERROR: the operation is not exist, the wrong format is "
              "used or number is out of range."
           << endl;
      return 0;
  }
}

double Calculate(char oper, double a) {

  switch (oper) {
    case '%':
      return a * 0.05;
    case 'q':
      return sqrt(a);
    case 'b':
      return cbrt(a);
    case 'g':
      return log10(a);
    case 'n':
      return log(a);

    case 's':
      return sin(a);
    case 'c':
      return cos(a);
    case 't':
      return tan(a);
    case 'o':
      return 1 / tan(a);

    default:
      cout << "ERROR: the operation is not exist, the wrong format is "
              "used or number is out of range."
           << endl;
      return 0;
  }
}

double CutAndDo(string expression) {
  vector<double> nums;
  vector<char> operands;
  string op;

  for (int i = 0; i < expression.length(); i) {
    while ((('0' <= expression[i]) && (expression[i] <= '9')) ||
           expression[i] == '.') {
      op += expression[i];
      i = ++i;
    }
    if (op != "") {
      double x;
      x = stod(op);
      nums.push_back(x);
      op.clear();
    }
      operands.push_back(expression[i]);
      i = ++i;
  }

  if (operands[0] == '\0') {
    return nums[0];
  }
  if (nums.size() > 1) {
    bool typic;
    for (int i = 0; i < operands.size() - 1; i++) {                                     // needs improvements.
      typic = ((operands[i] == '+') || (operands[i] == '-')) ==
              ((operands[i + 1] == '+') || (operands[i + 1] == '-'));
      if (typic == true || operands[i + 1] == '\0')
        nums[i + 1] = Calculate(nums[i], operands[i], nums[i + 1]);
      else {
        cout << "ERROR: calculations with 2 or more operands must have the "
                "SAME priority"
             << endl;
        return 0;
      }
    }
  } else if (nums.size() == 1)
    nums[0] = Calculate(operands[0], nums[0]);
  else {
    cout << "ERROR: the wrong format is used." << endl;
    return 0;
  }

  return nums[nums.size() - 1];
}

int main() {
    string label;

    cout << "Calculator Console Application" << endl << endl;
    cout << "Please enter the operation to perform." << endl
         << "Format : a+b | a-b | a*b | a/b | sb | gb " << endl << endl;
    cout << "If you want to exit the application, enter the command EXIT."
         << endl;
    cout << "Enter HELP for more info." << endl << endl;

    BEGIN:
      cin >> label;
      if (label == "help") {
        cout << endl
             << "+ - add        | % - 0.05x      | s - sinus     | "
                "g - base 10 logarithm" << endl
             << " - - substract | ^ - power      | c - cosinus   | "
                "n - base e logarithm" << endl
             << "* - multiply   | q - sqare root | t - tangent" << endl
             << "/ - division   | b - cubic root | o - cotangent"
             << endl << endl << endl;
        goto BEGIN;
      }
      else if (label != "exit") {
        cout << "Answer is: " << CutAndDo(label);
        cout << endl << endl;
        goto BEGIN;
      }

    return 0;
}