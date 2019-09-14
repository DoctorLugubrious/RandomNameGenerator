#include "NameTypePrinter.h"
#include "NumGetter.h"
#include <iostream>

using namespace std;

NameType NameTypePrinter::getUserInput() {
	const int NameTypeSize = 3;

	cout << "What type of name do you want to generate?" << endl;

	for (int i = 0; i < NameTypeSize; ++i) {
		cout << "\t(" << i << "): " << nameTypeNames.at((NameType)i) << endl;
	}

	int result = -1;
	while (result < 0 || result > NameTypeSize) {
		result = NumGetter::getNum("Selection: ");
	}

	return (NameType)result;
}
