/*
Nick Thoms
Data Structures 2020
Due: 2/11/2020
Lab 2: Unsorted List
Description: The purpose of this lab is to demonstrates the capabilites of an unsorted linked list with
             a pointer-based implementatin. The data structure or list will have different methods that
			 will allow the client to insert and delete items from the list. There will be a union method
			 that will create a new list from two existing lists.
*/
#include<iostream>
#include"UnsortedType.h"

using namespace std;

int main()
{
	UnsortedType list;
	UnsortedType list2;

	list.insertItem(50);
	list.insertItem(13);
	list.insertItem(69);

	list2.insertItem(2);
	list2.insertItem(19);
	list2.insertItem(38);

	cout << "List 1 \n";
	for (int i = 0; i < list.getLength(); i++)
		cout << "Item " << i+ 1 << ": " << list.getNextItem() << endl;

	cout << "\nList 2 \n";
	for (int i = 0; i < list2.getLength(); i++)
		cout << "Item " << i + 1 << ": " << list2.getNextItem() << endl;

	list.deleteItem(13);
	list2.makeEmpty();
	list2.insertItem(72);

	cout << "\nList 1 \n";
	for (int i = 0; i < list.getLength(); i++)
		cout << "Item " << i + 1 << ": " << list.getNextItem() << endl;

	cout << "\nList 2 \n";
	for (int i = 0; i < list2.getLength(); i++)
		cout << "Item " << i + 1 << ": " << list2.getNextItem() << endl;

	cout << "\n" << list.search(69) << endl;
	cout << list.search(13) << endl;

	switch (list.comparedTo(69, 50))
	{
	case GREATER: cout << "\nGREATER\n\n"; break;
	case LESS: cout << "\nLESS\n\n"; break;
	case EQUAL: cout << "\nEQUAL\n\n"; break;
	default:;
	}

	/*
	UnsortedType list3 = list.listUnion(list2);

	cout << "List 2 \n";
	for (int i = 0; i < list3.getLength(); i++)
		cout << "Item " << i + 1 << ": " << list3.getNextItem() << endl;
	*/

	return 0;
}