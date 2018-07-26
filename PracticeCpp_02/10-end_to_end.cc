/*
    Copyright 2018 Moreal
*/

#include <iostream>
#include <string>

class Player {
    std::string name;
 public:
    void setName(const std::string& name) { this->name = name; }
    inline const std::string getName() const { return name; }
};

class WordGame {
    Player *m_Players;
    int m_Size;

 public:
    void Configure();
    void Start();
    ~WordGame() { delete m_Players; }
};

void WordGame::Configure() {
    std::puts("Game will be started");
    std::cout << "Input players counts >> ";

    int size;
    std::cin >> size;

    m_Size = size;
    m_Players = new Player[size];

    std::string name;
    for (int i(0); i < size; ++i) {
        std::cout << "Input player name without empty character >> ";
        std::cin >> name;

        m_Players[i].setName(name);
    }
}

void WordGame::Start() {
    std::string before, now;
    before = "아버지";

    std::cout << "Start Word is " << before << '\n';

    int cursor = 0;
    while (true) {
        // Turn Start Process - Input word
        std::cout << m_Players[cursor].getName() << ">>";

        std::cin >> now;

        if (now.substr(0, 2) != before.substr(before.length() - 2, 2)) {
            break;
        }

        // Turn End Process
        before = now;
        cursor = (cursor + 1) % m_Size;
    }

    std::cout << "Game End..";
}

int main() {
    WordGame game;
    game.Configure();
    game.Start();
}