/**
* /author Oleg Rubenchik
*/
#include <iostream>
using namespace std;
int power(int, int); //	A function that raises a number to a certain degree
void reverseArray(int A[],int revA[], int);
void displayArray(int A[], int);
int convertToDecimal(int A[], int);
bool isBitSet(int num, int pos);
int main() {
	const int MAX = 10; // Maximum size of bits
	int answer[MAX] = { 0,0,1,1 }; // Answer in Binary form
	int size; // Actual size of bits
	int MAX_NUM;
	int revA[MAX];
	cout << isBitSet(4,6);
	return 0;
}
int power(int num,int power) {
	int poweredNum = 1;
	for (int i = 0; i < power; i++) {
		poweredNum = poweredNum * num;
	}
	return poweredNum;
}
void reverseArray(int A[],int revA[], int size) {
	for (int i = 0; i < size; i++)
		revA[i] = A[size - 1 - i];
}
void displayArray(int A[], int size) {
	for (int i = 0; i < size; i++)
		cout << A[i] << ' ';
	cout << '\n';
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
bool isBitSet(int num, int pos) {
	int currentPow = power(2, pos);
	while (num >= currentPow) {
		num -= currentPow; // Keep subtracting the power of 2
		if (num == 0) {
			return true; // If we hit exactly zero, the bit was set
		}
		// Find the next highest power of 2 less than the current number
		while (currentPow > num) {
			currentPow /= 2;
		}
	}
	return false;
}
