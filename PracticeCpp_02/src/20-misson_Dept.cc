/*
    Copyright 2018 Moreal
*/

#include <iostream>
#include <string>

class Dept {
    int size;
    int* scores;
 public:
    explicit Dept(int size) : size(size), scores(new int[size]) { }
    // Dept(const Dept& T);
    ~Dept();
    int getSize() { return size; }
    void read();
    bool isOver60(const int&) const;
};

// Dept::Dept(const Dept& T) : size(T.size) {
//     scores = new int[size];
//     std::copy(T.scores, T.scores + size, scores);
// }

Dept::~Dept() {
    delete[] scores;
}

void Dept::read() {
    std::cout << "Input points " << size << " >> ";
    for (int i(0); i < size; ++i) {
        std::cin >> scores[i];
    }
}

bool Dept::isOver60(const int& index) const {
    return 60 < scores[index];
}

int countPass(Dept& const dept) {
    int count(0);
    for (int i(0); i < dept.getSize(); ++i) {
        if (dept.isOver60(i)) count++;
    }
    return count;
}

int main() {
    Dept com(10);
    com.read();

    // Copy Constructor Called here
    int n = countPass(com);
    std::cout << "people over 60 are " << n;
}