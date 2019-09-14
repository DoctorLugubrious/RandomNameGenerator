#include "NameFile.h"
#include <iterator>
#include <iostream>
#include "RandomUtils.h"

using namespace std;

string NameFile::getRandom(int length) {
	vector<int> validSizes;
	for (pair<int, vector<string>> value : names) {
		if (value.first <= length) {
			validSizes.push_back(value.first);
		}
	}


	if (validSizes.size() == 0) {
		return "(TOO SHORT; NO NAMES FOUND)";
	}

	vector<string> validNames = names.at(RandomUtils::getRandomItem(validSizes));
	return RandomUtils::getRandomItem(validNames);
}

NameFile::NameFile(string filename) {
	ifstream nameFile(filename);
	vector<string>lines(istream_iterator<string>(nameFile), {});

	for (string line : lines) {
		addName(line);
	}
	nameFile.close();
}

void NameFile::addName(std::string name) {
	int length = name.length();
	if (names.find(length) != names.end()) {
		names.at(length).push_back(name);
	}
	else {
		names.insert(pair<int, vector<string>>(length, vector<string>({ name })));
	}
}


