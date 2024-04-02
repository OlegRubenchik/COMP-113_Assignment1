/** \file comp113_Assignment1_solution.cpp
* \brief The program will read the user’s name and then ask him/her to think of a number (secret number) within
* some limits. Then the program will display a number of tables asking the user if his/her secret number is
* displayed. Finally the program will guess the user’s number.
* \author Oleg Rubenchik
* \date 02/04/2024
*/
#include <iostream>

using namespace std;
//All descriptions of all the functions are written below
int power(int, int); 
int convertToDecimal(int A[], int);
bool isBitSet(int num, int pos);

/**
* Function <code>main</code> Asks the user to think of a number in a certain limits and guesses it using it's binary form
* <BR>
* @return Returns 0
*/
int main() {
	// Variables
	char c = NULL;
	const int MAX = 10; // Maximum size of bits
	int answer[MAX] = {0}; // Answer in Binary form
	int size; // Actual size of bits
	char name[256];
	int MAX_NUM; 
	//----------------------
	//Beginning
	cout << "Enter number of bits (<=10): ";
	cin >> size;
	MAX_NUM = power(2, size) - 1; // Biggest number we can have according to given size
	cout << "Thank you! Now tell me your name: ";
	cin.ignore(); // This is to clear out any leftover newline characters in the input buffer
	int i = 0; 
	while (c = cin.get(), c != '\n') // To read a c-string
		name[i++] = c;
	name[i] = '\0'; // To close the c-string
	cout << name << ", think of a number between 1 and " << power(2,size) - 1 << " and I will guess it...\n\n";
	//---------------------
	//Main Algorithm
	for (int pos = 0; pos < size; pos++) {
		int countline = 0; // How many numbers we printed
		for (int i = 1; i <= MAX_NUM; i++) {
			if (isBitSet(i, pos)) { // Is bit at certain position is set to 1?
				cout << i << ' ';
				countline += 1; // We just printed a number
			}
			if (countline == 10) { // If we printed 10 numbers, get to the new line
				countline = 0;
				cout << '\n';
			}
		}
		cout << '\n';
		char reply;
		cout << "Is your number in the above table (y/n): ";
		cin >> reply;
		if (reply == 'y') answer[pos] = 1; /* If secret number is present in printed table, then we know that that number has bit set to 1 at certain posion
											If not, we know it is set to 0 */								
	}
	int secretNumber = convertToDecimal(answer, size); // Since we got the binary form of our secret number,we can convert it to decimal
	cout << name << ", you have selected number " << secretNumber << ".";
	return 0;
}

//FUNCTIONS

/**
* Function <code>power</code> that raises a number to a certain degree
* <BR>
* @param num The number that we are rising to a certain degree
* @param degree Degree itself
* @return Returns <code>poweredNum</code>, number raised to a given degree
*/
int power(int num,int degree) { 
	int poweredNum = 1;
	for (int i = 0; i < degree; i++) {
		poweredNum = poweredNum * num;
	}
	return poweredNum;
}

/**
* Function <code>convertToDecimal</code> converts binary to decimal
* @param A[] The array that contains all the bits
* @param size Size of that array
* @return Returns <code>DecimalNum</code>, decimal number 
*/
int convertToDecimal(int A[], int size) {
	int DecimalNum = 0;
	for (int i = 0; i < size;i++) {
		if (A[i] == 1) {
			DecimalNum += power(2, i);
		}
	}
	return DecimalNum;
}

/**
* Function <code>isBitSet</code> receives a decimal number and determines if a specific bit in its binary representation is set to 1.
* @param number Decimal number
* @param pos Position of the bit
* @return Returns <code>true</code> if bit is set to 1
* <code>false</code> otherwise.
*/
bool isBitSet(int number, int pos) {
	if (pos == 0) {
		return number % 2 == 1; // If pos is 0, just check if number is odd
	}

	int divisor = power(2, pos);
	return (number / divisor) % 2 == 1;
}
