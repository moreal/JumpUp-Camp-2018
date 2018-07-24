/*
    Copyright 2018 Moreal
*/

class Circle {
    int radius;
 public:
    explicit Circle(int r) : radius(r) {}
    double getArea() { return 3.14*radius*radius; }
};

void swap(Circle& a, Circle& b) {
    auto tmp = a;
    a = b;
    b = a;
}

int main() {
    Circle a(1), b(2);
    swap(a, b);
    return 0;
}