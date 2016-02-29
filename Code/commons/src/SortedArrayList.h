/*
 * SortedArrayList.h
 *
 *  Created on: Feb 26, 2016
 *      Author: Dakota
 */

#ifndef SORTEDARRAYLIST_H_
#define SORTEDARRAYLIST_H_

#include <iostream>
using namespace std;
template<class T>
class SortedArrayList {
	int maxLength;
	T** elements;
	int length;
	//we need private memeber functions to pop the list into a linear order after a removal
	//were gonna take in a element and look for it or a look for a position that it can go
	int binarySearch(T* element);
	//when we call this private memeber function it will pop back the array to have no holes in the list
	void popBack(int delPos);
	void resize();
	void sort();
public:
	SortedArrayList();
	virtual ~SortedArrayList();
	/**
	 * Gets the current number of elements in the list.
	 * @return The integer number of elements in the list.
	 */
	int size();

	/**
	 * Inserts the specified element into the sorted list.
	 * @param[in] element The element that has to be inserted into the list.
	 * @post If the element is not NULL then it is inserted into the list at the proper position,
	 * so that the list remains sorted in ascending order.
	 * @return Position of the inserted element, or -1 if the element is NULL.
	 */
	int add(T* element);

	/**
	 * Removes the element from the list.
	 * @param[in] element The element that has to be removed from the list.
	 * @post If the element is not NULL and it is on the list, then it is removed from the list.
	 * @return TRUE if the element was successfully removed from the list, FALSE if the element is NULL
	 * or it does not appear on the list.
	 */
	bool remove(T* element);

	/**
	 * Removes the element at the specified position.
	 * @param[in] position The position of the element that has to be removed from the list.
	 * @post If position is the number between 0 and the current length - 1 of the list inclusively
	 * then removal is successful i. e. the element is removed at the desired position in the list.
	 * Elements(if any) that have position numbers smaller than position remain intact,
	 * whereas all the remaining elements (if any) of the list are shifted to the left by one position.
	 * @return TRUE if the element was successfully removed from the list, FALSE otherwise.
	 */
	bool remove(int position);

	/**
	 * Gets the position of a specified element.
	 * @param[in] element The element that has to be positioned on the list.
	 * @return Positive number denoting the position of the specified element, or number < 0
	 * when element is NULL or it does not appear on the list.
	 * */
	int getPosition(T* element);

	/**
	 * Gets the element at a specified position.
	 * @param[in] position The position of the element that has to be retrieved from the list.
	 * @return NULL if position IS NOT between 0 and the current length - 1 of the list inclusively.
	 * Otherwise, it returns the requested element.
	 * */
	T* get(int position);

	void display();

};

template<class T>
SortedArrayList<T>::SortedArrayList() {
	maxLength = 10;
	elements = new T*[maxLength];
	for (int var = 0; var < maxLength; ++var) {
		elements[var] = NULL;
	}
	length = 0;
}
template<class T>
SortedArrayList<T>::~SortedArrayList() {
	delete[] elements;
}
template<class T>
void SortedArrayList<T>::resize() {
	maxLength = 2 * maxLength;
	T** oldArray = elements;
	elements = new T*[maxLength];
	for (int var = 0; var < length; ++var) {
		elements[var] = oldArray[var];
	}
	for (int var = length; var < maxLength; ++var) {
		elements[var] = 0;
	}
	delete[] oldArray;
	oldArray = 0;
}
template<class T>
void SortedArrayList<T>::display() {
	for (int i = 0; i < length; i++) {
		cout << i + 1 << ": " << *elements[i] << endl;
	}
}
//sort the array to be a sorted list in this function
// we will run this after length > 0 after a elemnts is added to the sorted list
template<class T>
void SortedArrayList<T>::sort() {
	//T* temp;
	//here we will swap the current element with the previous
	//as this gets invoked if last < current
	//everthing is off by 2 because length is increased before invocationb
	cout << "sort started " << endl;
	//currEntry should be the current position in the list
	//int currEntry = length-1;
	for (int i = 0; i < length; i++) {
		//swap nessecary entries in the loop
		if (*elements[i] > *elements[i + 1] && i + 1 < length) {
			cout << "NUM out of order :" << i + 1 << endl;
		}
	}

}
template<class T>
int SortedArrayList<T>::getPosition(T* element) {
	//int ReturnPos = 0;
	int foundPos = binarySearch(element);
	// if the position is found it will less than or equal to 0
	if (foundPos <= 0) {
		//should make the negative number positive
		return -foundPos;
	}
	//if the result element isnt there return -1
	return -1;
}
template<class T>
T* SortedArrayList<T>::get(int position) {
	if (position >= 0 && position <= maxLength) {
		T* returnValue = elements[position];
		cout << "return value of get: " << returnValue << endl;
		return returnValue;
	}
	return NULL;
}
template<class T>
int SortedArrayList<T>::binarySearch(T* elment) {
	//find new condition for loop
	int left = 0;
	int right = length - 1;
	int middle = left + ((right - left) / 2);
	int i = 0;
	while (i < length) {
		cout << "left : " << left << endl;
		cout << "Middle :" << middle << endl;
		cout << "Right :" << right << endl;
		if (*elements[middle] == *elment) {
			cout << "if 1" << endl;
			cout << "Returned Value :" << middle << endl;
			return middle;
		} else if (*elment < *elements[middle]) {
			cout << "if 1" << endl;
			right = (middle - 1);
		} else if (*elment > *elements[middle]) {
			cout << "if 1" << endl;
			left = middle + 1;
			middle = left + ((right - left) / 2);
		} else if (*elements[middle - 1] < *elment
				&& *elements[middle + 1] > *elment) {
			cout << "if 1" << endl;
			//if the left is less than the value and right is greater its our position we wont
			return -middle;
		}
		i++;
		cout << "NOT FINDING ANYTHING ELSE FULL" << endl;
	}
	//this function will return a positive number if the number is found and a negative number if the element is not in the list but needs a position
	//if our number is less than the left and lower than the right its our position to return
	//all else fails
	return -1;
}
//we pass the position deleted to this function so we can pop the list back
template<class T>
void SortedArrayList<T>::popBack(int delPos) {
	//we alter the array here
	for (int i = delPos; i < length; i++) {
		elements[i] = elements[i + 1];
		//making sure the shifted element at the end isnt duplicated
	}
	elements[length] = NULL;
	//sets last pos of the shifted entry to NULL
}
//element remove
template<class T>
bool SortedArrayList<T>::remove(T* element) {
	cout << "binarySearchFail" << endl;
	int present = binarySearch(element);
	cout << "Present" << endl;
	//if binary search returns a number greater than or equal to zero, the entry is there
	if (present >= 0) {
		//T* returnElement = elements[present];
		elements[present] = NULL;
		//popBack(present);
		length--;
		return true;
	} else
		return false;
}
//specific position remove
template<class T>
bool SortedArrayList<T>::remove(int position) {
	int present = binarySearch(elements[position]);
	cout << "present : " << present << endl;
	if (present >= 0) {
		//T* returnElement = elements[position];
		cout << "here" << endl;
		elements[position] = NULL;
		popBack(position);
		length--;
		return true;
	}
	return false;
}
template<class T>
int SortedArrayList<T>::add(T* element) {
//if our address is not NULL add it to the list
	int position = 0;
	if (maxLength == length) {
		//if array is full resize it
		resize();
	}
	//int present = binarySearch(element);
	//if the entry is not null add it
	if (element != NULL) {
		elements[length] = element;
		position = length;
		cout << position << endl;
		length++;
		//if our added element is greater than the pervious element, swap them
		//
		if (length > 1) {
			cout << "previous entry : " << *elements[length - 2] << endl;
			cout << "Current entry : " << *element << endl;
		}
		if (length > 1 && *elements[length - 2] > *element) {
			sort();
		}
		return position;
	} else {
		return -1;
	}
	return 0;
}
template<class T>
int SortedArrayList<T>::size() {
	return this->length;
}

#endif /* SORTEDARRAYLIST_H_ */
