#include <iostream>

int main() {
	int *p = new int(6);
	std::cout << p << '\n';
	delete p;
	std::cout << p << '\n';
	delete p;

	// There is not error..
	return 0;
}