#include <iostream>
#include <string>

#include "Bin_Fun.h"
#include "Math_Fun.h"
#include "Date_Fun.h"
using namespace std;

//-----------------FORMAT MESSAGES------------------

void FormatMessage1() {
  cout << "Please enter the operation to perform." << endl
       << "Format : x+y | x-y | x+y-z | x | xs | xf\n";
}

void FormatMessage2() {
  cout << "Please enter the operation to perform." << endl
       << "Format : x+y | zb (z - binary) | x-zb | xoy | xn\n";
}

void FormatMessage3() {
  cout << "Please enter the operation to perform." << endl
       << "Format : 01.01.2000/02.02.2001 | 01.01.2000+30.0.10 |"
          " 01.01.2000-30.0.10\n";
}

//-----------------INPUT AND OUTPUT-----------------

void SetModeAndExit(int& modeCode, bool& exit) {
  string label;
  for (int n = 0; n == 0; n) {
    cin >> label;
    cout << endl;
    if (label == "exit") {  // exit application
      exit = true;
      ++n;
      continue;
    }
    if (label[0] > '9') {  // exeptions a, 5, 78, etc.
      cout << "Input is uncorrect. Enter a number"
              "from 1 to 3 or EXIT to leave.\n"
           << endl;
      continue;
    }
    modeCode = stoi(label);
    switch (modeCode) {  // mode choosing
      case 1:
        FormatMessage1();
        break;
      case 2:
        FormatMessage2();
        break;
      case 3:
        FormatMessage3();
        break;

      default:
        cout << "Input is uncorrect. Enter a number "
                "from 1 to 3 or EXIT to leave.\n"
             << endl;
        continue;
    }
    ++n;
  }
}

void AnswerOutput(int modeCode) {
  string label;
  for (int n = 0; n == 0; n) {
    cin >> label;
    cout << endl;
    if (label == "exit") {  // exit mode
      n = 1;
      continue;
    }

    int answerB,
        answerD;
    switch (modeCode) {
      case 1:
        cout << "Answer is: " << CutAndDo(label) << endl << endl;
        break;
      case 2:
        answerB = CutAndDoBin(label);
        cout << "Answer is: decimal - " << answerB
             << "\n           binary - " << ToBinary(answerB)
             << endl << endl;
        break;
      case 3:
        cout << "Answer is: " << CutAndDoDate(label) << " days"
             << endl << endl;
        break;
    }
  }
}