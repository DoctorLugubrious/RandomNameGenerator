#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>


class NameFile {
public:
	std::string getRandom(int length);
	NameFile(std::string filename);
private:
	std::unordered_map<int, std::vector<std::string>> names;
	void addName(std::string name);
};

