#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Node.h"
#include "variableTypes.h"

void menu() {
	std::cout << std::endl;
	std::cout << " 0 - clean screen " << std::endl;
	std::cout << " 1 - insert Node to front (left) " << std::endl;
	std::cout << " 2 - insert Node to back (right) " << std::endl;
	std::cout << " 3 - insert into middle after node " << std::endl;
	std::cout << " 4 - insert into middle before node " << std::endl;
	std::cout << " 5 - delete middle node " << std::endl;
	std::cout << " 6 - remove from front (left) " << std::endl;
	std::cout << " 7 - remove from back (right) " << std::endl;
	std::cout << " 8 - print list forward " << std::endl;
	std::cout << " 9 - print list backward " << std::endl;
	std::cout << " 10 - clear the list " << std::endl;
	std::cout << " 99 - exit " << std::endl;
	std::cout << " 911 - menu " << std::endl;
}

int main()
{
	LinkedList<VARTYPE> myList;
	VARTYPE data; // this comes from variableTypes.h
	
	int choice;
	menu();
	do {
		std::cout << "\n? : ";
		std::cin >> choice;
		switch (choice)
		{
		case 0://clean the screen for windows os
			system("cls");
			break;
		case 1: 
			
			std::cout << "Enter the data: ";
			std::cin >> data;
			myList.insertLeft(data);
			break;
		case 2:
			std::cout << "Enter the data: ";
			std::cin >> data;
			myList.insertRight(data);
			break;
		case 3:
			std::cout << "Enter the node data : ";
			std::cin >> data;
			myList.addMiddleAfterNode(data);
			break;
		case 4:
			std::cout << "Enter the node data : ";
			std::cin >> data;
			myList.addMiddleBeforeNode(data);
			break;
		case 5: 
			std::cout << "Enter the data for remove: ";
			std::cin >> data;
			myList.deleteMiddleNode(data); 
			break;
		case 6: 
			myList.removeFromLeft(); 
			break;
		case 7: 
			myList.removeFromRight(); 
			break;
		case 8: 
			myList.printList(); 
			break;
		case 9: 
			myList.printListBackward();
			break;
		case 10: 
			myList.clearTheList(); 
			break;
		case 99:
			break;
		case 911:
			menu();
			break;
		default:
			break;
		}
	} while (choice != 99);

	system("pause");
	return 0;
}