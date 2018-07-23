#include "10-pet_game-critter.h"

#include <iostream>
#include <thread>
#include <chrono>

// COMMAND HELP MESSAGE
const char* HELP_MESSAGE =
"\n"
"Critter Caretaker\n"
"\n"
"0. Quit\n"
"1. Listen to your critter\n"
"2. Feed your critter\n"
"3. Play with your critter\n"
"\n"
"Choice : ";

int main() {
	int command;
	Critter critter;

	// Time Sub Routine
	std::thread time_routine([&critter]() {
		using namespace std::chrono_literals;

		while (true) {
			// TODO: Study chrono
			std::this_thread::sleep_for(1ms);

			// critter mutex locking..
			while (!critter.mutex.try_lock());
			
			critter.PassTime();
			
			critter.mutex.unlock();
		}
	});

	time_routine.detach();

	// Game Main Loop
	while (true) {
		std::cout << HELP_MESSAGE;

		std::cin >> command;

		while (!critter.mutex.try_lock());

		switch (command)
		{
		case 0:
			std::puts("Good Bye~ My Master..");
			return 0;

		case 1:
			critter.Talk();
			break;

		case 2:
			critter.Eat();
			break;

		case 3:
			critter.Play();
			break;

		default:
			std::puts("[!] You inserted wrong data..");
			break;
		}

		critter.mutex.unlock();
	}
	
	return 0;
}