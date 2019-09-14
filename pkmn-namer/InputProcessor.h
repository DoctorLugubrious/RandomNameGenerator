#pragma once
#include "NameGenerator.h"
class InputProcessor {
public:
	void main();
private:
	NameGenerator generator;
	void printHelpMessage();
};

