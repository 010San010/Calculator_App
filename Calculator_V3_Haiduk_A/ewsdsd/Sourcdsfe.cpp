#include <iostream>
using namespace std;

int main() {
	string ex;

BEGIN:
  cin >> ex;
  if (ex != "exit")
	  goto BEGIN;
}