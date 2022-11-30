#include <iostream>
#include <string>
#include "Header.h"
using namespace std;

int main() {
  string label;

  cout << "Calculator Console Application" << endl << endl;
  cout << "Please enter the operation to perform." << endl
       << "Format : a+b | a-b | a*b | a/b | as | af " << endl
       << endl;
  cout << "If you want to exit the application, enter the command EXIT."
       << endl;
  cout << "Enter HELP to get more info." << endl << endl;

  for (int i = 0; i == 0; i) {
    cin >> label;
    if (label == "help") {
      cout << endl
           << "+ - add       | % - 0.05x      | s - sine      | "
              "g - base 10 logarithm"
           << endl
           << "- - substract | ^ - power      | c - cosine    | "
              "n - base e logarithm"
           << endl
           << "* - multiply  | q - sqare root | t - tangent   | "
              "f - factorial"
           << endl
           << "/ - division  | b - cubic root | o - cotangent" << endl
           << endl
           << endl;
      continue;
    } else if (label == "exit")
      i = 1;

      cout << "Answer is: " << CutAndDo(label);
      cout << endl << endl;
      continue;

  }

  return 0;
}