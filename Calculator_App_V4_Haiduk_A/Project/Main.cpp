#include <iostream>
#include <string>

#include "Output_Fun.h"
using namespace std;

int main() {
  int modeCode = 0;

  cout << "Calculator Console Application\n" << endl;
  for (int i = 0; i == 0; i) {
    cout << "Select mode:\n"
         << endl
         << "1 - Real number mode\n"
         << endl
         << "2 - Binary number mode\n"
         << endl
         << "3 - Date calculation mode\n"
         << endl;
    cout << "If you want to exit the application, enter the command EXIT.\n"
         << endl;

    bool exit = false;
    SetModeAndExit(modeCode, exit);
    if (exit)
        return 0;       // exit application
    cout << "Enter the command EXIT to change mode.\n"
         << endl;
    AnswerOutput(modeCode);
  }
}