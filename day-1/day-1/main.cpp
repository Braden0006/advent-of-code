#include <iostream> 
#include <string>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

int main() {

	// Initialized variables
	vector<char> numbers;

	map<string, char> oneToNine = { {"one", '1'}, {"two", '2'}, {"three", '3'}, {"four", '4'}, {"five", '5'}, {"six", '6'}, {"seven", '7'}, {"eight", '8'}, {"nine", '9'} };

	char firstElement{};
	char lastElement{};
	char lastLetterUsed;

	string firstAndLastElement;
	string stringLetter;

	int inputNumber;
	int total = 0;

	// Initialized input file stream variable
	ifstream inFS;

	// Opens a text file
	inFS.open("day-1-input.txt");

	// Checks to see if the text file can be opened
	if (!inFS.is_open()) {
		cout << "Cannot open file data-1-input.txt" << endl;
	}

	// Reads the text file line by line
	string line;
	while (getline(inFS, line)) {

		// Iterates over each stirng and checks to see if a number or a number spelled out as a word appears first
		for (unsigned int i = 0; i < line.size(); ++i) {

			// Keeps track of each letter by appending them to "stringLetter"
			stringLetter += line[i];

			// If the current letter is a number, append it to the numbers vector
			if (isdigit(line[i])) {
				numbers.push_back(line[i]);
			}

			// Compares each string in the oneToNine vector to the string "stringLetter" to see if it contains a number as a string, and appends it to the "numbers" vector
			for (auto key : oneToNine) {
				if (stringLetter.find(key.first) != string::npos) {
					numbers.push_back(key.second);

					// This ensures that no letters are being left out when iterating over words like "oneight"
					lastLetterUsed = stringLetter.back();
					stringLetter = "";
					stringLetter += lastLetterUsed;
				}
			}
		}

		// Checks to see if the numbers vector is not empty
		if (!numbers.empty()) {

			firstElement = numbers.front();
			lastElement = numbers.back();
		}

		// Concatenates the first and last element together
		firstAndLastElement = firstAndLastElement + firstElement + lastElement;

		// Converts them to a number
		inputNumber = stoi(firstAndLastElement);

		// Adds that number to the "total" variable
		total += inputNumber;

		// Clears the "numbers" vector
		numbers.clear();

		// Sets variable to an empty string so it can store the elements in the next line
		firstAndLastElement = "";
	}

	// Closes the file
	inFS.close();

	cout << "Total from all strings: " << total << endl;

	return 0;
}