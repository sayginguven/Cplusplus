#pragma once
#include <iostream>
#include "Node.h" 

template <class T>
class LinkedList {

private:
	Node<T> *startPtr;
	Node<T> *endPtr;
	Node<T> *getNewNode(const T &data);// allocate space in RAM

public:
	LinkedList();      
	~LinkedList();     
	void insertLeft(T &data);
	void insertRight(T &data);
	void addMiddleAfterNode(T &data);
	void addMiddleBeforeNode(T &data);
	void deleteMiddleAfterNode(T &data);
	void deleteMiddleBeforeNode(T &data);
	bool removeFromLeft();
	bool removeFromRight();
	bool isEmpty() const;
	void printList() const;
	void printListBackward() const;
	bool clearTheList();
}; 

template <class T>
LinkedList<T>::LinkedList()
	: startPtr(nullptr),
	endPtr(nullptr)
{

}

template <class T>
LinkedList<T>::~LinkedList()
{

} 

template <class T>
Node<T> *LinkedList<T>::getNewNode(const T &value)
{
	return new Node<T>(value);
}

template <class T>
void LinkedList<T>::insertLeft(T &value)
{
	Node<T> *newPtr = getNewNode(value);

	if (isEmpty()) {
		startPtr = endPtr = newPtr;
	} else {
		newPtr->nextPtr = startPtr;
		newPtr->prevPtr = nullptr;
		startPtr->prevPtr = newPtr;
		startPtr = newPtr;
	}
} 

template <class T>
void LinkedList<T>::insertRight(T &value)
{
	Node<T> *newPtr = getNewNode(value);

	if (isEmpty()) {
		startPtr = endPtr = newPtr;
	}
	else {
		newPtr->nextPtr = nullptr;
		newPtr->prevPtr = endPtr;
		endPtr->nextPtr = newPtr;
		endPtr = newPtr;
	}
} 

template <class T>
void LinkedList<T>::addMiddleAfterNode(T &data)
{
	
}

template <class T>
void LinkedList<T>::addMiddleBeforeNode(T &data)
{
}

template <class T>
void LinkedList<T>::deleteMiddleAfterNode(T &data)
{
}

template <class T>
void LinkedList<T>::deleteMiddleBeforeNode(T &data)
{
}

template <class T>
bool LinkedList<T>::removeFromLeft()
{
	if (isEmpty()) {
		printList();
		return false;
	}

	Node<T> *currentPtr = startPtr;

	if (startPtr->nextPtr == nullptr) {
		std::cout << currentPtr->getData() << " is deleted" << std::endl;
		delete currentPtr;
		startPtr = nullptr;
		endPtr = nullptr;
		printList();
		return true;
	} else {
		startPtr = currentPtr->nextPtr;
		startPtr->prevPtr = nullptr;
		std::cout << currentPtr->getData() << " is deleted" << std::endl;
		delete currentPtr;
		printList();
		return true;
	}
} 

template <class T>
bool LinkedList<T>::removeFromRight()
{
	if (isEmpty()) {
		printList();
		return false;
	}

	Node<T> *currentPtr = endPtr;

	if (endPtr->prevPtr == nullptr) {
		std::cout << currentPtr->getData() << " is deleted" << std::endl;
		delete currentPtr;
		startPtr = nullptr;
		endPtr = nullptr;
		printList();
		return true;
	}	else {
		endPtr = currentPtr->prevPtr;
		endPtr->nextPtr= nullptr;
		std::cout << currentPtr->getData() << " is deleted" << std::endl;
		delete currentPtr;
		printList();
		return true;
	}

} 

template <class T>
bool LinkedList<T>::isEmpty() const
{
	return startPtr == nullptr;
} 

template <class T>
void LinkedList<T>::printList() const
{
	if (isEmpty()) { 
		std::cout << "empty list" << std::endl; 
		return; 
	}

	Node<T> *currentPtr = startPtr;

	std::cout << " <- ";
	while (currentPtr != nullptr) {
		std::cout << "|" << currentPtr->data << "| -> " ;
		currentPtr = currentPtr->nextPtr;
	}

	std::cout << std::endl;
	
} 

template <class T>
void LinkedList<T>::printListBackward() const
{
	if (isEmpty()) { 
		std::cout << "empty list" << std::endl; 
		return;
	}

	Node<T> *currentPtr = endPtr;

	while (currentPtr != nullptr) {
		std::cout << " <- |" << currentPtr->data << "|";
		currentPtr = currentPtr->prevPtr;
	} 
	std::cout << " -> " << std::endl;
}

template <class T>
bool LinkedList<T>::clearTheList()
{
	return false;//not implemented
}