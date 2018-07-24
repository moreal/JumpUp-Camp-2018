/*
    Copyright 2018 Moreal
*/

#include <iostream>

class MyIntStack {
    int *arr;
    int size;
    int top;
 public:
    MyIntStack();
    explicit MyIntStack(const int& size);
    MyIntStack(const MyIntStack& T);
    ~MyIntStack();
    bool push(const int& n);
    bool pop(int &n);
};

MyIntStack::MyIntStack() : top(-1) {}

MyIntStack::MyIntStack(const int& size) : top(-1), size(size) {
    arr = new int[size];
}

MyIntStack::MyIntStack(const MyIntStack& T) : top(-1), size(T.size) {
    arr = new int[size];
    memcpy(arr, T.arr, size*sizeof(int));
}

MyIntStack::~MyIntStack() {
    delete[] arr;
}

bool MyIntStack::push(const int& n) {
    if (top == size-1)
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
    MyIntStack a(10);
    a.push(10);
    a.push(20);

    MyIntStack b = a;
    b.push(30);

    int n;
    a.pop(n);
    std::cout << "Stack a pop value " << n << '\n';
    b.pop(n);
    std::cout << "Stack b pop value " << n << '\n';

    return 0;
}