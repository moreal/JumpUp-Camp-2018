/*
    Copyright 2018 Moreal
*/

#include <iostream>
#include <string>

class Buffer {
    std::string text;
 public:
    explicit Buffer(std::string text) : text(text) {}
    void add(const std::string& next) { text += next; }
    void print() { std::cout << text << std::endl; }
};

Buffer& append(Buffer& buffer, const std::string& next) {
    buffer.add(next);
    return buffer;
}

int main() {
    Buffer buf("Hello");
    Buffer& temp = append(buf, "Guys");
    temp.print();
    buf.print();    
}