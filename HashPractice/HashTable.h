//HashTable.h - Header file for HashTable.cpp
#pragma once

//Each individual entry in hash table
struct node
{
	int key, val;
	node* next;
	node* prev;
};

class HashTable
{	
	public:
		node** head, ** tail;

		HashTable();
		~HashTable();
		bool find(int key);
		void insert(int key, int value);
		void remove(int key);
};

