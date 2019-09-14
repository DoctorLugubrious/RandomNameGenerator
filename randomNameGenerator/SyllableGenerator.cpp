#include "SyllableGenerator.h"
#include "RandomUtils.h"

using namespace std;

string SyllableGenerator::generateSyllable(int maxLength) {
	const int MAX_SYLLABLE_SIZE = 8;
	const int MIN_SYLLABLE_SIZE = 2;

	if (maxLength > MAX_SYLLABLE_SIZE) {
		return generateStart() + generateVowel() + generateEnd();
	}
	else if (maxLength < MIN_SYLLABLE_SIZE) {
		return "";
	}
	else {
		string vowel = generateVowel();
		string start = generateStart();
		int lengthSoFar = vowel.length() + start.length();

		if (lengthSoFar > maxLength) {
			return vowel;
		}

		string end = generateEnd();
		lengthSoFar += end.length();
		if (lengthSoFar > maxLength) {
			return start + vowel;
		}
		
		return start + vowel + end;
	}
}

SyllableGenerator::SyllableGenerator():
	starts({
		"b","bl","br","ch","dr","d","f","fr","fl","g","gr","gl","h","j","k","kr",
		"kl","l","m","n","p","pl","pr","kw","r","sl","st","str","t","tr","v","vl",
		"w","y","z" }),
	vowels({ "a","ae","ai","au","e","ea","ee","ei","eu","i","ie","o",
			"oi","ou","u" }),
	ends({ "b","lb","rb","ch","rd","d","f","rf","lf","g","rg","lg","h","j",
		"k","rk","lk","l","m","n","p","lp","rp","r","ls","ts","rts","t","rt","v","w","y","z" }) {}

string SyllableGenerator::generateStart() {
	return generateFromList(starts, startBlankChance);
}

string SyllableGenerator::generateVowel() {
	return RandomUtils::getRandomItem(vowels);
}

string SyllableGenerator::generateEnd() {
	return generateFromList(ends, endBlankChance);
}

std::string SyllableGenerator::generateFromList(std::vector<std::string> list, float chanceForBlank) {
	if (RandomUtils::getRandomFloat() < chanceForBlank) {
		return "";
	}
	return RandomUtils::getRandomItem(list);
}

