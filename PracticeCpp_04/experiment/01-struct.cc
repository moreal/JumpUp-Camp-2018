/*
    Copyright 2018 Moreal
*/

#include <iostream>

struct A {
 public:
    friend void show(struct A&);

    int a;
    int b;
 private:
    int c;
};

void show(struct A& a) {
    std::cout << &a.a << ' ' << &a.b << ' ' << &a.c << '\n';
}

int main() {
    struct A a;
    struct A* b = new struct A;
    show(a);
    show(*b);
    return 0;
}