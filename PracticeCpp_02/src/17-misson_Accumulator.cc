/*
    Copyright 2018 Moreal
*/

#include <iostream>

class Accumulator {
    int value;
 public:
    explicit Accumulator(const int& value) : value(value) {}
    Accumulator& add(const int& n);
    inline int get() { return value; }
};

Accumulator& Accumulator::add(const int& n) {
    value += n;
    return *this;
}

int main() {
    Accumulator acc(10);
    acc.add(5).add(6).add(7);
    std::cout << acc.get();
}