//HashPractice.cpp - Main driver for program, used to test edge cases, behavior, and make sure that creases are ironed out

#include <iostream>
#include "HashTable.h"

using namespace std;

int main()
{
	HashTable hash;
	hash.find(4);
	hash.insert(4, 5);
	hash.insert(21, 5);
	hash.find(4);
	hash.find(21);
	hash.remove(21);
	hash.find(4);
	hash.find(21);
	hash.remove(21);
	hash.remove(4);
	hash.remove(21);
	return 0;
}