/*
 * Stack.h
 *
 *  Created on: Feb 8, 2016
 *      Author: bkubiak
 */

#ifndef STACK_H_
#define STACK_H_

template<class T>
class Stack {
private:
	T** elements;
	int maxLength;
	int length;

public:
	Stack();
	~Stack();
	bool push(T& newElement);
	T* peek();
	T* pop();
	bool isEmpty();
};

template<class T>
Stack<T>::Stack() {
	maxLength = 100;
	elements = new T*[maxLength];
	for (int var = 0; var < maxLength; ++var) {
		elements[var] = NULL;
	}
	length = 0;
}

template<class T>
Stack<T>::~Stack() {
	delete[] elements;
}

#endif /* STACK_H_ */
