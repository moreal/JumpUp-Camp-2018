/*
    Copyright 2018 Moreal
*/

#include <iostream>

class MyIntStack {
    int arr[10];
    int top;  
 public:
    MyIntStack();
    bool push(const int& n);
    bool pop(int &n);
};

MyIntStack::MyIntStack() : top(-1) {}

bool MyIntStack::push(const int& n) {
    if (top == 9)
        return false;

    arr[++top] = n;
    return true;
}

bool MyIntStack::pop(int& n) {
    if (top == -1)
        return false;

    n = arr[top--];
    return true;
}

int main() {
    MyIntStack stack;
    for (int i(0); i < 11; ++i) {
        if (stack.push(i))
            std::cout << i << ' ';
        else
            std::cout << '\n' << i+1 << " stack is full..\n";
    }

    int n;

    for (int i(0); i < 11; ++i) {
        if (stack.pop(n))
            std::cout << n << ' ';
        else
            std::cout << '\n' << i+1 << " stack is empty..\n";
    }
    return 0;
}