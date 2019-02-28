#pragma once
//friend LinkedList declaration
template<class T> class LinkedList;

template <class T>
class Node {
	
friend class LinkedList<T>; //linked list can access Node class

private:
	T data;
	Node<T> *nextPtr; 
	Node<T> *prevPtr;

	//                  ______
	//				   |      |     
	//      prevPtr <--| data |-->nextPtr
	//                 |______|

public:
	Node();//default constructor signature
	Node(const T &data);  //overloaded constuctor signature
	T getData() const;  //getter signature

}; 

template <class T>
Node<T>::Node() // default constructor implementation
	: Node(NULL) //delegated constructor
{
} 

template <class T>
Node<T>::Node(const T &data) //overloaded constructor implementation
	: data(data),
	nextPtr(nullptr), prevPtr(nullptr)
{

} 

template <class T>
T Node<T>::getData() const // getter implementation
{
	return data;
} 
