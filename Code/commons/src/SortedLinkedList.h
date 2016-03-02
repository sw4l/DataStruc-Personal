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
	Node<T>* getNode(int position);
public:
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
int SortedLinkedList<T>::size() {
	return length;
}

template<class T>
int SortedLinkedList<T>::getPosition(T* element) {

	return 0;
}

template<class T>
T* SortedLinkedList<T>::get(int position) {
	bool notValidPosition = (position < 0 || position >= length);
	if (notValidPosition) {
		return NULL;
	}
	Node<T>* node = getNode(position);
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
bool SortedLinkedList<T>::remove(T* element) {

}

template<class T>
int SortedLinkedList<T>::add(T* element) {

}
#endif /* SORTEDLINKEDLIST_H_ */
