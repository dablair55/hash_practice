//HashTable.cpp - Defines behavior for the hash table

#include "HashTable.h";
#include <stdio.h>
#include <iostream>

//Simplify use of cout/endl
using namespace std;

//Prime number for hash size to avoid empty indices, kept small but adjustable for time being
const int HASH_SIZE = 17;

		//Constructor, using double linked list for faster deletion time
		HashTable::HashTable()
		{
			head = new node* [HASH_SIZE];
			tail = new node * [HASH_SIZE];
			for (int i = 0; i < HASH_SIZE; i++) 
			{
				head[i] = NULL;
				tail[i] = NULL;
			}
		}

		//Destructor
		HashTable::~HashTable()
		{
			delete[] head;
			delete[] tail;
		}

		//Hash function to return index where specific key is stored
		static int Hash(int key)
		{
			return key % HASH_SIZE;
		}

		//Find specific key within has table
		bool HashTable::find(int key)
		{
			//Hash function to find index, start from beginning of list at specific hash index
			int hashIndex = Hash(key);
			bool found = false;
			node* entry = head[hashIndex];

			//If values under specific hash index, traverse the list to check for key
			if (entry != NULL) 
			{
				while (entry != NULL && found == false) 
				{
					//If found, flag as true
					if (entry->key == key)
						found = true;
					//Assertion statement that key was found, also spits out value associated with key
					if (found) 
					{
						cout << "Element found: KEY = " << key << " VALUE = ";
						cout << entry->val << endl;
						return true;
					}
					//Else, check next key under list
					entry = entry->next;
				}
			}
			//If nothing is found, output message that key is not in list
			if (!found)
			{
				cout << "Element not found: KEY = " << key << endl;
				return false;
			}
		}

		//Insert node into hash table
		void HashTable::insert(int key, int value)
		{
			//Hash function to find index, start from beginning of list at specific hash index
			int hashIndex = Hash(key);
			node* entry = head[hashIndex];

			//If  no entries exist under that list, add entry, set head and tail of that list to that entry
			if (entry == NULL) 
			{
				entry = new node;
				entry->val = value;
				entry->key = key;
				entry->next = NULL;
				entry->prev = NULL;
				head[hashIndex] = entry;
				tail[hashIndex] = entry;
			}
			//Else, traverse the list, add entry to end, set tail to entry
			else 
			{
				while (entry != NULL)
					entry = entry->next;

				entry = new node;
				entry->val = value;
				entry->key = key;
				entry->next = NULL;
				entry->prev = tail[hashIndex];
				
				head[hashIndex]->next = entry;
				tail[hashIndex] = entry;
			}
			//Assert that value was added
			cout << "Element added succesfully: KEY = " << key <<" VALUE = " << value << endl;
		}

		void HashTable::remove(int key)
		{
			//Hash function to find index, start from beginning of list at specific hash index
			int hashIndex = Hash(key);
			node* entry = head[hashIndex];

			//If no entries exist under that hash index, output message that removing was unsuccessful
			if (entry == NULL)
			{
				cout << "Element removed unsuccesfully  (NO ENTRIES): KEY = " << key << endl;
				return;
			}

			//Traverse entries looking for key
			while (entry != NULL) 
			{
				if (entry->next == NULL) 
				{
					//If entry does not exist, output message that removing was unsuccessful
					if (entry->key != key)
					{
						cout << "Element removed unsuccesfully (DNE): KEY = " << key << endl;
						return;
					}
					//If only value, remove and set head and tail to null
					else if (entry->prev == NULL) 
					{
						head[hashIndex] = NULL;
						tail[hashIndex] = NULL;
						delete entry;
						break;
					}
					//Remove and set head and tail to proper position
					else 
					{
						tail[hashIndex] = entry->prev;
						tail[hashIndex]->next = NULL;
						delete entry;
						entry = tail[hashIndex];
					}
				}
				//Check next entry
				entry = entry->next;
			}
			//Assert that entry was successfully removed
			cout << "Element removed succesfully: KEY = " << key << endl;
		}