#include "06-class_circle.h"

void Circle::setRadius(const int& radius) {
	this->radius = radius;
}

float Circle::getArea() {
	return 3.14 * radius * radius;
}