#include <iostream>
#include <string>

class negativeException :public std::exception{
public:
	negativeException() noexcept = default;
	~negativeException() = default;
	virtual char const* what() const noexcept {
		return "I have no idea how can you think that I am able to divide something negative.";
	}
};

class divideByZero: public  std::exception{
public:
	divideByZero() noexcept = default;
	~divideByZero() = default;
	virtual char const* what() const noexcept{
		return "dividing by zero, really?, be smart. please";
	}
};
//f1
//double calculatePayment(int loan, int months) {
//	return static_cast<double>(loan) / months;
//}


//f2
//double calculatePayment(int loan, int months) {
//	if (months == 0) {
//		throw 0;
//	}
//	return static_cast<double>(loan) / months;
//}

//f3
//double calculatePayment(int loan, int months) {
//	if (months == 0) {
//		throw 0;
//	}
//	if (loan < 0 || months < 0) {
//		throw std::string{ "Error: negative value" };
//	}
//	return static_cast<double>(loan) / months;
//}

//function series 
//void func1();
//void func2();
//void func3();
//
//void func1() {
//	std::cout << "function 1 starts" << std::endl;
//	func2();
//	std::cout << "function 1 ends" << std::endl;
//}
//
//void func2() {
//	std::cout << "function 2 starts" << std::endl;
//	try {
//		func3();
//	}
//	catch (std::string &exception) {
//		std::cerr << "Error! in func2()" << std::endl;
//	}
//	std::cout << "function 2 ends" << std::endl;
//}
//
//void func3() {
//	std::cout << "function 3 starts" << std::endl;
//	throw std::string{ "Error!" };
//	std::cout << "function 3 ends" << std::endl;
//}

double calculatePayment(int loan, int months) {
	if (months == 0) {
		throw divideByZero{};
	}
	if (loan < 0 || months < 0) {
		throw negativeException{};
	}
	return static_cast<double>(loan) / months;
}

int main()
{
	int studentLoan;
	int howManyMonths;
	double result{};

	std::cout << "how much is your student loan? ";
	std::cin >>  studentLoan;

	std::cout << "In how many months you are going to pay? ";
	std::cin >> howManyMonths;

	//1
	//result = studentLoan / howManyMonths;
	//std::cout << "your monthly payment is : " << result << std::endl;


	//2
	//result = static_cast<double>(studentLoan) / howManyMonths;
	//std::cout << "your monthly payment is : " << result << std::endl;


	//3
	//if (howManyMonths != 0) {
	//	result = static_cast<double>(studentLoan) / howManyMonths;
	//	std::cout << "your monthly payment is : " << result << std::endl;
	//} else {
	//	std::cerr << "Error: Cant divide by zero" << std::endl;
	//}

	//4
	//try {
	//	if (howManyMonths == 0)
	//		throw 0;
	//	result = static_cast<double>(studentLoan) / howManyMonths;
	//	std::cout << "your monthly payment is : " << result << std::endl;
	//}
	//catch (int &exception) { // exception is 0 because try throw 0
	//	std::cerr << "Error: Cant divide by zero" << std::endl;
	//}


	//f2 1
	//result = calculatePayment(studentLoan, howManyMonths);
	//std::cout << "your monthly payment is : " << result << std::endl;



	//f2 2
	//try
	//{
	//	result = calculatePayment(studentLoan, howManyMonths);
	//	std::cout << "your monthly payment is : " << result << std::endl;
	//}
	//catch (int &exception)
	//{
	//	std::cerr << "Error: Cant divide by zero" << std::endl;
	//}


	//f3 1
	//try
	//{
	//	result = calculatePayment(studentLoan, howManyMonths);
	//	std::cout << "your monthly payment is : " << result << std::endl;
	//}
	//catch (int &exception)
	//{
	//	std::cerr << "Error: Cant divide by zero" << std::endl;
	//}



	//f3 2
	//try
	//{
	//	result = calculatePayment(studentLoan, howManyMonths);
	//	std::cout << "your monthly payment is : " << result << std::endl;
	//}
	//catch (int &exception)
	//{
	//	std::cerr << "Error: Cant divide by zero" << std::endl;
	//}
	//catch (std::string &exception)
	//{
	//	std::cerr << exception << std::endl;
	//}


	//f3 3
	//try
	//{
	//	result = calculatePayment(studentLoan, howManyMonths);
	//	std::cout << "your monthly payment is : " << result << std::endl;
	//}
	//catch (...)
	//{
	//	std::cerr << "Something went wrong but I dont know what. maybe its you. Its always you." << std::endl;
	//}

	
	try
	{
		result = calculatePayment(studentLoan, howManyMonths);
		std::cout << "your monthly payment is : " << result << std::endl;
	}
	catch (divideByZero &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	catch (negativeException &exception)
	{
		std::cerr << exception.what() << std::endl;
	}



	system("pause");
	return 0;
}
