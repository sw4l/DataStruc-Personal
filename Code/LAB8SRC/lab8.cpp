//============================================================================
// Name        : lab8.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
using namespace std;
#include "ArrayStack.h"
#include "SuperStack.h"
int findMin(int array[], int length);
string freqOfOccurance(string myString, int length);

int main() {
	int myArray[3] = { 3, 2, 1 };
	int myArray2[5] = { 8, 10, 1, 5, 7 };
	int myArray3[5] = { 1, 5, 7, 8, 10 };
	int myArray4[2] = { 5, 1 };
	cout << "find min 1 = " << findMin(myArray, 3) << endl;
	cout << "find min 2 = " << findMin(myArray2, 5) << endl;
	cout << "find min 3 = " << findMin(myArray3, 5) << endl;
	cout << "find min 4 = " << findMin(myArray4, 2) << endl;
	string s = "1+4+5=10";
	freqOfOccurance(s, s.size());
}
//our find minimum function of run time O(LOG(N))
int findMin(int array[], int length) {
	//binary search
	//were looking for when the left is greater, if at beginning go other way, if right is greater we where we want to be
	int left = 0;
	int right = length - 1;
	int middle = left + ((right - left) / 2);
	while (left <= right) {
		if (middle == 0 && array[middle + 1] > array[middle]) {
			//cout << "left boundry" << endl;
			return array[middle];
		} else if (middle == length - 1 && array[middle - 1] > array[middle]) {
			//cout << "Right boundry" << endl;
			return array[middle];
		} else if (array[middle - 1] > array[middle]
				&& array[middle + 1] > array[middle]) {
			return array[middle];
		} else if (array[middle] > array[middle - 1]) {
			right = (middle - 1);
		} else {
			left = (middle + 1);
		}

		middle = left + ((right - left) / 2);
	}
	return 69;
}
//we go into this with an array and a length and use loops to count each occurnce of each char in a stirng
//we go into a double loop, out put the letter, then out put result of the second loop as the number of occurence
string freqOfOccurance(string myString, int length) {
	int count = 0, temp = 0;
	bool flag = true;
	for (int i = 0; i < length; i++) {
		count = 0;
		for (int j = 0; j < length; j++) {
			if (myString[j] == myString[i]) {
				count++;
			}
		}
		//cout << myString[i] << " appear " << count << " times" << endl;
		for (int k = 0; k < i; k++) {
			if (myString[i] == myString[k]) {
				//cout << "present do nothing" << endl;
				flag = false;
				break;
			}
		}
		if (flag == true) {
			cout << myString[i] << " appear " << count << " times" << endl;
		}
		//resetting flah each loop
		flag = true;
	}
	return myString;
}
