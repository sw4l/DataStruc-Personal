/*
 * SortedLinkedList.h
 *
 *  Created on: Mar 1, 2016
 *      Author: Dakota
 */

#ifndef SORTEDLINKEDLIST_H_
#define SORTEDLINKEDLIST_H_
#include"Node.h"
template<class T>
class SortedLinkedList {
	Node<T>* head;
	int length;
	void sortNodes();
	Node<T>* getNode(int position);
public:
	void displayNodes();
	SortedLinkedList();
	virtual ~SortedLinkedList();
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
};

template<class T>
SortedLinkedList<T>::SortedLinkedList() {
	head = NULL;
	length = 0;
}

template<class T>
SortedLinkedList<T>::~SortedLinkedList() {
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
void SortedLinkedList<T>::displayNodes() {
	for (int i = 0; i < length; i++) {
		cout << i + 1 << " : " << *get(i) << endl;
	}

}

template<class T>
Node<T>* SortedLinkedList<T>::getNode(int position) {
	Node<T>* node = head;
	for (int var = 0; var < position; ++var) {
		node = node->getNext();
	}
	return node;
}

template<class T>
int SortedLinkedList<T>::size() {
	return length;
}
//sorts the nodes as they are added to the list
template<class T>
void SortedLinkedList<T>::sortNodes() {
//cur working here
//until we get our iterator we iterate through manually comparing
	Node<T>* node = head;
	Node<T>* temp = NULL;
	Node<T>* hold = NULL;
	Node<T>* nodeAfter = NULL;
	for (int i = 0; i < length; i++) {
		//if our current pos is grater than the next swtich them
		//next value in the list
		//1 ahead
		hold = head->getNext();
		// 2 ahead
		nodeAfter = hold->getNext();
		if (*head->getElement() > *head->getNext()->getElement()) {
			temp = node;
			hold = temp;
			temp = nodeAfter;
		}
		head = head->getNext();
	}
}

//returns -1 if the element is not in the list
template<class T>
int SortedLinkedList<T>::getPosition(T* element) {
	Node<T>* node = head;
	int retVal = -1;

	for (int var = 0; var < length - 1; ++var) {
		if (*element == *node->getElement()) {
			retVal = var;
		}
		node = node->getNext();
		retVal = var;
	}
	return retVal;
}

//type error fix this
template<class T>
T* SortedLinkedList<T>::get(int position) {
	Node<T> *node = head;
	for (int var = 0; var < position; ++var) {
		node = node->getNext();
	}
	return node->getElement();
}

template<class T>
bool SortedLinkedList<T>::remove(int position) {
	bool notValidPosition = (position < 0 || position >= length);
	if (notValidPosition) {
		return NULL;
	}
	Node<T>* nodeForRemoval = NULL;
	if (position == 0) {
		nodeForRemoval = head;
		head = head->getNext();
	} else {
		Node<T>* precedingNode = getPosition(position - 1);
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
bool SortedLinkedList<T>::remove(T* element) {
//iteratator needed
//search through and find the node its in
	int pos = getNode(element);
	Node<T>* nodeForRemoval = NULL;
//if our node is in the list
	if (pos >= 0) {

		if (pos == 0) {
			nodeForRemoval = head;
			head = head->getNext();
		} else {
			Node<T>* precedingNode = getNode(length - 1);
			nodeForRemoval = precedingNode->getNext();
			precedingNode->setNext(nodeForRemoval->getNext());
		}
		return true;
	}


	return false;
}

template<class T>
int SortedLinkedList<T>::add(T* element) {
	Node<T>* newNode = new Node<T>(element);
// if length = 0 no sort else sort
//if not in list return 0
	cout << "Added" << endl;
	if (length == 0) {
		newNode->setNext(head);
		head = newNode;
	} else {
		Node<T>* precedingNode = getNode(length - 1);
		newNode->setNext(precedingNode->getNext());
		precedingNode->setNext(newNode);
		//sortNodes();
	}
	length++;
	//get position again after sorting

	int getPos = getPosition(element);
	return getPos;

}
#endif /* SORTEDLINKEDLIST_H_ */
