#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define all_math_functions

double Calculate(double x, char symbol, double y) {
   switch (symbol) {
     case '+':
       return x + y;
     case '-':
       return x - y;
     case '*':
       return x * y;
     case '/':
       return x / y;

     default:
       cout << "ERROR.";
       return 0;
   }
}

double Calculate(double x, char symbol) {
  switch (symbol) {
    case 's':
      return sin(x);

    default:
      cout << "ERROR.";
      return 0;
  }
}

int main() {
  vector<double> nums;
  vector<char> operands;
  string expression;
  string op;

  expression = "12*23/22";

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
      cout << nums[0];
    }
    if (nums.size() > 1) {
      bool typic;
      for (int i = 0; i < operands.size() - 1; i++) {  // needs improvements.
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
    else
      cout << "ERROR: the wrong format is used." << endl;

    cout << nums[nums.size() - 1] << endl;

    system("pause");
}