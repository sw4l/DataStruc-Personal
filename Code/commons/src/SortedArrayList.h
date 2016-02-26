/*
 * SortedArrayList.h
 *
 *  Created on: Feb 26, 2016
 *      Author: Dakota
 */

#ifndef SORTEDARRAYLIST_H_
#define SORTEDARRAYLIST_H_
template<class T>
class SortedArrayList {
	int maxLength;
	T** elements;
	int length;
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
};
template<class T>
SortedArrayList<T>::SortedArrayList() {
	maxLength = 100;
	elements = new T*[maxLength];
	for (int var = 0; var < maxLength; ++var) {
		elements[var] = NULL;
	}
	length = 0;
}

template<class T>
int SortedArrayList<T>::getPosition(T* element) {
return 0;
}

template<class T>
bool SortedArrayList<T>::remove(T* element) {
return false;
}
template<class T>
int SortedArrayList<T>::add(T* element) {
return 0;
}
template<class T>
int SortedArrayList<T>::size() {
return 0;
}
#endif /* SORTEDARRAYLIST_H_ */
