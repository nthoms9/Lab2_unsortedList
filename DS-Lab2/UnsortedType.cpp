/*
Nick Thoms
Data Structures 2020
Due: 2/11/2020
Lab 2: Unsorted List
Description: This is the implementation file for the UnsortedType class. It contains the definitions for the
             methods which manipulate the list.
*/

#include<iostream>
#include"UnsortedType.h"

using namespace std;

// The constructor
UnsortedType::UnsortedType()
{ 
	head = nullptr;
	pos = nullptr;
	length = 0;
}

UnsortedType::~UnsortedType()
{
	makeEmpty();             //The destructor calls the makeEmpty function.
}

//Items are inserted to the list.
bool UnsortedType::insertItem(itemType item_)
{

if(isFull() == false)
{
	nodeType* newNode = new nodeType;
	newNode->item = item_;
	newNode->next = head;
	head = newNode;

	length++;

	return true;
}
else
	return false;

}

//Items are deleted from the list.
bool UnsortedType::deleteItem(itemType item_)
{
	if (head == nullptr)
		return false;
	else
	{
		nodeType* deleteNode = head->next;
		nodeType* previous = head;

		if (head->item == item_)
		{
			head = head->next;
			delete previous;
			length--;
			resetList();
			return true;
		}
		else
		{
			int loops = 0;
			while (deleteNode->item != item_ && deleteNode->next != nullptr)
			{
				deleteNode = deleteNode->next;
				previous = previous->next;
			}

			if (deleteNode->next == nullptr && deleteNode->item != item_)   
				return false;
			else
			{
				previous->next = deleteNode->next;  // Deletes nodes other than the head node.
				delete deleteNode;
				length--;
				resetList();
				return true;
			}
		}
	}
}

void UnsortedType::resetList()
{
	pos = nullptr;
}

//The position pointer is being moved to allow for acces to other parts of the list.
itemType UnsortedType::getNextItem()
{
	if (pos == nullptr)
		pos = head;
	else
		pos = pos->next;

	if (pos == nullptr)
	{
		resetList();
		cout << "End of list reached: list has been reset";
		return NULL;
	}
	else
		return pos->item;

}


bool UnsortedType::isFull()
{
	if (length == maxItems)
		return true;
	else
		return false;
}

//All items in the list are deleted.
bool UnsortedType::makeEmpty()
{
	if (head == nullptr)
		return false;
	else
	{
		do
		{

			nodeType* deleteNode = head;
			head = head->next;
			delete deleteNode;
			length--;

		} while (head != nullptr);

		resetList();
		return true;

	}
}

// This function searches or a value in the list.
nodeType* UnsortedType::search(itemType item_)
{
	if (head == nullptr)
		return nullptr;
	else
	{
		nodeType* loc = head;

		while (loc->item != item_ && loc->next != nullptr)
		{
			loc = loc->next;
		}

		if (loc->next == nullptr && loc->item != item_)
			return nullptr;
		else
			return loc;
	}
}

RelationType UnsortedType::comparedTo(itemType item1, itemType item2)
{
	if (item1 > item2)
		return GREATER;
	else if (item1 < item2)       //A comparison is made between arguments
		return LESS;
	else if (item1 == item2)
		return EQUAL;
}

//combines lists that are not empty.
UnsortedType UnsortedType::listUnion(UnsortedType list2)
{

	UnsortedType newList;
	
	resetList();

	do
	{
		newList.insertItem(getNextItem()); //Items from list1 are added to the new list
	} while (pos->next != nullptr);

	list2.resetList();

	do
	{
		if(search(list2.getNextItem()) == nullptr)
			newList.insertItem(list2.pos->item);  //Items from list2 are added to the new list without
	} while (list2.pos->next != nullptr);         //adding duplicates.
	
	return newList;
	
}