#pragma once
#include <unordered_map>
#include <string>
enum NameType { MALE, FEMALE, RANDOM };

const std::unordered_map<NameType, std::string> nameTypeNames = std::unordered_map<NameType, std::string>({
	{MALE, "male"},
	{FEMALE, "female"},
	{RANDOM, "random"},
});