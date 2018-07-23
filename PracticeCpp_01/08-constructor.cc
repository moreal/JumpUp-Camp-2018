#include "08-constructor.h"

Circle::Circle() {
	radius = 0;
}

Circle::Circle(const int& radius) : radius(radius) {
	// PASS
}

float Circle::getArea() const {
	return 3.14 * radius * radius;
}