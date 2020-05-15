
#include <iostream>
#include<cstdlib>
#include<string>

#include "hash.h"

using namespace std;

hashx::hashx() {
	for (int i = 0; i < this->tableSize; i++)
	{
		this->HashTable[i] = new item;
		this->HashTable[i]->name = "empty";
		this->HashTable[i]->drink = "empty";
		this->HashTable[i]->next = NULL;
	}
}
int hashx::Hash(string key) {

	int hash = 0;
	int index;

	for (int i = 0; i < key.length(); i++)
		hash += static_cast<int>(key[i]);

	index = hash % tableSize;
	return index;

}
void hashx::AddItem(string name, string drink) {

	int index = Hash(name);
	if (this->HashTable[index]->name == "empty")
	{
		this->HashTable[index]->name = name;
		this->HashTable[index]->drink = drink;
	}
	else
	{
		item* Ptr = this->HashTable[index];
		item*n = new item;
		n->name = name;
		n->drink = drink;
		n->next = NULL;

		while (Ptr->next != NULL)
			Ptr = Ptr->next;

		Ptr->next = n;
	}

}
int hashx::NumberOfItemsIndex(int index) {

	int count = 0;

	if (HashTable[index]->name == "empty")
		return count;
	else
	{
		count++;
		item* Ptr = HashTable[index];
		while (Ptr->next != NULL)
		{
			count++;
			Ptr = Ptr->next;
		}
	}

	return count;

}
void hashx::PrintTable() {

	int number;

	for (int i = 0; i < tableSize; i++)
	{
		number = NumberOfItemsIndex(i);
		cout << "--------------------------\n";
		cout << "intdex= " << i << endl;
		cout << HashTable[i]->name << endl;
		cout << HashTable[i]->drink << endl;
		cout << "num of items= " << number << endl;
		cout << "--------------------------\n";
	}
}
void hashx::PrintItemsInIndex(int index) {
	item* Ptr = this->HashTable[index];

	if (Ptr->name == "empty")
	{
		cout << "index= " << index << "is empty" << endl;
	}
	else
	{
		cout << "index= " << index << "Contains:" << endl;
		cout << "--------------------------\n";
		while (Ptr != NULL)
		{
			cout << Ptr->name << endl;

			cout << Ptr->drink << endl;
			Ptr = Ptr->next;
			cout << "--------------------------\n";
		}
	}
}
void hashx::FindDrink(string name) {

	int index = Hash(name);
	bool foundName = false;
	string drink;

	item* Ptr = HashTable[index];
	while (Ptr != NULL)
	{
		if (Ptr->name == name) {
			foundName = true;
			drink = Ptr->drink;
		}
		Ptr = Ptr->next;
	}
	if (foundName == true)
	{
		cout << "Favorite drink = " << drink << endl;
	}
	else
	{
		cout << name << "'s info was not found in the Hash Table\n";
	}

}
void hashx::RemoveItem(string name) {

	int index = Hash(name);

	item* delPtr;
	item* P1;
	item*P2;
	

}