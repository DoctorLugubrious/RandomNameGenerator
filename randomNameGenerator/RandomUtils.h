#pragma once
#include <vector>
class RandomUtils {
public: 
	template<class T>
	static T getRandomItem(std::vector<T> items);
	static float getRandomFloat();
};

template<class T>
inline T RandomUtils::getRandomItem(std::vector<T> items) {
	return items.at(rand() % items.size());
}
