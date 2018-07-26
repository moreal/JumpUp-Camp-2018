/*
    Copyright 2018 Moreal
*/

#include <iostream>
#include <string>

class Person {
    std::string name;

 public:
    explicit Person(std::string name = "") : name(name) { }
    inline std::string getName() const { return name; }
    inline void setName(const std::string& name) { this->name = name; }
};

class Family {
    Person* p;
    int size;
    std::string name;
 public:
    Family(std::string name, int size) :
        name(name), p(new Person[size]), size(size) { }

    void show();
    void setName(const int, const std::string&);

    ~Family();
};

Family::~Family() {
    delete p;
}

void Family::show() {
    std::cout << name << " Family is like below\n";
    for (int i(0); i < size; ++i) {
        std::cout << p[i].getName() << '\t';
    }
}

void Family::setName(const int index, const std::string& name) {
    p[index].setName(name);
}

void setName(int index, std::string name);
int main() {
    Family* simpson = new Family("Simpson", 3);
    simpson->setName(0, "Mr. Simpson");
    simpson->setName(1, "Mrs. Simpson");
    simpson->setName(2, "Bart Simpson");
    simpson->show();
    delete simpson;
    return 0;
}