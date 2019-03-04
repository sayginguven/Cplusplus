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
	void deleteMiddleNode(T &data);
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
void LinkedList<T>::deleteMiddleNode(T &data)
{

	Node<T> *currentPtr = startPtr;
	
	while (currentPtr != nullptr) {
		if (currentPtr->data == data) {
			std::cout << "found it! deleting..." << std::endl;

			if (startPtr == endPtr) { // one node only
				removeFromLeft();
			} else if (startPtr == currentPtr && startPtr != endPtr) { // node at the start position
				removeFromLeft();
			}else if(endPtr == currentPtr && startPtr != endPtr) { // node at the end position
				removeFromRight();
			} else { // node in the middle
				currentPtr->prevPtr->nextPtr = currentPtr->nextPtr;
				currentPtr->nextPtr->prevPtr = currentPtr->prevPtr;
				currentPtr->nextPtr = nullptr;
				currentPtr->prevPtr = nullptr;
				delete currentPtr;
				printList();
			}

			return;
		}else {
			currentPtr = currentPtr->nextPtr;
		}
	}
	
	std::cout << "not found it. mission abort!" << std::endl;
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

	delete currentPtr;
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
	delete currentPtr;
	std::cout << " -> " << std::endl;
}

template <class T>
bool LinkedList<T>::clearTheList()
{
	if (isEmpty()) {
		printList();
		return false;
	}

	while (!isEmpty()) {
		//remove from right without prompt message

		Node<T> *currentPtr = endPtr;

		if (endPtr->prevPtr == nullptr) {
			delete currentPtr;
			startPtr = nullptr;
			endPtr = nullptr;
		}
		else {
			endPtr = currentPtr->prevPtr;
			endPtr->nextPtr = nullptr;
			delete currentPtr;
		}
	}

	delete currentPtr;
	printList();
	return true;
}