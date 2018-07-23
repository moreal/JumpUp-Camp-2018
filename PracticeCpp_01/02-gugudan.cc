#include <iostream>

int main() {
	for (int i(1); i < 10; ++i) {
		for (int j(1); j < 10; ++j) {
			std::cout << j << 'x' << i << '=' << i * j << '\t';
		}
		std::putchar('\n');
	}
	return 0;
}