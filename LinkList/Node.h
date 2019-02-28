#pragma once
//add template for flexible linked list
class Node {
	
friend class LinkedList; //linked list can access Node class

private:
	int data;
	Node *nextPtr; 
	Node *prevPtr;

	//                  ______
	//				   |      |     
	//      prevPtr <--| data |-->nextPtr
	//                 |______|

public:
	Node();//default constructor signature
	Node(const int &data);  //overloaded constuctor signature
	int getData() const;  //getter signature

}; 

Node::Node() // default constructor implementation
	: Node(NULL) //delegated constructor
{
} 

Node::Node(const int &data) //overloaded constructor implementation
	: data(data),
	nextPtr(nullptr), prevPtr(nullptr)
{

} 

int Node::getData() const // getter implementation
{
	return data;
} 
