#include "InputProcessor.h"
#include <string>
#include <iostream>
#include "NameType.h"
#include "NameTypePrinter.h"
#include "NumGetter.h"
#include <unordered_set>

using namespace std;

void InputProcessor::main() {

	int maxSize = 0;
	string name = "";
	char userInput = '\0';

	cout << "\t---\tThe random name generator\t---" << endl;

	generator.setType(NameTypePrinter::getUserInput());
	generator.setLength(NumGetter::getNum("What is the maximum number of characters?"));
	printHelpMessage();

	const unordered_set<char> validInputs({'q', 't', 'l', 'g'});

	while (userInput != 'q') {
		cout << ">";
		cin >> userInput;

		while (validInputs.find(userInput) == validInputs.end()) {
			printHelpMessage();
			cout << "Invalid input. New Input :";
			cin >> userInput;
		}

		if (userInput == 'q') {
			return;
		}
		else if (userInput == 't') {
			generator.setType(NameTypePrinter::getUserInput());
		}
		else if (userInput == 'l') {
			generator.setLength(NumGetter::getNum("New maximum length: "));
		}
		else if (userInput == 'g') {
			cout << generator.getName() << endl;
		}

		userInput = '\0';
	} 
}

void InputProcessor::printHelpMessage() {
	cout << "usage: \n" <<
		"\tq: quit\n" <<
		"\tt: set type\n" <<
		"\tl: set length\n" <<
		"\tg: generate name" << endl;
}
