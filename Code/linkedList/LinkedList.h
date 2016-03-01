/*
 * LinkedList.h
 *
 *  Created on: Feb 26, 2016
 *      Author: bkubiak
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>
using namespace std;
#include "Node.h"

template<class T>
class LinkedList {
private:
	Node<T>* head;
	int length;
	Node<T>* getNode(int position);
public:
	LinkedList();
	virtual ~LinkedList();
	int size();
	bool add(int position, T* element);
	T* remove(int position);
	T* get(int position);
	bool set(int position, T* element);
	void setNext(Node<T>* nextNode);
	/**
	 * Merges a specified list into this list at alternate positions.
	 * @param[in] list The list that has to be merged into this list.
	 * @post If the list given in the parameter is NULL or empty, then
	 * this list remains unchanged. First n (n <= length) elements of the list
	 * given in the parameter appear at non-even positions in this list.
	 * Remaining elements, if there are such, are appended to the end of this list.
	 * @return TRUE if the list was successfully merged into this list,
	 * FALSE if it is NULL.
	 */
	bool merge(LinkedList<T>* list);
	void rotate(int k);
	void reverse();
};

template<class T>
LinkedList<T>::LinkedList() {
	head = NULL;
	length = 0;
}

template<class T>
LinkedList<T>::~LinkedList() {
	Node<T>* nodeForRemoval = head;
	while (nodeForRemoval != NULL) {
		head = head->getNext();
		nodeForRemoval->setNext(NULL);
		delete nodeForRemoval;
		nodeForRemoval = NULL;
		nodeForRemoval = head;
	}
}
template<class T>
bool LinkedList<T>::merge(LinkedList<T>* list) {
	//point first entry to first entry in second list and alternate with this pattern until list is completely re-pointed
	//maybe use a loop?
}
template<class T>
void LinkedList<T>::rotate(int k) {
//rotates/reverses to a certain point in the list so 1-2-3-4 k = 2 would make the list 2-1-3-4

}

template<class T>
void LinkedList<T>::reverse() {
//completely reverse the direction of the list 1-2-3-4 would be 4-3-2-1
}
template<class T>
Node<T>* LinkedList<T>::getNode(int position) {
	Node<T>* node = head;
	for (int var = 0; var < position; ++var) {
		node = node->getNext();
	}
	return node;
}

template<class T>
int LinkedList<T>::size() {
	return length;
}

template<class T>
bool LinkedList<T>::add(int position, T* element) {
	if (element == NULL) {
		return false;
	}
	bool notValidPosition = (position < 0 || position > length);
	if (notValidPosition) {
		return false;
	}
	Node<T>* newNode = new Node<T>(element);
	if (position == 0) {
		newNode->setNext(head);
		head = newNode;
	} else {
		Node<T>* precedingNode = getNode(position - 1);
		newNode->setNext(precedingNode->getNext());
		precedingNode->setNext(newNode);
	}
	++length;
	return true;
}

template<class T>
T* LinkedList<T>::remove(int position) {
	bool notValidPosition = (position < 0 || position >= length);
	if (notValidPosition) {
		return NULL;
	}
	Node<T>* nodeForRemoval = NULL;
	if (position == 0) {
		nodeForRemoval = head;
		head = head->getNext();
	} else {
		Node<T>* precedingNode = getNode(position - 1);
		nodeForRemoval = precedingNode->getNext();
		precedingNode->setNext(nodeForRemoval->getNext());
	}
	T* removedElement = nodeForRemoval->getElement();
	nodeForRemoval->setNext(NULL);

	delete nodeForRemoval;
	nodeForRemoval = NULL;
	--length;
	return removedElement;
}

template<class T>
T* LinkedList<T>::get(int position) {
	bool notValidPosition = (position < 0 || position >= length);
	if (notValidPosition) {
		return NULL;
	}
	Node<T>* node = getNode(position);
	return node->getElement();
}

template<class T>
bool LinkedList<T>::set(int position, T* element) {
	if (element == NULL) {
		return false;
	}
	bool notValidPosition = (position < 0 || position >= length);
	if (notValidPosition) {
		return false;
	}
	Node<T>* node = getNode(position);
	node->setElement(element);
	return true;
}

#endif /* LINKEDLIST_H_ */
