/**
* /author Oleg Rubenchik
*/
#include <iostream>
#include <string>
using namespace std;
int power(int, int); //	A function that raises a number to a certain degree
int convertToDecimal(int A[], int);
bool isBitSet(int num, int pos);
int main() {
	char c;
	const int MAX = 10; // Maximum size of bits
	int answer[MAX] = {0}; // Answer in Binary form
	int size; // Actual size of bits
	string name;
	int MAX_NUM;
	cout << "Enter number of bits (<=10): ";
	cin >> size;
	cout << "Thank you! Now tell me your name: ";
	while (c = cin.get(), c != '\n');
	getline(cin, name);
	cout << name << ", think of a number between 1 and " << power(2,size) - 1 << " and I will guess it...\n\n";
	for (int pos = 0; pos < size; pos++) {
		int countline = 0;
		for (int i = 1; i <= (power(2, size) - 1); i++) {
			if (isBitSet(i, pos)) {
				cout << i << ' ';
				countline += 1;
			}
			if (countline == 10) {
				countline = 0;
				cout << '\n';
			}
		}
		cout << '\n';
		char reply;
		cout << "Is your number in the above table (y/n): ";
		cin >> reply;
		if (reply == 'y') answer[pos] = 1;
	}
	int secretNumber = convertToDecimal(answer, size);
	cout << name << ", you have selected number " << secretNumber << ".";
	return 0;
}
int power(int num,int power) {
	int poweredNum = 1;
	for (int i = 0; i < power; i++) {
		poweredNum = poweredNum * num;
	}
	return poweredNum;
}
int convertToDecimal(int A[], int size) {
	int num = 0;
	for (int i = 0; i < size; ++i) {
		if (A[i] == 1) {
			num += power(2, i);
		}
	}
	return num;
}
bool isBitSet(int number, int pos) {
	if (pos == 0) {
		return number % 2 == 1; // If pos is 0, just check if number is odd
	}

	int divisor = power(2, pos);
	return (number / divisor) % 2 == 1;
}
