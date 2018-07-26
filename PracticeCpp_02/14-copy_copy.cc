/*
    Copyright 2018 Moreal
*/

#include <iostream>
#include <cstring>

class Person {
    int id;
    char* name = nullptr;
 public:
    Person(int, char*);
    Person(const Person&);
    ~Person() { delete name; }
    void changeName(char*);
    void show() { std::cout << id << ',' << name << '\n'; }
};

Person::Person(int id, char* name) : id(id) {
    int len = strlen(name);
    this->name = new char[len+1];
    std::strncpy(this->name, name, len);
}

// For Deep Copy :: Copy Constructor
Person::Person(const Person& T) {
    int len = std::strlen(T.name);
    id = T.id;
    name = new char[len+1];
    std::strncpy(name, T.name, len);
}

void Person::changeName(char* name) {
    if (this->name != nullptr)
        delete this->name;

    int len = std::strlen(name);
    this->name = new char[len+1];

    std::strncpy(this->name, name, len);
}

// 여기 부터는 못봐서 마음 대로 짯..
int main() {
    Person amd(123, "AMD"), intel(amd);

    amd.show();
    intel.show();

    intel.changeName("INTEL");

    // std::cout << (int)(amd.name) << ' ' << (int)(intel.name) << '\n';

    amd.show();
    intel.show();

    return 0;
}