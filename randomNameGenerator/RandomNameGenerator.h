#pragma once
#include <string>
#include "SyllableGenerator.h"
class RandomNameGenerator {
public:
	/*returns a name with length less than or equal to the length parameter*/
	std::string getName(int length);
private:
	SyllableGenerator syllableGenerator;
};

