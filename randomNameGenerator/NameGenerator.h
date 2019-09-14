#pragma once
#include "NameType.h"
#include <string>
#include "RandomNameGenerator.h"
#include "NameFile.h"


class NameGenerator {
public:
	void setType(NameType type);
	void setLength(int length);
	std::string getName();
	NameGenerator();
private:
	RandomNameGenerator randomGenerator;
	NameFile boys;
	NameFile girls;
	NameType type;
	int length;
};

