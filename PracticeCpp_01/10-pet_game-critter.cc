#include "10-pet_game-critter.h"

#include <iostream>

Critter::Critter() : m_Boredom(0), m_Hunger(0) {}

void Critter::Eat() {
	this->m_Hunger -= 5;
}

void Critter::Play() {
	this->m_Boredom -= 5;
}

void Critter::Talk() {
	GetMood();
}

void Critter::GetMood() {
	std::cout << "\n"
		"I'm a critter and I feel ";

	if (m_Hunger < 50 && m_Boredom < 50) {
		std::cout << "happy\n";
	}
	else if (m_Hunger > 90 || m_Boredom > 90) {
		std::cout << "dead\n";
	}
	else {
		std::cout << "bad\n";
	}

#ifdef __DEBUG__
	std::cout << "[+] Status is " << m_Hunger << " and " << m_Boredom << '\n';
#endif
}

void Critter::PassTime() {
	m_Hunger += 1;
	m_Boredom += 1;
}