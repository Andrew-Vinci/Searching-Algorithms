
/*

Author: Andrew Vinci

Class: CSI-281 - Data Structures and Algorithms

Assignment: PA 4

Date Assigned: 03/01/2022

Due Date: 03/10/2022 @ 11:30 am

Description:
This file holds the logic for the implentation of sequential search 
and binary search, along with accompanying functions needs to perform 
the various tasks of the project.

Certification of Authenticity:
I certify that this is entirely my own work, except where I have given
fully-documented references to the work of others. I understand the definition and
consequences of plagiarism and acknowledge that the assessor of this assignment
may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of academic staff;
and/or
- Communicate a copy of this assignment to a plagiarism checking service (which may
then retain a copy of this assignment on its database for the purpose of future
plagiarism checking)

*/



#include <iostream>
#include <iomanip>
#include <fstream>
#include <time.h>
#include <cstdlib>
#include <stdio.h>
#include "Header.h"

using namespace std;

/* Cite: This is Another Students Timer System that I'm using for this project.*/

/*      Pre:  None
 *     Post:  The private members are initialized
 *  Purpose:  Default constructor for the TimerSystem
******************************************************************************/
TimerSystem::TimerSystem()
{
	start.QuadPart = 0;
	finish.QuadPart = 0;

	//Sets the clock frequency for the system we are running on
	QueryPerformanceFrequency(&freq);
}


/*      Pre:  The stopwatch must be initialized and started
 *     Post:  The elapse time is returned to the caller
 *  Purpose:  Gets time in seconds since the stopwatch has started
 ******************************************************************************/
double TimerSystem::getTime()
{
	QueryPerformanceCounter(&finish);  //get end cpu cycles

   // return the amount of time elapsed
	return static_cast<double>((finish.QuadPart - start.QuadPart) / static_cast<double>(freq.QuadPart));
}


/*      Pre:  The stopwatch must be initialized
 *     Post:  The start private member is reset
 *  Purpose:  To start the stopwatch
 ******************************************************************************/
void TimerSystem::startClock()
{
	//get the top of the frames CPU count
	QueryPerformanceCounter(&start);
}



/*
Pre: Takes in an array of any type, a search key, and a lower and upper bound.

Post: Performs binary search on the array.

Purpose: This functions purpose is to take an array of any type and
search through the list to find the search key.
*/


template <typename T>
bool binarySearch(T list[], int searchKey, int lowerBound, int upperBound) {

	bool found = false;
	int mid;

	if (lowerBound <= upperBound) {

		mid = (lowerBound + upperBound) / 2;

		if (list[mid] == searchKey) {
			found = true;
		}
		else if (list[mid] > searchKey) {
			return binarySearch(list, searchKey, lowerBound, mid - 1);
		}
		else {
			return binarySearch(list, searchKey, mid + 1, upperBound);
		}
	}

	return found;

}

/*
Pre: Takes in an array of any type, a search key, and a size of a list.

Post: Performs sequential search on the array.

Purpose: This functions purpose is to take an array of any type and
search through the list to find the search key.
*/


template <typename T>
bool sequentialSearch(T list[], int searchKey, int size) {

	int i;
	bool found = false;

	for (i = 0; i < size; i++) {
		if (list[i] == searchKey) {
			found = true;
		}
		else if (list[i] > searchKey) {
		}
	}

	return found;

}




/*
Pre: Takes in an array of any type and an int.

Post: Performs quick sort on the array and sorts them.

Purpose: This functions purpose is to take an array of any type and
sort it using quick sort in ascending/alphabetical order.
*/

template <typename T>
void quickSort(T list[], int lowerBound, int upperBound) {

	int i, j;

	T pivot;

	T temp;

	i = lowerBound;
	j = upperBound;

	pivot = list[(lowerBound + upperBound) / 2];


	while (i <= j) {

		while (list[i] < pivot) {
			i += 1;
		}

		while (list[j] > pivot) {
			j -= 1;
		}

		if (i <= j) {
			temp = list[i];
			list[i] = list[j];
			list[j] = temp;
			i += 1;
			j -= 1;
		}
	}

	if (lowerBound < j) {
		quickSort(list, lowerBound, j);
	}

	if (i < upperBound) {
		quickSort(list, i, upperBound);
	}
}





/*
Pre: None.

Post: Populates one million random numbers for test.

Purpose: This function populates 1,000,000 random numbers for test.
*/

void TestingAlgorithms::populateRanNum() {

	srand((long int)time(NULL));

	long int randomNumber;
	const long int UPPER_BOUND = 10000;
	const long int ONE_MILLION = 999999;

	ofstream fout;

	fout.open("oneMillionNumbers.txt");

	for (int i = 0; i <= ONE_MILLION; i++) {
		randomNumber = rand() % UPPER_BOUND;
		fout << randomNumber << endl;
	}

	fout.close();

}





/*
Pre: none.

Post: Resets the ascending arrays list for all numbers.

Purpose: The purpose of this function is to reset the ascending arays list
for all numbers.
*/


void TestingAlgorithms::resetAscending() {


	ifstream fin;
	ifstream fin2;
	ifstream fin3;

	fstream fout;
	fstream fout2;
	fstream fout3;

	long int i, j, k, tmp;
	const long int NUM = 99;
	const long int NUM2 = 99999;
	const long int NUM3 = 999999;

	const long int ONE_HUNDRED = 100;
	const long int ONE_HUNDRED_THOUSAND = 100000;
	const long int ONE_MILLION = 1000000;

	const int LOWER_BOUND = 0;

	unsigned int* hundredArray = new unsigned int[ONE_HUNDRED];
	unsigned int* hundredThousandArray = new unsigned int[ONE_HUNDRED_THOUSAND];
	unsigned int* oneMillionArray = new unsigned int[ONE_MILLION];

	cout << "Reseting the Ascending Arrays. Please wait.\n";

	// Populate 100 Ascending Numbers

	fin.open("oneMillionNumbers.txt");
	fout.open("100_Ascending.txt");

	for (i = 0; i <= NUM; i++) {
		fin >> tmp;
		//fout << tmp << endl;
		hundredArray[i] = tmp;
	}

	quickSort(hundredArray, LOWER_BOUND, NUM);

	fout.clear();
	fout.seekg(0);

	for (int j = 0; j <= NUM; j++) {
		fout << hundredArray[j] << endl;
	}

	fin.close();
	fout.close();

	delete[] hundredArray;

	// Populate 100,000 Ascending Numbers


	fin2.open("oneMillionNumbers.txt");
	fout2.open("100,000_Ascending.txt");

	for (i = 0; i <= NUM2; i++) {
		fin2 >> tmp;
		//fout << tmp << endl;
		hundredThousandArray[i] = tmp;
	}

	cout << "Sorting 100,000 Array.\n";

	quickSort(hundredThousandArray, LOWER_BOUND, NUM2);

	fout2.clear();
	fout2.seekg(0);

	for (int j = 0; j <= NUM2; j++) {
		fout2 << hundredThousandArray[j] << endl;
	}

	fin2.close();
	fout2.close();

	delete[] hundredThousandArray;

	cout << "100,000 Array Sorted.\n";

	// Populate 1,000,000 Ascending Numbers


	fin3.open("oneMillionNumbers.txt");
	fout3.open("1,000,000_Ascending.txt");

	for (i = 0; i <= NUM3; i++) {
		fin3 >> tmp;
		//fout << tmp << endl;
		oneMillionArray[i] = tmp;
	}

	cout << "Sorting 1,000,000 Array.\n";

	quickSort(oneMillionArray, LOWER_BOUND, NUM3);

	fout3.clear();
	fout3.seekg(0);

	for (k = 0; k <= NUM3; k++) {
		fout3 << oneMillionArray[k] << endl;
	}

	fin3.close();
	fout3.close();

	delete[] oneMillionArray;

	cout << "1,000,000 Array Sorted.\n";

}

/*
Pre: None.

Post: give user option to perform tests with sequential search or binary search.

Purpose: This functions purpose is to provide a menu for the user to perform tests.
*/

void TestingAlgorithms::testMenu() {

	int userInput;

	cout << "Please Select an Algorithm to Test.\n";
	cout << "[1] - Sequential Search.\n";
	cout << "[2] - Binary Search.\n";
	cin >> userInput;

	switch (userInput) {
	case 1:
		testMenuSequential();
		break;
	case 2:
		testMenuBinary();
		break;
	}

}


/*
Pre: None.

Post: give user option to perform tests with sequential search.

Purpose: This functions purpose is to provide a menu for the user to perform tests
using sequential search.

Cite: This Code Uses Another Students Timer System that I'm Using for This Project.

*/



void TestingAlgorithms::testMenuSequential() {



	const int MAX = 100, RANGE = 1001;

	TimerSystem timer;
	int numbers[MAX];

	cout.setf(ios::fixed | ios::showpoint);
	cout.precision(16);

	srand(unsigned(time(NULL)));



	int userInput, i, tmp;

	bool value = false;

	fstream fin;

	const long int NUM = 99;
	const long int NUM2 = 99999;
	const long int NUM3 = 999999;

	const long int ONE_HUNDRED = 100;
	const long int ONE_HUNDRED_THOUSAND = 100000;
	const long int ONE_MILLION = 1000000;

	const int SEARCH_KEY_LOW = 0;

	const int SEARCH_KEY_LOW_100 = 158;
	const long int SEARCH_KEY_MID_100 = 4018;
	const long int SEARCH_KEY_HIGH_100 = 9854;

	const long int SEARCH_KEY_MID_100_000 = 4517;
	const long int SEARCH_KEY_MID_1_000_000 = 4537;

	const long int SEARCH_KEY_HIGH = 9999;


	const int LOWER_BOUND = 0;

	long int* hundredArray = new long int[ONE_HUNDRED];
	long int* hundredThousandArray = new long int[ONE_HUNDRED_THOUSAND];
	long int* oneMillionArray = new long int[ONE_MILLION];


	cout << "Enter a Number Corresponding With a Sequential Search Test.\n";
	cout << "[1] - 100 Search Key Low.\n";
	cout << "[2] - 100 Search Key Mid.\n";
	cout << "[3] - 100 Search Key High.\n";
	cout << "[4] - 100,000 Search Key Low.\n";
	cout << "[5] - 100,000 Search Key Mid.\n";
	cout << "[6] - 100,000 Search Key High.\n";
	cout << "[7] - 1,000,000 Search Key Low.\n";
	cout << "[8] - 1,000,000 Search Key Mid.\n";
	cout << "[9] - 1,000,000 Search Key High.\n";
	cin >> userInput;

	switch (userInput) {
	case 1:

		fin.open("100_Ascending.txt");

		for (i = 0; i <= NUM; i++) {
			fin >> tmp;
			hundredArray[i] = tmp;
		}

		quickSort(hundredArray, LOWER_BOUND, NUM);

		timer.startClock();

		value = sequentialSearch(hundredArray, SEARCH_KEY_LOW_100, ONE_HUNDRED);

		if (value) {
			cout << "\n";
			cout << "The Amount of time a List of 100 Took With Low Search Key: " << timer.getTime() << endl;
		}
		else {
			cout << "Value Not Found.\n";
		}

		fin.close();
		delete[] hundredArray;

		break;
	case 2:

		fin.open("100_Ascending.txt");

		for (i = 0; i <= NUM; i++) {
			fin >> tmp;
			hundredArray[i] = tmp;
		}

		quickSort(hundredArray, LOWER_BOUND, NUM);

		timer.startClock();

		value = sequentialSearch(hundredArray, SEARCH_KEY_MID_100, ONE_HUNDRED);

		if (value) {
			cout << "\n";
			cout << "The Amount of time a List of 100 Took With Mid Search Key: " << timer.getTime() << endl;
		}
		else {
			cout << "Value Not Found.\n";
		}

		fin.close();
		delete[] hundredArray;

		break;
	case 3:


		fin.open("100_Ascending.txt");

		for (i = 0; i <= NUM; i++) {
			fin >> tmp;
			hundredArray[i] = tmp;
		}

		quickSort(hundredArray, LOWER_BOUND, NUM);

		timer.startClock();

		value = sequentialSearch(hundredArray, SEARCH_KEY_HIGH_100, ONE_HUNDRED);

		if (value) {
			cout << "\n";
			cout << "The Amount of time a List of 100 Took With High Search Key: " << timer.getTime() << endl;
		}
		else {
			cout << "Value Not Found.\n";
		}

		fin.close();
		delete[] hundredArray;

		break;
	case 4:


		fin.open("100,000_Ascending.txt");

		for (i = 0; i <= NUM2; i++) {
			fin >> tmp;
			hundredThousandArray[i] = tmp;
		}

		quickSort(hundredThousandArray, LOWER_BOUND, NUM2);

		timer.startClock();

		value = sequentialSearch(hundredThousandArray, SEARCH_KEY_LOW, ONE_HUNDRED_THOUSAND);

		if (value) {
			cout << "\n";
			cout << "The Amount of time a List of 100,000 Took With Low Search Key: " << timer.getTime() << endl;
		}
		else {
			cout << "Value Not Found.\n";
		}

		fin.close();
		delete[] hundredThousandArray;

		break;
	case 5:

		fin.open("100,000_Ascending.txt");

		for (i = 0; i <= NUM2; i++) {
			fin >> tmp;
			hundredThousandArray[i] = tmp;
		}

		quickSort(hundredThousandArray, LOWER_BOUND, NUM2);

		timer.startClock();

		value = sequentialSearch(hundredThousandArray, SEARCH_KEY_MID_100_000, ONE_HUNDRED_THOUSAND);

		if (value) {
			cout << "\n";
			cout << "The Amount of time a List of 100,000 Took With Mid Search Key: " << timer.getTime() << endl;
		}
		else {
			cout << "Value Not Found.\n";
		}

		fin.close();
		delete[] hundredThousandArray;

		break;
	case 6:


		fin.open("100,000_Ascending.txt");

		for (i = 0; i <= NUM2; i++) {
			fin >> tmp;
			hundredThousandArray[i] = tmp;
		}

		quickSort(hundredThousandArray, LOWER_BOUND, NUM2);

		timer.startClock();

		value = sequentialSearch(hundredThousandArray, SEARCH_KEY_HIGH, ONE_HUNDRED_THOUSAND);

		if (value) {
			cout << "\n";
			cout << "The Amount of time a List of 100,000 Took With High Search Key: " << timer.getTime() << endl;
		}
		else {
			cout << "Value Not Found.\n";
		}

		fin.close();
		delete[] hundredThousandArray;

		break;
	case 7:

		fin.open("1,000,000_Ascending.txt");

		for (i = 0; i <= NUM3; i++) {
			fin >> tmp;
			oneMillionArray[i] = tmp;
		}

		quickSort(oneMillionArray, LOWER_BOUND, NUM3);

		timer.startClock();

		value = sequentialSearch(oneMillionArray, SEARCH_KEY_LOW, ONE_MILLION);

		if (value) {
			cout << "\n";
			cout << "The Amount of time a List of 1,000,000 Took With Low Search Key: " << timer.getTime() << endl;
		}
		else {
			cout << "Value Not Found.\n";
		}

		fin.close();
		delete[] oneMillionArray;

		break;
	case 8:

		fin.open("1,000,000_Ascending.txt");

		for (i = 0; i <= NUM3; i++) {
			fin >> tmp;
			oneMillionArray[i] = tmp;
		}

		quickSort(oneMillionArray, LOWER_BOUND, NUM3);

		timer.startClock();

		value = sequentialSearch(oneMillionArray, SEARCH_KEY_MID_1_000_000, ONE_MILLION);

		if (value) {
			cout << "\n";
			cout << "The Amount of time a List of 1,000,000 Took With Mid Search Key: " << timer.getTime() << endl;
		}
		else {
			cout << "Value Not Found.\n";
		}

		fin.close();
		delete[] oneMillionArray;

		break;
	case 9:

		fin.open("1,000,000_Ascending.txt");

		for (i = 0; i <= NUM3; i++) {
			fin >> tmp;
			oneMillionArray[i] = tmp;
		}

		quickSort(oneMillionArray, LOWER_BOUND, NUM3);

		timer.startClock();

		value = sequentialSearch(oneMillionArray, SEARCH_KEY_HIGH, ONE_MILLION);

		if (value) {
			cout << "\n";
			cout << "The Amount of time a List of 1,000,000 Took With High Search Key: " << timer.getTime() << endl;
		}
		else {
			cout << "Value Not Found.\n";
		}

		fin.close();
		delete[] oneMillionArray;

		break;
	}

}

/*
Pre: None.

Post: give user option to perform tests with binary search.

Purpose: This functions purpose is to provide a menu for the user to perform tests
using binary search.

Cite: This Code Uses Another Students Timer System that I'm Using for This Project.

*/


void TestingAlgorithms::testMenuBinary() {


	const int MAX = 100, RANGE = 1001;

	TimerSystem timer;
	int numbers[MAX];

	cout.setf(ios::fixed | ios::showpoint);
	cout.precision(16);

	srand(unsigned(time(NULL)));



	int userInput, i, tmp;

	bool value = false;

	fstream fin;

	const long int NUM = 99;
	const long int NUM2 = 99999;
	const long int NUM3 = 999999;

	const long int ONE_HUNDRED = 100;
	const long int ONE_HUNDRED_THOUSAND = 100000;
	const long int ONE_MILLION = 1000000;

	const int SEARCH_KEY_LOW = 0;

	const int SEARCH_KEY_LOW_100 = 158;
	const long int SEARCH_KEY_MID_100 = 4018;
	const long int SEARCH_KEY_HIGH_100 = 9854;

	const long int SEARCH_KEY_MID_100_000 = 4517;
	const long int SEARCH_KEY_MID_1_000_000 = 4537;

	const long int SEARCH_KEY_HIGH = 9999;


	const int LOWER_BOUND = 0;

	long int* hundredArray = new long int[ONE_HUNDRED];
	long int* hundredThousandArray = new long int[ONE_HUNDRED_THOUSAND];
	long int* oneMillionArray = new long int[ONE_MILLION];


	cout << "Enter a Number Corresponding With a Binary Search Test.\n";
	cout << "[1] - 100 Search Key Low.\n";
	cout << "[2] - 100 Search Key Mid.\n";
	cout << "[3] - 100 Search Key High.\n";
	cout << "[4] - 100,000 Search Key Low.\n";
	cout << "[5] - 100,000 Search Key Mid.\n";
	cout << "[6] - 100,000 Search Key High.\n";
	cout << "[7] - 1,000,000 Search Key Low.\n";
	cout << "[8] - 1,000,000 Search Key Mid.\n";
	cout << "[9] - 1,000,000 Search Key High.\n";
	cin >> userInput;

	switch (userInput) {
	case 1:

		fin.open("100_Ascending.txt");

		for (i = 0; i <= NUM; i++) {
			fin >> tmp;
			hundredArray[i] = tmp;
		}

		quickSort(hundredArray, LOWER_BOUND, NUM);

		timer.startClock();

		value = binarySearch(hundredArray, SEARCH_KEY_LOW_100, LOWER_BOUND, NUM);

		if (value) {
			cout << "\n";
			cout << "The Amount of time a List of 100 Took With Low Search Key: " << timer.getTime() << endl;
		}
		else {
			cout << "Value Not Found.\n";
		}

		fin.close();
		delete[] hundredArray;

		break;
	case 2:

		fin.open("100_Ascending.txt");

		for (i = 0; i <= NUM; i++) {
			fin >> tmp;
			hundredArray[i] = tmp;
		}

		quickSort(hundredArray, LOWER_BOUND, NUM);

		timer.startClock();

		value = binarySearch(hundredArray, SEARCH_KEY_MID_100, LOWER_BOUND, NUM);

		if (value) {
			cout << "\n";
			cout << "The Amount of time a List of 100 Took With Mid Search Key: " << timer.getTime() << endl;
		}
		else {
			cout << "Value Not Found.\n";
		}

		fin.close();
		delete[] hundredArray;

		break;
	case 3:


		fin.open("100_Ascending.txt");

		for (i = 0; i <= NUM; i++) {
			fin >> tmp;
			hundredArray[i] = tmp;
		}

		quickSort(hundredArray, LOWER_BOUND, NUM);

		timer.startClock();

		value = binarySearch(hundredArray, SEARCH_KEY_HIGH_100, LOWER_BOUND, NUM);

		if (value) {
			cout << "\n";
			cout << "The Amount of time a List of 100 Took With High Search Key: " << timer.getTime() << endl;
		}
		else {
			cout << "Value Not Found.\n";
		}

		fin.close();
		delete[] hundredArray;

		break;
	case 4:


		fin.open("100,000_Ascending.txt");

		for (i = 0; i <= NUM2; i++) {
			fin >> tmp;
			hundredThousandArray[i] = tmp;
		}

		quickSort(hundredThousandArray, LOWER_BOUND, NUM2);

		timer.startClock();

		value = binarySearch(hundredThousandArray, SEARCH_KEY_LOW, LOWER_BOUND, NUM2);

		if (value) {
			cout << "\n";
			cout << "The Amount of time a List of 100,000 Took With Low Search Key: " << timer.getTime() << endl;
		}
		else {
			cout << "Value Not Found.\n";
		}

		fin.close();
		delete[] hundredThousandArray;

		break;
	case 5:

		fin.open("100,000_Ascending.txt");

		for (i = 0; i <= NUM2; i++) {
			fin >> tmp;
			hundredThousandArray[i] = tmp;
		}

		quickSort(hundredThousandArray, LOWER_BOUND, NUM2);

		timer.startClock();

		value = binarySearch(hundredThousandArray, SEARCH_KEY_MID_100_000, LOWER_BOUND, NUM2);

		if (value) {
			cout << "\n";
			cout << "The Amount of time a List of 100,000 Took With Mid Search Key: " << timer.getTime() << endl;
		}
		else {
			cout << "Value Not Found.\n";
		}

		fin.close();
		delete[] hundredThousandArray;

		break;
	case 6:


		fin.open("100,000_Ascending.txt");

		for (i = 0; i <= NUM2; i++) {
			fin >> tmp;
			hundredThousandArray[i] = tmp;
		}

		quickSort(hundredThousandArray, LOWER_BOUND, NUM2);

		timer.startClock();

		value = binarySearch(hundredThousandArray, SEARCH_KEY_HIGH, LOWER_BOUND, NUM2);

		if (value) {
			cout << "\n";
			cout << "The Amount of time a List of 100,000 Took With High Search Key: " << timer.getTime() << endl;
		}
		else {
			cout << "Value Not Found.\n";
		}

		fin.close();
		delete[] hundredThousandArray;

		break;
	case 7:

		fin.open("1,000,000_Ascending.txt");

		for (i = 0; i <= NUM3; i++) {
			fin >> tmp;
			oneMillionArray[i] = tmp;
		}

		quickSort(oneMillionArray, LOWER_BOUND, NUM3);

		timer.startClock();

		value = binarySearch(oneMillionArray, SEARCH_KEY_LOW, LOWER_BOUND, NUM3);

		if (value) {
			cout << "\n";
			cout << "The Amount of time a List of 1,000,000 Took With Low Search Key: " << timer.getTime() << endl;
		}
		else {
			cout << "Value Not Found.\n";
		}

		fin.close();
		delete[] oneMillionArray;

		break;
	case 8:

		fin.open("1,000,000_Ascending.txt");

		for (i = 0; i <= NUM3; i++) {
			fin >> tmp;
			oneMillionArray[i] = tmp;
		}

		quickSort(oneMillionArray, LOWER_BOUND, NUM3);

		timer.startClock();

		value = binarySearch(oneMillionArray, SEARCH_KEY_MID_1_000_000, LOWER_BOUND, NUM3);

		if (value) {
			cout << "\n";
			cout << "The Amount of time a List of 1,000,000 Took With Mid Search Key: " << timer.getTime() << endl;
		}
		else {
			cout << "Value Not Found.\n";
		}

		fin.close();
		delete[] oneMillionArray;

		break;
	case 9:

		fin.open("1,000,000_Ascending.txt");

		for (i = 0; i <= NUM3; i++) {
			fin >> tmp;
			oneMillionArray[i] = tmp;
		}

		quickSort(oneMillionArray, LOWER_BOUND, NUM3);

		timer.startClock();

		value = binarySearch(oneMillionArray, SEARCH_KEY_HIGH, LOWER_BOUND, NUM3);

		if (value) {
			cout << "\n";
			cout << "The Amount of time a List of 1,000,000 Took With High Search Key: " << timer.getTime() << endl;
		}
		else {
			cout << "Value Not Found.\n";
		}

		fin.close();
		delete[] oneMillionArray;

		break;
	}

}