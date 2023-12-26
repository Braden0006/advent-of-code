#include <iostream> 
#include <string>
#include <vector>

using namespace std;

int main() {
	string inputValue;
	vector<char> numbers;

	char firstElement;
	char secondElement;

	string firstAndSecondElement;

	int inputNumber;

	int total = 0;

	cout << "Enter in your values: ";

	cin >> inputValue;

	for (unsigned int i = 0; i < inputValue.size(); ++i) {
		if (isdigit(inputValue[i])) {
			numbers.push_back(inputValue[i]);
		}
	}

	firstElement = numbers.front();
	secondElement = numbers.back();

	firstAndSecondElement = firstAndSecondElement + firstElement + secondElement;

	inputNumber = stoi(firstAndSecondElement);

	total += inputNumber;

	cout << inputNumber;

	return 0;
}