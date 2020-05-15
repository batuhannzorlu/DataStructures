
#ifndef HASH_H

#define HASH_H

#include <iostream>
#include<cstdlib>
#include<string>

using namespace std;

class hashx
{
private:
	static const int tableSize=40;

	struct item {

		string name;
		string drink;
		item*next;
	};
	item* HashTable[tableSize];

public:
	hashx();
	int Hash(string key);
	void AddItem(string name, string drink);
	int NumberOfItemsIndex(int index);
	void PrintTable();
	void PrintItemsInIndex(int index);
	void FindDrink(string name);
	void RemoveItem(string name);
};

#endif