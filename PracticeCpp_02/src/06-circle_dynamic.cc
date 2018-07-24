/*
    Copyright 2018 Moreal
*/

#include <iostream>

class Circle {
    int radius;
 public:
    Circle(int r) : radius(r) { std::cout << "생성자 실행 radius = " << r << '\n'; };
    ~Circle() { std::cout << "소멸자 실행 radius = " << radius << '\n'; }
    double getArea() { return 3.14*radius*radius; }
};

int main() {
    int input = 1;
    Circle* circle;
    while (input > 0) {
        std::cout << "정수 반지름 입력(음수이면 종료)>>";
        std::cin >> input;

        circle = new Circle(input);

        std::cout << "원의 면적은 " << circle->getArea() << '\n';

        delete circle;
    }

    return 0;
}