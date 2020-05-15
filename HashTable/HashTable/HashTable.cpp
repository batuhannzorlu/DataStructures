

#include <iostream>
#include<cstdlib>
#include<string>

#include "hash.h"

using namespace std;

int main()
{
	hashx Hashy;
	string name = "";
	Hashy.AddItem("Monica", "Cola");
	Hashy.AddItem("Rachel", "Iced Mocha");
	//Hashy.AddItem("Rachel", "Water");
	Hashy.AddItem("Joey", "Chai Tea");
	Hashy.AddItem("Chandler", "Tea");
	Hashy.AddItem("Ross", "Skinny Latte");
	Hashy.AddItem("Annie", "Water");
	Hashy.AddItem("Sarah", "Green Tea");
	Hashy.AddItem("Stece", "Smoothy");
	Hashy.AddItem("Laura", "Apple Cider");
	Hashy.AddItem("Joe", "Beer");

	//while (name!="exit")
	//{
	//	cout << "search for ";
	//	cin >> name;
	//	if (name !="exit")
	//	{
	//		Hashy.FindDrink(name);
	//	}
	//		
	//}

	Hashy.PrintTable();
	//Hashy.PrintItemsInIndex(2);

}

