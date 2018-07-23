#include <iostream>
#include <string>

int main() {
	std::string with_move = "Move Initailze";
	std::string with_constructor("Constructor");
	std::string nothing;

	// == operator overloading
	if (with_move == "Move Initailze") {
		std::cout << "Wow!!\n";
	}

	return 0;
}