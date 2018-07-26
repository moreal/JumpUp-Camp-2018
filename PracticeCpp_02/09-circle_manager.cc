/*
    Copyright 2018 Moreal
*/

#include <iostream>
#include <string>

class Circle {
    int radius;
    std::string name;

 public:
    void setCircle(const std::string&, const int&);
    double getArea() const { return 3.14*radius*radius; }
    inline std::string getName() { return name; }
};

class CircleManager {
    Circle *p;
    int size;

 public:
    explicit CircleManager(int);
    ~CircleManager();
    void searchByName();
    void searchByArea();
};

void Circle::setCircle(const std::string& name, const int& radius) {
    this->name = name;
    this->radius = radius;
}

CircleManager::CircleManager(int size)
    : p(new Circle[size]), size(size)  {

    std::string name;
    int radius;

    for (int i(0); i < size; ++i) {
        std::cout << "Circle " << i+1 << "'s name and radius >> ";
        std::cin >> name >> radius;
        p[i].setCircle(name, radius);
    }
}

CircleManager::~CircleManager() {
    delete p;
}

void CircleManager::searchByName() {
    std::string name;
    std::cout << "Input Circle's name to search >> ";
    std::cin >> name;

    for (int i(0); i < size; ++i) {
        if (p[i].getName() == name) {
            std::cout << name << "'s area is " << p[i].getArea();
            break;
        }
    }

}

void CircleManager::searchByArea() {
    int area;
    std::cout << "Input the min area size as integer >> ";
    std::cin >> area;

    std::cout << "I'will find the circles are biggger than " << area << '\n';

    for (int i(0); i < size; ++i) {
        int size = p[i].getArea();
        if (size > area) {
            std::cout << p[i].getName() << "'s area is " << size << ',';
        }
    }
}

int main() {
    int size(0);
    std::cout << "Circle Count >> ";
    std::cin >> size;

    CircleManager manager(size);

    manager.searchByName();
    manager.searchByArea();

    return 0;
}