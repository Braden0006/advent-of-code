#include <iostream> 
#include <string>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

int main() {

	// Initialized variables
	vector<char> numbers;
	vector<int> numberIndex;
	vector<char> words;
	vector<int> wordIndex;
	vector<string> strings;

	map<string, char> oneToNine = { {"one", '1'}, {"two", '2'}, {"three", '3'}, {"four", '4'}, {"five", '5'}, {"six", '6'}, {"seven", '7'}, {"eight", '8'}, {"nine", '9'} };

	char firstElement;
	char lastElement;
	char lastLetterUsed;

	string firstAndLastElement;
	string stringWord;

	int inputNumber;
	int total = 0;
	int index = 0;

	int temp_num = 0;

	// Initialized input file stream variable
	ifstream inFS;

	// Opens a text file
	inFS.open("day-1-input-2.txt");

	// Checks to see if the text file can be opened
	if (!inFS.is_open()) {
		cout << "Cannot open file data-1-input.txt" << endl;
	}

	// Reads the text file line by line
	string line;
	while (getline(inFS, line)) {

		// Iterates over each string and appends any numbers to a vector
		for (unsigned int i = 0; i < line.size(); ++i) {

			stringWord += line[i];

			if (isdigit(line[i])) {
				numbers.push_back(line[i]);
				numberIndex.push_back(i);
			}

			for (auto key : oneToNine) {
				if (stringWord.find(key.first) != string::npos) {
					strings.push_back(key.first);
					words.push_back(key.second);
					

					// This ensures that no letters are being left out when iterating over words like "oneight"
					lastLetterUsed = stringWord.back();
					stringWord = "";
					stringWord += lastLetterUsed;
				}
			}
		}

		for (unsigned int i = 0; i < wordIndex.size(); ++i) {
			cout << wordIndex[i] << endl;
		}

		cout << endl;

		//for (unsigned int i = 0; i < numberIndex.size(); ++i) {
		//	cout << numberIndex[i] << endl;
		//}


		// Checks to see if the numbers vector is not empty
		if (!numbers.empty() && !words.empty()) {

			if (line.find(numbers.front()) < line.find(strings.front())) {
				firstElement = numbers.front();
			} 
			else {
				firstElement = words.front();
			}

			//cout << line.find(numbers.back()) << endl;
			//cout << line.find(strings.back()) << endl;

			if (line.find(numbers.back()) > line.find(strings.back())) {
				lastElement = numbers.back();
			} 
			else {
				lastElement = words.back();
			}

			// Checks to see if the index of the first and last element of the string are the same number
			if ((numbers.front() == numbers.back()) && (numbers.size() > 1) && (numberIndex.front() < line.find(strings.front())) && (numberIndex.back() > line.find(strings.back()))) {
				lastElement = numbers.back();
			}
			//else {
			//	lastElement = words.back();
			//}


		}
		else if (!words.empty()) {
			firstElement = words.front();
			lastElement = words.back();
		}
		else if (!numbers.empty()) {
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
		numberIndex.clear();
		words.clear();
		strings.clear();

		// Sets variable to an empty string so it can store the elements in the next line
		cout << firstAndLastElement << endl;

		firstAndLastElement = "";
		index = 0;
	}

	// Closes the file
	inFS.close();

	cout << total << endl;

	return 0;
}