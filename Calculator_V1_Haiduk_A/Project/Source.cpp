#include <iostream>
using namespace std;
#define all_math_functions ;

double Calculate(double a, char oper, double b) {  // writing a non-number in double A or B gives an UNFIXABLE ERROR
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

        case '%':
          return a * 0.05;
        case '^':
          return pow(a, b);
        case 'q':
          return sqrt(b);
        case 'b':
          return cbrt(b);
        case 'g':
          return log10(b);
        case 'n':
          return log(b);

        case 's':
          return sin(b);
        case 'c':
          return cos(b);
        case 't':
          if ((b - 90) / 180 == 0) {
            cout << "ERROR: tangent have no solution in this point.";
            break;
          }
          return tan(b);
        case 'o':
          if (b / 180 == 0) {
            cout << "ERROR: cotangent have no solution in this point.";
            break;
          }
          return 1 / tan(b);

        default:
          cout << "ERROR: the operation is not exist, the wrong format is "
                  "used or number is out of range." << endl;
          return 0;
  }
}

int main() {
	int x,y;
  char symbol;
        string command;

    cout << "Calculator Console Application" << endl << endl;
    cout << "Enter HELP for more info or KEY + ENTER to continue." << endl;
      cin >> command;
    if (command == "help") {
        cout << endl << "+ - add | - - substract | * - multiply | / - division | "
                     << "% - 0.05x | ^ - power" << endl << endl
                     << "q - sqare root | b - cubic root | g - base 10 logarithm | "
                     "n - base e logarithm" << endl << endl
                     << "s - sinus | c - cosinus | t - tangent | o - cotangent"
                     << endl << endl;
    }

    cout << "Please enter the operation to perform." << endl
         << "Format : a + b | a - b | a * b | a / b | 0 s b | 0 g b " << endl;

    BEGIN:
      cin >> x >> symbol >> y;
      cout << "Result is: " << Calculate(x, symbol, y) << endl << endl;

      cout << "If you want to exit the application, enter the command EXIT,"
              "else push KEY + ENTER to continue." << endl;
      cin >> command;
      cout << endl;
      if (command != "exit") {
        goto BEGIN;
      }
    return 0;
}