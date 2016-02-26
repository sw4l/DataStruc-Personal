#include <iostream>
using namespace std;
#include "gtest/gtest.h"
#include "../src/ArrayList.h"

TEST(ArrayList, addToEmptyListAtValidPosition) {
	ArrayList<int> myList;
	int myInt = 13;
	bool added = myList.add(0, &myInt);
	EXPECT_TRUE(added);

	EXPECT_EQ(myList.size(), 1);
}

TEST(ArrayList, addToEmptyListAtInvalidPosition) {
	ArrayList<int> myList;
	int myInt = 23;
	bool added = myList.add(2, &myInt);
	EXPECT_FALSE(added);

	EXPECT_EQ(myList.size(), 0);
}

TEST(ArrayList, addTo3ElemListAtValidPosition) {
	ArrayList<int> myList;
	int myInt1 = 12;
	bool added = myList.add(0, &myInt1);
	EXPECT_TRUE(added);
	int myInt2 = 25;
	added = myList.add(1, &myInt2);
	EXPECT_TRUE(added);
	int myInt3 = 51;
	added = myList.add(2, &myInt3);
	EXPECT_TRUE(added);
	int myInt4 = 17;
	added = myList.add(1, &myInt4);
	EXPECT_TRUE(added);

	EXPECT_EQ(myList.size(), 4);

	EXPECT_EQ(*myList.get(0), 12);
	EXPECT_EQ(*myList.get(1), 17);
	EXPECT_EQ(*myList.get(2), 25);
	EXPECT_EQ(*myList.get(3), 51);
}

TEST(ArrayList, addTo3ElemListAtInvalidPosition) {
	ArrayList<int> myList;
	int myInt1 = 121;
	bool added = myList.add(0, &myInt1);
	EXPECT_TRUE(added);
	int myInt2 = 251;
	added = myList.add(1, &myInt2);
	EXPECT_TRUE(added);
	int myInt3 = 511;
	added = myList.add(2, &myInt3);
	EXPECT_TRUE(added);
	int myInt4 = 171;
	added = myList.add(4, &myInt4);
	EXPECT_FALSE(added);

	EXPECT_EQ(myList.size(), 3);

	EXPECT_EQ(*myList.get(0), 121);
	EXPECT_EQ(*myList.get(1), 251);
	EXPECT_EQ(*myList.get(2), 511);
}

TEST(ArrayList, removeFromEmptyList) {
	ArrayList<int> myList;
	int* removedElement = myList.remove(1);
	EXPECT_EQ(NULL, removedElement);
}

TEST(ArrayList, removeFrom1ElemList) {
	ArrayList<int> myList;
	int myInt1 = 56;
	myList.add(0, &myInt1);
	int* removedElement = myList.remove(0);
	//EXPECT_NE(NULL, removedElement);
	EXPECT_EQ(myList.size(), 0);
}

TEST(ArrayList, removeFrom3ElemListFromValidPosition) {
	ArrayList<int> myList;
	int myInt1 = 121;
	bool added = myList.add(0, &myInt1);
	EXPECT_TRUE(added);
	int myInt2 = 32;
	added = myList.add(1, &myInt2);
	EXPECT_TRUE(added);
	int myInt3 = 22;
	added = myList.add(2, &myInt3);
	EXPECT_TRUE(added);

	EXPECT_EQ(myList.size(), 3);

	bool removed = myList.remove(0);
	EXPECT_TRUE(removed);

	EXPECT_EQ(myList.size(), 2);

	EXPECT_EQ(*myList.get(0), 32);
	EXPECT_EQ(*myList.get(1), 22);
}
