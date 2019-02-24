#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "Player.h"
#include <string>

#define MAX(x, y) ((x > y) ? x : y)
#define SQUARE(x) x*x


int square(int x) {
	return x * x;
}

int max(int a, int b) {
	return (a > b) ? a : b;
}

double max(double a, double b) {
	return (a > b) ? a : b;
}

char max(char a, char b) {
	return (a > b) ? a : b;
}

template<class T> // or template<typename T> 
T Max(T a, T b){
	return (a > b) ? a : b;
}

void printNameAndAge(std::string name, int age) {
	std::cout << "hello " << name << ". you are " << age << std::endl;
}

template<typename T1, typename T2>
void PrintNameAndAge(T1 name, T2 age) {
	std::cout << "hello " << name << ". you are " << age << std::endl;
}

template<class T>
void Swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

std::ostream& operator <<(std::ostream& stream, const Player& obj) {
	stream << obj.getName() << std::endl;
	return stream;
}


int main() {

	std::vector<int> numbers{ 0,5,1,9 };

	//sort
	std::cout << "\nsort the numbers in a ascending order in the vector" << std::endl;
	std::cout << "_____________________________________" << std::endl;
	std::sort(numbers.begin(), numbers.end());
	for (auto number : numbers)
		std::cout << number << std::endl;

	//reverse 
	std::cout << "\nreverse the numbers in the vector" << std::endl;
	std::cout << "_____________________________________" << std::endl;
	std::reverse(numbers.begin(), numbers.end());
	for (auto number : numbers)
		std::cout << number << std::endl;
	
	//accumulate 
	std::cout << "\naccumulate the numbers<int> in the vector" << std::endl;
	std::cout << "_____________________________________" << std::endl;
	std::cout << std::accumulate(numbers.begin(), numbers.end(), 0);

	//accumulate double 
	std::vector<double> doubleNumbers{ 0.1,5.2,1.5,9.9 };
	std::cout << "\naccumulate the numbers<double> in the vector" << std::endl;
	std::cout << "_____________________________________" << std::endl;
	std::cout << std::accumulate(doubleNumbers.begin(), doubleNumbers.end(), 0.0);//0.0


	//max function for int, double and char
	std::cout << "\nmax function for different signatures" << std::endl;
	std::cout << "_____________________________________" << std::endl;
	std::cout << max(5, 6) <<std::endl;
	std::cout << max(10.5, 25.2) << std::endl;
	std::cout << max('x', 'w') << std::endl;

	//improvement with macros
	//defined outside of main #define MAX(x,y) ((x>y)? x: y) 
	std::cout << "\n#defined MAX macro" << std::endl;
	std::cout << "_____________________________________" << std::endl;
	std::cout << MAX(5, 6) << std::endl;
	std::cout << MAX(10.5, 25.2) << std::endl;
	std::cout << MAX('x', 'w') << std::endl;
	
	//SQUARE macro
	std::cout << "\n#defined MAX SQUARE macro vs square function" << std::endl;
	std::cout << "_____________________________________" << std::endl;
	std::cout << 100 / SQUARE(5) <<std::endl;
	std::cout << 100 / square(5) << std::endl; 


	//testing the Max function with template<class T> additional type decleration 
	std::cout << "\nmax function for different signatures" << std::endl;
	std::cout << "_____________________________________" << std::endl;
	std::cout << Max<int>(5, 6) << std::endl;
	std::cout << Max<double>(10.5, 25.2) << std::endl;
	std::cout << Max<char>('x', 'w') << std::endl;

	//testing the Max function with template<class T> 
	std::cout << "\nmax function for different signatures" << std::endl;
	std::cout << "_____________________________________" << std::endl;
	std::cout << Max(5, 6) << std::endl;
	std::cout << Max(10.5, 25.2) << std::endl;
	std::cout << Max('x', 'w') << std::endl;

	std::cout << "\nCreate 2 players and compare them" << std::endl;
	std::cout << "_____________________________________" << std::endl;
	const Player Oogway("Oggway", 100, 9999);
	const Player Po("Po", 100, 911);
	std::cout << Max(Oogway, Po);
	//or same result
	std::cout << Max<Player>(Oogway, Po);


	//call print name function  
	std::cout << "\nCreate 2 players and cmopare them" << std::endl;
	std::cout << "_____________________________________" << std::endl;
	printNameAndAge("Shifu", 100); // limitted with string and int
	PrintNameAndAge<int, std::string>(7, "prime"); // type dependant

	PrintNameAndAge<double, std::string>(100.92, "double presision"); // PrintNameAndAge(100.92, "double presision") same output
	PrintNameAndAge<std::string, std::string>("milk", "protein"); //PrintNameAndAge("milk", "protein") same output


	//different way to compare objects
	std::cout << "\nCreate 2 players and compare them with another way" << std::endl;
	std::cout << "_____________________________________" << std::endl;
	Player compare = Max(Oogway, Po); //retunrs more experienced
	std::cout << compare.getName() << " is experienced." << std::endl;

	int a, b;
	std::cin >> a >> b;

	std::cout << Max(a, b);

	system("pause");
	return 0;
}
