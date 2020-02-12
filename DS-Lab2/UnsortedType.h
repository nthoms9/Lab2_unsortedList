/*
Nick Thoms
Data Structures 2020
Due: 2/1/2020
Lab 2: Unsorted List
Description: This class contains the attributes and methods of an unsorted list. There is a user defined type
             for the type of the info stored within the list called itemType. Each node of the list is of the
			 nodeType which is a struct that holds a itemType value and a next pointer which links nodes
			 together.
*/

#ifndef UNSORTEDTYPE_H
#define UNSORTEDTYPE_H

#include<string>
//#include"NodeType.h"

using namespace std;

typedef int itemType;

struct nodeType  // A struct that makes a the container for a node.
{
	itemType item;
	nodeType* next;
};

enum RelationType {LESS, GREATER, EQUAL};

class UnsortedType
{

public:

	//preconditions: The object has been declared in the client file.
	//postconditions: The object is created and default values are set to the attributes.
	UnsortedType();

	//preconditions: The constructor has been called and the object exists.
	//postconditions: The make empty function is called and memory is deallocated.
	~UnsortedType();

	//preconditions: There is a value to be inserted of itemType and the object has been created.
	//postconditions: Memory for a new node is allocated and the information is stored. A bool is returned
	//                to represent success.
	bool insertItem(itemType item_);
	
	//preconditions: A value is given to be deleted and the object has been created.
	//postconditions: Memory is deallocated and a node holding specific data is deleted. A bool is returned
	//                for success.
	bool deleteItem(itemType item_);

	//preconditions: The object has been created
	//postconditions: The position pointer is set to null.
	void resetList();

	//preconditions: The object has been created and items have been inserted into the list. 
	//postconditions: The position pointer is relocated to the next item on the list and an itemType value
	//                is returned.
	itemType getNextItem();

	//preconditions: The object has been created.
	//postconditions: A bool value is returned.
	bool isFull();

	//preconditions: The object has been created.
	//postconditions: An integer representing length of the list is returned.
	int getLength() { return length; };

	//preconditions: The object has been created.
	//postconditions: All memory in the list is deallocated and the postition is set back to null.
	bool makeEmpty();

	//preconditions: The object has been created and there is a value to be searched for.
	//Postconditions: A pointer of the item location is returned if the item is found or nullptr is returned
	//                if the item is not found.
	nodeType* search(itemType item_);

	//preconditions: The object has been created and there are two arguments of item type to be compared.
	//postconditions: Based on the relationship between the arguments a value of the relationType will be
	//                returned.
	RelationType comparedTo(itemType item1, itemType item2);
	
	//preconditions: Two objects of the UnsortedType have been created and have called the insertItems function.
	//postconditions: A third Unsorted type is created that contains unique elements from the two previous lists.
	UnsortedType listUnion( UnsortedType list2);

private:

	const int maxItems = 100000000;
	int length;
	nodeType* head;      //Head pointer that distinguishes front of the list.
	nodeType* pos;       //Position pointer that maneuvers through the list.

};

#endif
