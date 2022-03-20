

/*

Author: Andrew Vinci

Class: CSI-281 - Data Structures and Algorithms

Assignment: PA 4

Date Assigned: 03/01/2022

Due Date: 03/10/2022 @ 11:30 am

Description:
This file holds the header file information for the project.

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
#include <string>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

using namespace std;

/*Cite: This is Another Students Timer System that I'm Using for This Project.*/

#ifndef TIMER_SYSTEM_H
#define TIMER_SYSTEM_H

class TimerSystem
{
private:
	LARGE_INTEGER start, finish, freq;  //For frequency and high speed timers

public:
	TimerSystem();

	double getTime();  //gets current time since top of frame
	void   startClock();  //Starts the frame counter
};

#endif

template <typename T>
bool binarySearch(T list[], int searchKey, int lowerBound, int upperBound);

template <typename T>
bool sequentialSearch(T list[], int searchKey, int size);


template <typename T>
void quickSort(T list[], int lowerBound, int upperBound);

template <typename T>
void quickSortDescending(T list[], int lowerBound, int upperBound);


class TestingAlgorithms {
private:

public:

	void populateRanNum();

	void testMenu();
	void testMenuBinary();
	void testMenuSequential();

	void resetAscending();

};
