#include <iostream>
#include <string>
#include <functional>
#include <sstream>
#include <chrono>
#include <thread>

std::function<void()> func() {

	int i = 0;

	return [i]() mutable {
		std::cout << "lambda function, i : " << i << std::endl;
		i += 1;
	};
}

template< class Rep, class Period>
void countDown(std::string message, const std::chrono::duration<Rep, Period>& sleep_duration) {
	for (char c : message) {
		std::cout << c;
		std::this_thread::sleep_for(sleep_duration);
	}
}

int main()
{

	/*auto closureFunc = func();

	closureFunc();*/
	using namespace std::literals::chrono_literals;


	std::string str = "Hi guys,\n\n";
	str += "As I promised yesterday, ";
	str += "I prepared a closure example.\n";
	str += "There was a stupid!!\b\b\b\b\b\b\b\blogical mistake in the previous code.\n";
	str += "Anyhow, yesterday night it took couple minutes to found out my mistake.\n\n";
	str += "After that I decided to write the code in a creative way.\n";
	str += "I hope you will like it.\n\n";
	countDown(str, 0.01s);

	str = "";
	str += "                 __ \n";
	str += "                / _)\n";
	str += "       _.----._/ /  \n";
	str += "      /         /	  \n";
	str += "   __/   ( |  ( |	  \n";
	str += "  /__.-''|_|--|_|	  Lets Code!\n\n\n";

	countDown(str, 0.01s);

	str = "We are preparing the code for you.\n\n";
	str += "It will take couple seconds to load the code! Thank you for your patience\n\n";
	str += "Almost there.\n";
	countDown(str, 0.01s);

	str = "";
	for (int i = 10; i > 0; i -= 1) {
		str += '.';
	}
	std::cout << "Loading";
	countDown(str, .1s);

	system("cls");


	str = "#include <iostream>\n";
	str += "#include <string>\n";
	str += "#include <functional>\n\n\n";
	str += "std::function<void()> func() {\n";
	str += "   int i = 0;\n";
	str += "   return [i]() mutable{\n";
	str += "     std::cout << \"lambda function, i : \" << i << std::endl;\n";
	str += "     i += 1;\n";
	str += "   };\n";
	str += "}\n\n\n\n";
	str += "int main(){\n\n";
	str += "   auto closureFunc = func(); //dont forget to add paranteses after func\n";
	str += "   closureFunc();\n\n\n";
	str += "   system(\"pause\")\n";
	str += "   return 0;\n";
	str += "}\n";

	countDown(str, 0.03s);


	std::cin >> str;
	system("pause");
	return 0;
}
