/*
    Copyright 2018 Moreal
*/

#include <iostream>
#include <string>

class Point {
    int x, y;
 public:
    explicit Point(const int& x, const int& y) : x(x) , y(y) {}
    int getX() { return x; }
    int getY() { return y; }
 protected:
    void move(int, int);
};

void Point::move(int x, int y) {
    this->x = x;
    this->y = y;
}

class ColorPoint : Point {
    std::string color;
 public:
    explicit ColorPoint(
        const int& x = 0,
        const int& y = 0,
        const std::string& color = "BLACK") : Point(x, y), color(color) {}

    void setPoint(const int&, const int&);
    void setColor(const std::string&);
    void show();
};

void ColorPoint::setColor(const std::string& color) {
    this->color = color;
}

void ColorPoint::setPoint(const int& x, const int& y) {
    move(x, y);
}

void ColorPoint::show() {
    std::cout << "Color is " << color
        << " / (" << getX() << ',' << getY() << ")\n";
}

int main() {
    ColorPoint zeroPoint;
    zeroPoint.show();

    ColorPoint cp(5, 5);
    cp.setPoint(10, 20);
    cp.setColor("BLUE");
    cp.show();
    return 0;
}
