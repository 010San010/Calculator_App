#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#define all_math_functions

//double Calculate(){}

int main() {
	double x, y, res;
	char symbol = '$';
	string expression;
	string op1, op2;

	ifstream in("Expression.txt", ios::in);
		in >> expression;
		cout << expression << endl;
	in.close();

	for (int i = 0; i < expression.length(); i++) {
		if (('0' <= expression[i]) && (expression[i] <= '9')) {
			if (symbol == '$')
				op1 += expression[i];
			else
			op2 += expression[i];
		}
		else {
			symbol = expression[i];
		}
	}
	cout << op1 << ' ' << op2 << ' ' << symbol;

	x = stod(op1);
	y = stod(op2);

	switch (symbol) {
	case '+':
		res = x + y;
		break;
	case '/':
		res = x / y;
		break;
	}
	cout << endl << res << endl;
}