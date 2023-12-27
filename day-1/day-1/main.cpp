#include <iostream> 
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main() {
	vector<char> numbers;

	char firstElement;
	char secondElement;

	string firstAndSecondElement;

	int inputNumber;

	int total = 0;

	ifstream inFS;

	inFS.open("day-1-input.txt");

	if (!inFS.is_open()) {
		cout << "Cannot open file data-1-input.txt" << endl;
	}

	string line;

	while (getline(inFS, line)) {

		for (unsigned int i = 0; i < line.size(); ++i) {
			if (isdigit(line[i])) {
				numbers.push_back(line[i]);
			}
		}

		firstElement = numbers.front();
		secondElement = numbers.back();

		firstAndSecondElement = firstAndSecondElement + firstElement + secondElement;

		inputNumber = stoi(firstAndSecondElement);

		total += inputNumber;

		numbers.clear();
		firstAndSecondElement = "";
	}

	inFS.close();

	cout << total;

	return 0;
}