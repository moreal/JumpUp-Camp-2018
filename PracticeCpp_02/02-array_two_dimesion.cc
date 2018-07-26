#include <iostream>

class Circle {
	int radius;
public:
	Circle(int r = 1) : radius(r) {};
	double getArea() { std::cout << radius << '\n'; return 3.14*radius*radius; }
	void setRadius(int r) { radius = r; }
};

int main() {
	Circle circles[2][3]{ {1,2,3}, {4,5,6} };

	for (int i(0); i < 2; ++i)
		for (int j(0); j < 3; ++j)
			std::cout << "Circle [" << i << ',' << j << "]의 면적은 " << circles[i][j].getArea() << '\n';

	return 0;
}