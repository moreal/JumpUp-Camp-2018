/*
    Copyright 2018 Moreal
*/

#include <iostream>
#include <string>

class BaseMemory {
    char *mem;

 public:
    char read(const int& index) { return mem[index]; }
    void write(const int& index, const char& val) { mem[index] = val; }
 
 protected:

    explicit BaseMemory(int size) : mem(new char[size]) {}

};

class ROM : public BaseMemory {
    void burn(const char*&, const int& len);
 public:
    ROM(const int, const char*, const int);
};

class RAM : public BaseMemory {
 public:
    explicit RAM(const int& size) : BaseMemory(size) {}
};

ROM::ROM(const int size, const char* data, const int len)
    : BaseMemory(size) {
    burn(data, len);
}

void ROM::burn(const char*& data, const int& len) {
    for (int i(0); i < len; ++i) {
       write(i, data[i]);
    }
}

int main() {
    char x[5] = {'h', 'e', 'l', 'l', 'o'};
    ROM biosROM(1024*10, x, 5);
    RAM mainMemory(1024*1024);

    for (int i(0); i < 5; ++i)
        mainMemory.write(i, biosROM.read(i));

    for (int i(0); i < 5; ++i)
        std::cout << mainMemory.read(i);

    return 0;
}