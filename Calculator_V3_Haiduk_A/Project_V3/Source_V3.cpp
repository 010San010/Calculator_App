#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define all_math_functions

enum class Operation{ s, u, m, d };

double Calculate(double x, char symbol, double y) {
  switch (symbol) {
     case 's':
       return x + y;
     case 'u':
       return x - y;
     case 'm':
       return x * y;
     case 'd':
       return x / y;

     default:
       cout << "ERROR.";
       return 0;
   }
}

int main() {
  vector<double> nums = {12, 23};
  vector<char> operands = {'m', 'o'};

    cout << Calculate(nums[0], operands[0], nums[1]) << endl;

    system("pause");
}