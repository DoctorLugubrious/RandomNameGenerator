#include "RandomNameGenerator.h"
#include "NumGetter.h"
#include <iostream>
using namespace std;

string RandomNameGenerator::getName(int maxLength) {

	string newSyllable = syllableGenerator.generateSyllable(maxLength);
	string name = "";

	while (name.length() + newSyllable.length() <= maxLength && newSyllable != "") {
		name += newSyllable;
		newSyllable = syllableGenerator.generateSyllable(maxLength - name.length());
		if (newSyllable.length() == 0) {
			cout << "0 syllable" << endl;
		}
	}

	if (name.size() == 0) {
		return "FAKE";
	}

	return name;
}
