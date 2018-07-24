/*
    Copyright 2018 Moreal
*/

#include <iostream>
#include <string>

class Book {
    std::string title;
    int price;
 public:
    explicit Book(const std::string& title, const int& price);
    void set(const std::string& title, const int& price);
    void show() const;
};

Book::Book(const std::string& title, const int& price)
    : title(title), price(price) {}




void Book::set(const std::string& title, const int& price) {
    this->title = title;
    this->price = price;
}

void Book::show() const {
    std::cout << title << ' ' << price << "won" << std::endl;
}

int main() {
    Book cpp("BeautyC++", 10000);
    Book java = cpp;
    java.set("BeautyJava", 12000);
    cpp.show();
    java.show();
}