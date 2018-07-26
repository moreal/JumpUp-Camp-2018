/*
    Copyright 2018 Moreal
*/

#include <iostream>
#include <string>

class Circle {
 protected:
    int radius;
 public:
    explicit Circle(const int& radius = 0) : radius(radius) {}
    int getRadius() { return radius; }
    void setRadius(int radius) { this->radius = radius; }
    double getArea() { return 3.14*radius*radius; }
};

class NamedCircle : public Circle {
    std::string name;
 public:
    explicit NamedCircle(
        const int& radius = 0,
        const std::string& name = "My Name")
        : Circle(radius), name(name) {}

    std::string getName() const { return name; }
    void setName(const std::string& name) { this->name = name; }
};

int main() {
    NamedCircle pizza[5];

    int radius;
    std::string name;

    int index = 0;

    for (int i(0); i < 5; ++i) {
        std::cout << i+1 << ">>";
        std::cin >> radius >> name;

        pizza[i].setRadius(radius);
        pizza[i].setName(name);

        if (pizza[index].getArea() < pizza[i].getArea())
            index = i;
    }

    std::cout << "Biggest pizza is " << pizza[index].getName();
    return 0;
}

