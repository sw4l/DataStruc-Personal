/*
 * ArrayStack.h
 *
 *  Created on: Feb 8, 2016
 *      Author: bkubiak
 */

#ifndef ARRAYSTACK_H_
#define ARRAYSTACK_H_

#include <iostream>
using namespace std;

template<class T>
class ArrayStack {
private:
	int maxLength;
	T** elements;
	int length;

	void resize();
public:
	ArrayStack();
	~ArrayStack();

	bool isEmpty();
	bool push(T* element);
	T* pop();
	T* peek();
};

template<class T>
ArrayStack<T>::ArrayStack() {
	maxLength = 100;
	elements = new T*[maxLength];
	for (int var = 0; var < maxLength; ++var) {
		elements[var] = NULL;
	}
	length = 0;
}

template<class T>
ArrayStack<T>::~ArrayStack(void) {
	delete[] elements;
	elements = NULL;
}

template<class T>
bool ArrayStack<T>::isEmpty() {
	return length == 0;
}

template<class T>
bool ArrayStack<T>::push(T* element) {
	if (element == NULL) {
		return false;
	}
	bool notBigEnough = (maxLength == length);
	if (notBigEnough) {
		resize();
	}
	elements[length] = element;
	++length;
	return true;
}

template<class T>
T* ArrayStack<T>::pop() {
	T* element = NULL;
	if (length != 0) {
		element = elements[length - 1];
		elements[length - 1] = NULL;
		--length;
	}
	return element;
}

template<class T>
T* ArrayStack<T>::peek() {
	T* element = NULL;
	if (length != 0)
		element = elements[length - 1];
	return element;
}

template<class T>
void ArrayStack<T>::resize() {
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

#endif /* ARRAYSTACK_H_ */
