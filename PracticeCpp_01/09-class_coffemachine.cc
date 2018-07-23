#include "09-class_coffemachine.h"
#include <tuple>
#include <iostream>

CoffeeMachine::CoffeeMachine() {
	CoffeeMachine::CoffeeMachine(10,10,10);
}

CoffeeMachine::CoffeeMachine(int coffee, int water, int sugar) :
	coffee(coffee), water(water), sugar(sugar) {
	// PASS
}

void CoffeeMachine::show() const {
	std::cout << L"커피머신 상태, 커피:" << coffee
		<< L" 물:" << water << L" 설탕:" << sugar << '\n';
}

void CoffeeMachine::fill() {
	coffee = 10;
	water = 10;
	sugar = 10;
}

void CoffeeMachine::drinkAmericano() {
	drinkCoffee(AMERICANO_MATERIAL);
}

void CoffeeMachine::drinkEspresso() {
	drinkCoffee(ESPRESSO_MATERIAL);
}

void CoffeeMachine::drinkSugarCoffee() {
	drinkCoffee(SUGARCOFFEE_MATERIAL);
}

void CoffeeMachine::drinkCoffee(const std::tuple<int,int,int>& MATERIAL) {
	const auto&[coffee, water, sugar] = MATERIAL;
	this->coffee -= coffee;
	this->water -= water;
	this->sugar -= sugar;
}