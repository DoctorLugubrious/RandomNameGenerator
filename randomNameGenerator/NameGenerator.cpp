#include "NameGenerator.h"
using namespace std;
void NameGenerator::setType(NameType type) {
	this->type = type;
}

void NameGenerator::setLength(int length) {
	this->length = length;
}

string NameGenerator::getName() {
	switch (type) {
	case RANDOM:
		return randomGenerator.getName(length);
	case MALE:
		return boys.getRandom(length);
	case FEMALE:
		return girls.getRandom(length);
	}
	return "";
}

NameGenerator::NameGenerator(): randomGenerator(), boys("boynames.txt"), girls("girlnames.txt"), length(0), type(RANDOM) {
}
