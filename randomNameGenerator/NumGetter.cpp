#include "NumGetter.h"
#include <iostream>

using namespace std;

int NumGetter::getNum(const string& prompt) {
	int result = -1;

	cout << prompt << endl;
	cin >> result;

	while (result < 0 || cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << prompt << endl;
		cin >> result;
	} 
	return result;
}
