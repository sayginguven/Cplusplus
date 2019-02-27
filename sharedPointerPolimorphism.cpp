#include <iostream>
#include <iomanip>
#include <string>
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
	int id;

public:
	Cat(int id) : id{ id } {}
	Cat() :Cat(0) {}

	void sound() override {
		std::cout << "my id is " << id << " and I say meow" << std::endl;
	}
};

class Dog :public Animal {
private:
	int id;

public:
	Dog(int id) : id{ id } {}
	Dog() :Dog(0) {}
public:
	void sound() override {
		std::cout << "my id is " << id << " and I say whoof" << std::endl;
	}
};

class Bird :public Animal {
private:
	int id;

public:
	Bird(int id) : id{ id } {}
	Bird() : Bird(0) {}
public:
	void sound() override {
		std::cout << "my id is " << id << " and I say tweet" << std::endl;
	}
};


int main() {

	std::vector<std::shared_ptr<Animal>> Animals;

	Animals.push_back(std::make_shared<Cat>(1));
	Animals.push_back(std::make_shared<Dog>(2));
	Animals.push_back(std::make_shared<Bird>(3));


	//thats ok to print without const and ref(&) to each element
	for (auto animal : Animals) {
		animal->sound();
	}


	system("pause");
	return 0;
}
