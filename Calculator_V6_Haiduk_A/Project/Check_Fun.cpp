#include <iostream>
#include <string>
#include <vector>
using namespace std;

//------------------DEFAULT EXEPTIONS---------------------

void OneTokenExeption(string &expression, string &operand) {  
  if ((expression[0] == '+') || (expression[0] == '-')) {
    operand = expression[0];  // case +a..., -a...
    expression.erase(0, 1);
  }
}

bool EmptyExpressionExeption(string expression) {
  if (expression == "\0") {
    cout << "ERROR: the wrong format is used.";
    return true;
  }
  return false;
}

bool SingleNumberExeption(char operation) {  // case a
  if (operation == '\0')
    return true;
  return false;
}

bool MoreOperationTokensExeption(int numsSize, int operationsSize) {
  if (operationsSize > numsSize) {
    cout << "ERROR: the wrong format is used."
         << endl;  // exeptions a+-b, a*b**, sa-b, /a-b
    return true;
  }
  return false;
}

//-----------------BINARY MODE EXEPTIONS------------------

bool SizeCheckBin(string operand) {
  if (operand.length() > 10) {  // not more than 10 symbols
    cout << "ERROR: the number is out of range." << endl;
    return true;
  }
  return false;
}

bool SizeCheckDec(long operand) {
  int digit = 0;
  int temp = operand;
  while (temp % 10) {
    temp = temp / 10;
    ++digit;
  }
  if (digit > 4) {  // not more than 4 symbols
    cout << "ERROR: the number is out of range." << endl;
    return true;
  }
  return false;
}

//------------DATA CALCULATION MODE EXEPTIONS-------------

bool NotIntSymbolsExeption(std::string &expression) {
  while (('0' >= expression[0]) ||
         (expression[0] >= '9')) {  // exeption +++12.12...
    expression.erase(0, 1);
    if (expression[0] == '\0') {  // exeption  +, -, /
      cout << "ERROR: the wrong format is used." << endl;
      return true;
    }
  }
  return false;
}