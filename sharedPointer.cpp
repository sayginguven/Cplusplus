#include <iostream>
#include <iomanip>
#include <string>



int main() {


	//std::shared_ptr<int> ptr1 {new int{ 10 }}; // or 
	std::shared_ptr<int> ptr1 = std::make_shared<int>( 10 );


	std::cout << "shared pointer ptr1 pointing : " << *ptr1 << std::endl;

	std::cout << "how many pointers pointing to the ptr1's pointing data? : " << ptr1.use_count() << std::endl;

	//std::shared_ptr<int> ptr2 = ptr1; // or
	std::shared_ptr<int> ptr2{ ptr1 };
	
	//std::shared_ptr<int> ptr3;// not initilized smart pointers cause compile error


	*ptr2 = 20;
	std::cout << "shared pointer ptr2 pointing : " << *ptr2 << std::endl;
	std::cout << "how many pointers pointing to the ptr2's pointing data? : " << ptr2.use_count() << std::endl;
	std::cout << "how many pointers pointing to the ptr1's pointing data? : " << ptr1.use_count() << std::endl;

	std::shared_ptr<int> ptr3 = ptr1;
	std::cout << "how many pointers pointing to the ptr1's pointing data? : " << ptr3.use_count() << std::endl;

	ptr3.reset();
	std::cout << "how many pointers pointing to the ptr1's pointing data? after reseting one of them : " << ptr1.use_count() << std::endl;

	std::cout << "shared pointer ptr3 pointing : " << ptr3.use_count() << std::endl;

	std::cout << "shared pointers ptr1, ptr2 pointing : " << *ptr1 << ", " << *ptr2 << std::endl;
	//std::cout << "reset pointer ptr3 pointing to : " << *ptr3 << std::endl; // runtime error


	system("pause");
	return 0;
}
