//============================================================================
// Name        : Driver.cpp
// Author      : 
// Version     :
// Copyright   :
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "Stack.h"
#include "ArrayList.h"
#include "SortedArrayList.h"
int main() {
	ArrayList<string> list;
	cout << "I COMPILED";
	string s1, s2, s3, s4, s5, s6;
	s1 = "bread";
	s2 = "cookies";
	s3 = "cake";
	s4 = "bannanas";
	s5 = "parsley";
	s6 = "apples";
	list.add(0, &s1);
	list.add(1, &s2);
	list.add(2, &s3);
	list.add(3, &s4);
	list.add(4, &s5);
	list.remove(2);
	list.add(4, &s6);
	list.subList(list.size(),0);

	return 0;
}
