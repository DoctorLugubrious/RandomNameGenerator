#include "RandomNameGenerator.h"
#include "NumGetter.h"
#include <iostream>
using namespace std;

string RandomNameGenerator::getName(int maxLength) {

	string newSyllable = syllableGenerator.generateSyllable(maxLength);
	string name = "";

	while (name.length() + newSyllable.length() <= (size_t)maxLength && !newSyllable.empty()) {
		name += newSyllable;
		newSyllable = syllableGenerator.generateSyllable(maxLength - name.length());
	}

	return name;
}
