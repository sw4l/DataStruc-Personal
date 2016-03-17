/*
 * SuperStack.h
 *
 *  Created on: Mar 10, 2016
 *      Author: Dakota
 */

#ifndef SUPERSTACK_H_
#define SUPERSTACK_H_
#include <iostream>
#include "ArrayStack.h"
template<class T>
class SuperStack {
	ArrayStack<T> maxValue;
	ArrayStack<T> myStack;
public:
	SuperStack();
	virtual ~SuperStack();
	bool push(T* element);
	T* pop();
	T* peek();
	T* getMax();

};
//constructor
template<class T>
SuperStack<T>::SuperStack() {

}
//destructor
template<class T>
SuperStack<T>::~SuperStack() {

}
//our method implementations

/*
 * we check if the element is null if not push
 * update maxValue if element is greater than current MaxValue
 */
template<class T>
bool SuperStack<T>::push(T* element) {
	if (element != NULL) {
		myStack.push(element);
		//if the added element is larger than our stored max value, push it to our maxValue stack
		if (*element > *maxValue.peek()) {
			maxValue.push(element);
		}
		return true;
	} else {
		return false;
	}
}

//we just call stack pop and return the removed element
template<class T>
T* SuperStack<T>::pop() {
	T* temp;
	if (!myStack.isEmpty()) {
		temp = myStack.peek();
		myStack.pop();
		//checking if our maxValue thats stored on the tracked stack is being deleted if so pop it out of maxValue
		if (*temp == *maxValue.peek()) {
			maxValue.pop();
		}
		return temp;
	} else {
		return NULL;
	}
}

template<class T>
T* SuperStack<T>::peek() {
	T* temp;
	if (!myStack.isEmpty()) {
		temp = myStack.peek();
		return temp;
	} else {
		return NULL;
	}
}

template<class T>
T* SuperStack<T>::getMax() {
	return this->maxValue.peek();
}
#endif /* SUPERSTACK_H_ */
