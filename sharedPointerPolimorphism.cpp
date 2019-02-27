#include <iostream>
#include <iomanip>
#include <string>
#include <memory>
#include <vector>

class Animal { // abstract
public:
	// virtual void sound() -- virtual
	//virtual void sound() = 0 --pure virtual -- you must override the method in child class
	Animal() {}
	virtual void sound() = 0;
};

class Cat :public Animal {
private:
	std::string name;

public:
	Cat(std::string id) : name{ id } {}
	Cat() :Cat("") {}

	void sound() override {
		std::cout << "my name is " << name << " and I say meow" << std::endl;
	}
};

class Dog :public Animal {
private:
	std::string name;

public:
	Dog(std::string name) : name{ name } {}
	Dog() :Dog("") {}
public:
	void sound() override {
		std::cout << "my name is " << name << " and I say whoof" << std::endl;
	}

	void dogFunc() {
		std::cout << "I can chew anything I like" << std::endl;
	}
};

class Bird :public Animal {
private:
	std::string name;

public:
	Bird(std::string name) : name{ name } {}
	Bird() : Bird("") {}
public:
	void sound() override {
		std::cout << "my name is " << name << " and I say tweet" << std::endl;
	}
};



int main() {

	Animal * test = new Dog;
	std::cout << "casting for raw dog pointer " << std::endl;
	dynamic_cast<Dog*>(test)->dogFunc();

	std::vector<std::shared_ptr<Animal>> Animals;

	Animals.push_back(std::make_shared<Cat>("catty"));
	Animals.push_back(std::make_shared<Dog>("doggy"));
	Animals.push_back(std::make_shared<Bird>("birdy"));


	//thats ok to print without const and ref(&) to each element
	std::cout << "\n\nAnimals vector sound " << std::endl;
	for (auto animal : Animals) {
		animal->sound();
	}

	std::cout << "\n\ncasting for shared dog pointer " << std::endl;
	std::shared_ptr<Animal> doggy = std::make_shared<Dog>("goofy");
	std::dynamic_pointer_cast<Dog>(doggy)->dogFunc();


	system("pause");
	return 0;
}
