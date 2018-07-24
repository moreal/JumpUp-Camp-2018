/*
    Copyright 2018 Moreal
*/

#include <iostream>


void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int a = 7, b = 9;
    swap(a, b);
    std::cout << a << ' ' << b;
    return 0;
}