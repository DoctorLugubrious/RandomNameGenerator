#pragma once
#include <string>
#include <vector>
#include<exception>

class SyllableGenerator {
public:
	std::string generateSyllable(int length);
	SyllableGenerator();
private:
	std::string generateStart();
	std::string generateVowel();
	std::string generateEnd();
	static std::string generateFromList(std::vector<std::string> list, float chanceForBlank);

	static constexpr float startBlankChance = 0.3f;
	static constexpr float endBlankChance = 0.5f;
	std::vector<std::string> starts;
	std::vector<std::string> vowels;
	std::vector<std::string> ends;
};

