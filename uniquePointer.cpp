#include <iostream>
#include <string>


template<class T>
class Icecream {
private:
	T flavor;
public:
	Icecream() {}
	Icecream(T flavor) 
		:flavor{ flavor }{
		std::cout << "created icecream with " << flavor << " flavor!"<<std::endl;
	}
	Icecream(const Icecream &obj) 
		: flavor{ obj.flavor }
	{
	}
	~Icecream() {
		std::cout << "destroyed with " << flavor << " flavor is destroyed! :("  << std::endl;
	}
	T getName() {
		return flavor;
	}

};



int main() {

	//raw pointers should be deleted
	Icecream<std::string> *iptr = new Icecream<std::string>( "mapple and nuts" );
	delete iptr;

	//no delete required
	Icecream<std::string>* ice1 = new Icecream<std::string>{ "chocolate" };
	std::unique_ptr<Icecream<std::string>> ice2= std::make_unique<Icecream<std::string>>( "london fog" );
	std::unique_ptr<Icecream<std::string>> ice3; 

	//ice3 = ice2; // unique poiters can not be assigned to another pointer
	ice3 = std::move(ice2); // however, we can move them

	//std::cout << ice2->getName(); // runtime error ice2 is null
	if (ice2 == nullptr) { std::cout << "ice2 is nullptr" << std::endl; }


	system("pause");
	return 0;
}
