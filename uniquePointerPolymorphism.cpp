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
	Cat() :Cat(0) {}

	void sound() override {
		std::cout << "my name is " << name << " and I say meow" << std::endl;
	}
};

class Dog :public Animal {
private:
	std::string id;

public:
	Dog(std::string id) : id{ id } {}
	Dog() :Dog(0) {}
public:
	void sound() override {
		std::cout << "my name is " << id << " and I say whoof" << std::endl;
	}
};

class Bird :public Animal {
private:
	std::string id;

public:
	Bird(std::string id) : id{ id } {}
	Bird() : Bird(0) {}
public:
	void sound() override {
		std::cout << "my name is " << id << " and I say tweet" << std::endl;
	}
};


int main() {

	//create vector for Animals1 vector to push back with make unique
	std::vector<std::unique_ptr<Animal>> Animals1;

	Animals1.push_back(std::make_unique<Cat>("fluffy"));
	Animals1.push_back(std::make_unique<Dog>("spike"));
	Animals1.push_back(std::make_unique<Bird>("dragon"));
	
	std::cout << "Animal 1 vector polymorpism" << std::endl;
	for (const auto &animal : Animals1) {
		animal->sound();
		//(*animal).sound();
	}

	//create vector for Animals2 vector to push back after creating the unique pointer
	std::vector<std::unique_ptr<Animal>> Animals2;

	std::unique_ptr<Animal> cat1 = std::make_unique<Cat>("twity");
	std::unique_ptr<Animal> dog1= std::make_unique<Dog>("marley");
	std::unique_ptr<Animal> bird1 = std::make_unique<Bird>("angry bird");

	Animals2.push_back(std::move(cat1));
	Animals2.push_back(std::move(dog1));
	Animals2.push_back(std::move(bird1));
	

	std::cout << "\n\nAnimal 2 vector polymorpism" << std::endl;
	for (const auto &animal : Animals2) {
		animal->sound();
		//(*animal).sound();
	}
	

	system("pause");
	return 0;
}
