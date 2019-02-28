#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Node.h"
//git test!!

void menu() {
	std::cout << std::endl;
	std::cout << " 0 - clean screen " << std::endl;
	std::cout << " 1 - insert Node to front (left) " << std::endl;
	std::cout << " 2 - insert Node to back (right) " << std::endl;
	std::cout << " 3 - insert into middle after node " << std::endl;
	std::cout << " 4 - insert into middle before node " << std::endl;
	std::cout << " 5 - delete from middle after node " << std::endl;
	std::cout << " 6 - delete from middle before node " << std::endl;
	std::cout << " 7 - remove from front (left) " << std::endl;
	std::cout << " 8 - remove from back (right) " << std::endl;
	std::cout << " 9 - print list forward " << std::endl;
	std::cout << " 10 - print list backward " << std::endl;
	std::cout << " 11 - clear the list " << std::endl;
	std::cout << " 99 - exit " << std::endl;
	std::cout << " 911 - menu " << std::endl;
}

int main()
{
	LinkedList<int> myList;

	int choice;
	menu();
	do {
		std::cout << "\n? : ";
		std::cin >> choice;
		switch (choice)
		{
		case 0://clean the screen
			system("cls");
			break;
		case 1: 
			int data;
			std::cout << "Enter the data: ";
			std::cin >> data;
			myList.insertLeft(data);
			break;
		case 2:
			myList.insertRight(data); //not implemented
			break;
		case 3:
			myList.addMiddleAfterNode(data); //not implemented
			break;
		case 4:
			myList.addMiddleBeforeNode(data); //not implemented
			break;
		case 5: 
			myList.deleteMiddleAfterNode(data); //not implemented
			break;
		case 6: 
			myList.deleteMiddleBeforeNode(data); //not implemented
			break;
		case 7: 
			myList.removeFromLeft(data); //not implemented
			break;
		case 8: 
			myList.removeFromRight(data); //not implemented
			break;
		case 9: 
			myList.printList(); //not implemented
			break;
		case 10: 
			myList.printListBackward(); //not implemented
			break;
		case 11: 
			myList.clearTheList(); //not implemented
			break;
		case 99:
			exit;
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