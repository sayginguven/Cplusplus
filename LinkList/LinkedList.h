#pragma once
#include <iostream>
#include "Node.h" 

template <class T>
class LinkedList {

private:
	Node<T> *startPtr;
	Node<T> *endPtr;
	Node<T> *getNewNode(const int &data);// allocate space in RAM

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
Node<T> *LinkedList<T>::getNewNode(const int &value)
{
	return new Node<T>(value);
}

template <class T>
void LinkedList<T>::insertLeft(int &value)
{
	Node<T> *newPtr = getNewNode(value);

	if (isEmpty()) {
		startPtr = endPtr = newPtr;
	} else {
		newPtr->nextPtr = startPtr;
		newPtr->prevPtr = nullptr;
		startPtr = newPtr;
	}

} 

template <class T>
void LinkedList<T>::insertRight(int &value)
{
} 

template <class T>
void LinkedList<T>::addMiddleAfterNode(int &data)
{
	
}

template <class T>
void LinkedList<T>::addMiddleBeforeNode(int &data)
{
}

template <class T>
void LinkedList<T>::deleteMiddleAfterNode(int &data)
{
}

template <class T>
void LinkedList<T>::deleteMiddleBeforeNode(int &data)
{
}

template <class T>
bool LinkedList<T>::removeFromLeft(int &value)
{
	return false;

} 

template <class T>
bool LinkedList<T>::removeFromRight(int &value)
{
	return false;

} 

template <class T>
bool LinkedList<T>::isEmpty() const
{
	return startPtr == nullptr;
} 

template <class T>
void LinkedList<T>::printList() const
{
	if (isEmpty()) { std::cout << "empty list" << std::endl; }

	Node<T> *currentPtr = startPtr;

	while (currentPtr != nullptr) {
		std::cout << currentPtr->data << " -> ";
		currentPtr = currentPtr->nextPtr;
	} // end while
} 

template <class T>
void LinkedList<T>::printListBackward() const
{
};

template <class T>
bool LinkedList<T>::clearTheList()
{
	return false;//not implemented
}