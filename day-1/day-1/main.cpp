#include <iostream> 
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main() {

	// Initialized variables
	vector<char> numbers;

	char firstElement;
	char lastElement;

	string firstAndLastElement;

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

		// Iterates over each string and appends any numbers to a vector
		for (unsigned int i = 0; i < line.size(); ++i) {
			if (isdigit(line[i])) {
				numbers.push_back(line[i]);
			}
		}

		// Stores the first and last element in the vector
		firstElement = numbers.front();
		lastElement = numbers.back();

		// Concatenates the first and last element together
		firstAndLastElement = firstAndLastElement + firstElement + lastElement;

		// Converts them to a number
		inputNumber = stoi(firstAndLastElement);

		// Adds that number to the "total" variable
		total += inputNumber;

		// Clears the "numbers" vector and sets "firstAndLastElement" to an empty string
		numbers.clear();
		firstAndLastElement = "";
	}

	// Closes the file
	inFS.close();

	cout << total;

	return 0;
}