/*
 * ArrayList.h
 *
 *  Created on: Dec 17, 2014
 *      Author: bkubiak
 */

#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

#include <iostream>
using namespace std;

template<class T>
class ArrayList {

private:
	int maxLength;
	T** elements;
	int length;

	void resize();

public:
	ArrayList();
	virtual ~ArrayList();
	int size();
	bool add(int position, T* element);
	T* remove(int position);
	T* get(int position);
	bool set(int position, T* element);
	bool append(T* element);
	bool isEmpty();
	ArrayList<T>* subList(int position, int toPostion);
};

template<class T>
bool ArrayList<T>::append(T* element) {
	if (*element == NULL) {
		return false;
	} else {
		add(element);
	}
}

template<class T>
bool ArrayList<T>::isEmpty() {
	if (length == 0) {
		return true;
	} else {
		return false;
	}
}

template<class T>
ArrayList<T>* ArrayList<T>::subList(int position, int toPosition) {
	ArrayList<T> returnList = new ArrayList<T>;
	for (int i = position; i < toPosition; i++) {
		returnList.append(elements[i]);
	}
}

template<class T>
ArrayList<T>::ArrayList(void) {
	maxLength = 100;
	elements = new T*[maxLength];
	for (int var = 0; var < maxLength; ++var) {
		elements[var] = NULL;
	}
	length = 0;
}

template<class T>
ArrayList<T>::~ArrayList(void) {
	delete[] elements;
}

template<class T>
int ArrayList<T>::size() {
	return length;
}

template<class T>
bool ArrayList<T>::add(int position, T* element) {
	if (element == NULL) {
		return false;
	}
	bool notValidPosition = (position < 0 || position > length);
	if (notValidPosition) {
		return false;
	}
	bool notBigEnough = (maxLength == length);
	if (notBigEnough) {
		resize();
	}
	for (int var = length; var > position; --var) {
		elements[var] = elements[var - 1];
	}
	elements[position] = element;
	++length;
	return true;
}

template<class T>
T* ArrayList<T>::remove(int position) {
	bool notValidPosition = (position < 0 || position >= length);
	if (notValidPosition) {
		return NULL;
	}
	T* element = elements[position];
	--length;
	for (int var = position; var < length; ++var) {
		elements[var] = elements[var + 1];
	}
	elements[length] = NULL;
	return element;
}

template<class T>
T* ArrayList<T>::get(int position) {
	bool notValidPosition = (position < 0 || position >= length);
	if (notValidPosition) {
		return NULL;
	}
	return elements[position];
}

template<class T>
bool ArrayList<T>::set(int position, T* element) {
	if (element == NULL) {
		return false;
	}
	bool notValidPosition = (position < 0 || position >= length);
	if (notValidPosition) {
		return false;
	}
	elements[position] = element;
	return true;
}

template<class T>
void ArrayList<T>::resize() {
	maxLength = 2 * maxLength;
	T** oldArray = elements;
	elements = new T*[maxLength];
	for (int var = 0; var < length; ++var) {
		elements[var] = oldArray[var];
	}
	for (int var = length; var < maxLength; ++var) {
		elements[var] = NULL;
	}
	delete[] oldArray;
	oldArray = NULL;
}

#endif /* ARRAYLIST_H_ */
