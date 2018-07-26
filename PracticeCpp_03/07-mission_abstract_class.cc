/*
    Copyright 2018 Moreal
*/

#include <iostream>
using namespace std;

class Comparable {
 public:
    virtual bool operator>(Comparable& op2) = 0;
    virtual bool operator<(Comparable& op2) = 0;
    virtual bool operator==(Comparable& op2) = 0;
};

class Circle : public Comparable {
    int radius;
 public:
    explicit Circle(int radius = 1) : radius(radius) { }
    int getRadius() { return radius; }
    bool operator >(Comparable& op2);
    bool operator <(Comparable& op2);
    bool operator ==(Comparable& op2);
};

class Rect : public Comparable {
    int side;
 public:
    explicit Rect(int side = 1) : side(side) { }
    int getSize() { return side*side; }
    bool operator >(Comparable& op2) { return this->getSize() > ((Rect&)op2).getSize(); }
    bool operator <(Comparable& op2) { return this->getSize() < ((Rect&)op2).getSize(); }
    bool operator ==(Comparable& op2) { return this->getSize() == ((Rect&)op2).getSize(); }
};

bool Circle::operator >(Comparable& op2) {
    std::cout << "Test\n";
    Circle* circle = dynamic_cast<Circle*>(&op2);
    std::cout << std::hex << reinterpret_cast<intptr_t>(circle) << '\n';
    if (circle && this->getRadius() > ((Circle&)op2).getRadius()) return true;
    else
        return false;
}

bool Circle::operator <(Comparable& op2) {
    if (this->getRadius() < ((Circle&)op2).getRadius())
        return true;
    else
        return false;
}

bool Circle::operator ==(Comparable& op2) {
    if (this->getRadius() == ((Circle&)op2).getRadius())
        return true;
    else
        return false;
}

template <class T>
T bigger(T a, T b) {
    if (a > b)
        return a;
    else
        return b;
}


//Circle bigger(Circle a, Circle b) {
//	if (a.getRadius() > b.getRadius()) return a;
//	else return b;
//}

// 바른 풀이 dynamic_cast로 형변환 가능 검사 후 진행한다
// C++ 표준에는 저런 모습을 볼 수 없다. C++은 자바가 아니다
// https://stackoverflow.com/questions/27098650/how-to-make-comparable-class-in-c

int main() {
    int a = 20, b = 50, c;
    c = bigger(a, b);
    cout << "20 with 50, biggest is " << c << endl;
    Circle waffle(10), pizza(20), y;
    y = bigger(waffle, pizza);

    Rect rect(10);

    cout << "biggest radius is " << y.getRadius() << endl;
}