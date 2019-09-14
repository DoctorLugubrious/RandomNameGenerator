#include "RandomUtils.h"

float RandomUtils::getRandomFloat() {
	return (float)rand() / (float)RAND_MAX;
}
