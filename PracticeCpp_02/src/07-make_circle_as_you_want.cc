/*
    Copyright 2018 Moreal
*/

#include <iostream>

class Circle {
    int radius;
 public:
    double getArea() { return 3.14*radius*radius; }
    void setRadius(int r) { radius = r; }
};

int main() {
    int cnt;
    std::cout << "생성하고자 하는 원의 개수는? ";
    std::cin >> cnt;

    int sum(0);
    Circle* arr = new Circle[cnt];

    for (int i(0); i < cnt; ++i) {
        int r;
        std::cout << "원" << i << ':';
        std::cin >> r;

        arr[i].setRadius(r);
    }

    int circle_cnt(0);
    for (int i(0); i < cnt; ++i) {
        int size = arr[i].getArea();
        std::cout << size << ' ';
        if (100 < size && size < 200) circle_cnt += 1;
    }

    std::putchar('\n');

    std::cout << "면적이 100에서 200사이인 원의 개수는 " << circle_cnt;

    return 0;
}