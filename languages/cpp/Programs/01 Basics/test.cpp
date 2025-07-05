#include <iostream>

consteval int get_value() {
	return 3;
}

int main() {
	constexpr int value = get_value();
	std::cout << "Hello World!!" << value << std::endl;
	std::cout << "value : " << value << std::endl;
	return 0;
}