#include "SyllableGenerator.h"
#include "RandomUtils.h"

using namespace std;

string SyllableGenerator::generateSyllable(int length) {
	const int MAX_SYLLABLE_SIZE = 8;
	const int MIN_SYLLABLE_SIZE = 2;

	if (length > MAX_SYLLABLE_SIZE) {
		return generateStart() + generateVowel() + generateEnd();
	}

	if (length < MIN_SYLLABLE_SIZE) {
		return "";
	}
	
	string vowel = generateVowel();
	string start = generateStart();
	int lengthSoFar = vowel.length() + start.length();

	if (lengthSoFar > length) {
		return vowel;
	}

	string end = generateEnd();
	lengthSoFar += end.length();
	if (lengthSoFar > length) {
		return start + vowel;
	}
		
	return start + vowel + end;
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

string SyllableGenerator::generateStart() const
{
	return generateFromList(starts, startBlankChance);
}

string SyllableGenerator::generateVowel() const
{
	return RandomUtils::getRandomItem(vowels);
}

string SyllableGenerator::generateEnd() const
{
	return generateFromList(ends, endBlankChance);
}

std::string SyllableGenerator::generateFromList(std::vector<std::string> list, float chanceForBlank) {
	if (RandomUtils::getRandomFloat() < chanceForBlank) {
		return "";
	}
	return RandomUtils::getRandomItem(list);
}

