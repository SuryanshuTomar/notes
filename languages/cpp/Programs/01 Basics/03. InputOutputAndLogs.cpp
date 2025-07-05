#include <iostream>
#include <string>

int main() {
	int age;
	std::string name;

	std::cout << "Ebnter your name : " << std::endl;
	std::getline(std::cin, name);

	std::cout << "Enter you age : " << std::endl;
	std::cin >> age;

	std::cout << "Hi " << name << "!, your are " << age << " years old!" << std::endl;

	std::cerr << "This is an error message" << std::endl;

	std::clog << "This is a log message" << std::endl;

}