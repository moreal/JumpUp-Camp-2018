#include <iostream>

class Circle {
	int radius;
public:
	Circle(int r) : radius(r) {};
	double getArea() { return 3.14*radius*radius; }
};

int main() {
	Circle circleArray[3]{ 1,2,3 };

	for (auto& circle : circleArray) {
		std::cout << circle.getArea() << '\n';
	}
	return 0;
}