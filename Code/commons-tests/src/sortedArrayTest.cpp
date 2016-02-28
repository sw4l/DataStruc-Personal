/*
 * SortedSortedArrayListTests.cpp

 *
 *  Created on: Feb 24, 2016
 *      Author: lerenard
 */

#include "../src/SortedArrayList.h"
#include "../src/ArrayList.h"
#include "gtest/gtest.h"
#include <iostream>
#include <cstddef>

using namespace std;

TEST(SortedArrayList, addValidToEmptyList) {
	SortedArrayList<int> myList;
	int myInt = 13;

	EXPECT_EQ(0, myList.add(&myInt));

	EXPECT_EQ(myList.size(), 1);
	EXPECT_EQ(myList.getPosition(&myInt), 0);
	EXPECT_EQ(myList.get(0), &myInt);
	//EXPECT_FALSE(myList.get(-1));
}

TEST(SortedArrayList, addNULL) {
	SortedArrayList<int> myList;
	EXPECT_EQ(-1, myList.add(NULL));
	EXPECT_EQ(myList.size(), 0);
}

TEST(SortedArrayList, addFourStrings) {
	SortedArrayList<string> myList;
	string str1 = "hello";
	EXPECT_EQ(0, myList.add(&str1));
	string str2 = "bonjour";
	EXPECT_EQ(0, myList.add(&str2));
	EXPECT_EQ(myList.get(1), &str1);
	string str3 = "hola";
	EXPECT_EQ(2, myList.add(&str3));
	string str4 = "ciao";
	EXPECT_EQ(1, myList.add(&str4));

	EXPECT_EQ(myList.size(), 4);
	cout << "Failed here 1" << endl;
	EXPECT_EQ(*myList.get(0), "bonjour");
	cout << "Failed here" << endl;
	EXPECT_EQ(*myList.get(1), "ciao");
	cout << "Failed here" << endl;
	EXPECT_EQ(*myList.get(2), "hello");
	cout << "Failed here" << endl;
	EXPECT_EQ(*myList.get(3), "hola");
	cout << "Failed here" << endl;
}

TEST(SortedArrayList, addFourInts) {
	SortedArrayList<int> list;
	int a = 1000, b = 243504, c = 0, d = -2340532;
	EXPECT_EQ(0, list.add(&a));
	EXPECT_EQ(0, list.add(&c));
	EXPECT_EQ(2, list.add(&b));
	EXPECT_EQ(0, list.add(&d));
	EXPECT_EQ(list.getPosition(&a), 2);
	EXPECT_EQ(list.getPosition(&b), 3);
	EXPECT_EQ(list.getPosition(&c), 1);
	EXPECT_EQ(list.getPosition(&d), 0);
}
/*
TEST(SortedArrayList, resizeTest) {
	SortedArrayList<int> myList;
	int maxInt = 100;
	for (int i = 0; i < maxInt; ++i) {
		int myInt = 5;
		EXPECT_TRUE(myList.add(&myInt) <= i);
	}
	EXPECT_EQ(myList.size(), maxInt);
	EXPECT_FALSE(myList.get(maxInt));
}
*/
TEST(SortedArrayList, removeFromEmptyList) {
	SortedArrayList<int> myList;
	EXPECT_FALSE(myList.remove(1));
	EXPECT_FALSE(myList.remove(0));
}

TEST(SortedArrayList, duplicates) {
	SortedArrayList<int> myList;
	int int1 = 1, int2 = 1;
	myList.add(&int1);
	EXPECT_TRUE(myList.remove(&int2));
}

TEST(SortedArrayList, removeFrom1ElemList) {
	SortedArrayList<int> myList;
	int myInt1 = 0;
	myList.add(&myInt1);
	cout << "Here 1" << endl;
	//EXPECT_FALSE(myList.remove(static_cast<int*>(NULL)));
	cout << "Here 2" << endl;
	EXPECT_EQ(myList.size(), 1);
	EXPECT_TRUE(myList.remove(&myInt1));
	EXPECT_EQ(myList.size(), 0);
}

TEST(SortedArrayList, duplicateBools) {
	SortedArrayList<bool> myList;
	bool bool1 = false;
	EXPECT_EQ(myList.add(&bool1), 0);
	bool bool2 = true;
	EXPECT_EQ(myList.add(&bool2), 1);
	bool bool3 = false;
	EXPECT_TRUE(myList.add(&bool3) < 2);

	EXPECT_EQ(myList.size(), 3);

	EXPECT_TRUE(myList.remove(&bool1));

	EXPECT_EQ(myList.size(), 2);

	EXPECT_FALSE(*myList.get(0));
	EXPECT_TRUE(*myList.get(1));
	EXPECT_EQ(myList.getPosition(&bool2), 1);
	EXPECT_EQ(myList.size(), 2);
	EXPECT_TRUE(myList.remove(&bool2));
	EXPECT_FALSE(myList.remove(&bool2));
	EXPECT_EQ(myList.size(), 1);
	EXPECT_EQ(myList.getPosition(&bool3), 0);
	EXPECT_EQ(myList.getPosition(&bool2), -1);
}
