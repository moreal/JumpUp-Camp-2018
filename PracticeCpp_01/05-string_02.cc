#include <iostream>
#include <string>

int main() {
	std::string input;

	std::cout << "Input String >> ";
	std::cin >> input;

	for (int i(1); i <= input.length(); ++i) {
		std::cout << input.substr(0, i) << '\n';
	}

	return 0;
}