#pragma once
#include <iostream>
#include "Node.h" 

class LinkedList {

private:
	Node *startPtr;
	Node *endPtr;
	Node *getNewNode(const int &data);// allocate space in RAM

public:
	LinkedList();      
	~LinkedList();     
	void insertLeft(int &data);
	void insertRight(int &data);
	void addMiddleAfterNode(int &data);
	void addMiddleBeforeNode(int &data);
	void deleteMiddleAfterNode(int &data);
	void deleteMiddleBeforeNode(int &data);
	bool removeFromLeft(int &data);
	bool removeFromRight(int &data);
	bool isEmpty() const;
	void printList() const;
	void printListBackward() const;
	bool clearTheList();
}; 

LinkedList::LinkedList()
	: startPtr(nullptr),
	endPtr(nullptr)
{

}

LinkedList::~LinkedList()
{

} 

Node *LinkedList::getNewNode(const int &value)
{
	return new Node(value);
}

void LinkedList::insertLeft(int &value)
{
	Node *newPtr = getNewNode(value);

	if (isEmpty()) {
		startPtr = endPtr = newPtr;
	} else {
		newPtr->nextPtr = startPtr;
		newPtr->prevPtr = nullptr;
		startPtr = newPtr;
	}

} 

void LinkedList::insertRight(int &value)
{
} 

void LinkedList::addMiddleAfterNode(int &data)
{
	
}

void LinkedList::addMiddleBeforeNode(int &data)
{
}

void LinkedList::deleteMiddleAfterNode(int &data) 
{
}

void LinkedList::deleteMiddleBeforeNode(int &data) 
{
}

bool LinkedList::removeFromLeft(int &value)
{
	return false;

} 

bool LinkedList::removeFromRight(int &value)
{
	return false;

} 

bool LinkedList::isEmpty() const
{
	return startPtr == nullptr;
} 

void LinkedList::printList() const
{
	Node *currentPtr = startPtr;

	while (currentPtr != nullptr) {
		std::cout << currentPtr->data << " -> ";
		currentPtr = currentPtr->nextPtr;
	} // end while
} 

void LinkedList::printListBackward() const
{
};

bool LinkedList::clearTheList() 
{
	return false;//not implemented
}