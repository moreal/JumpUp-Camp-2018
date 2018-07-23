#include <tuple>

class CoffeeMachine {
public:
	void drinkEspresso();
	void drinkAmericano();
	void drinkSugarCoffee();

	void show() const;
	void fill();

	CoffeeMachine();
	CoffeeMachine(int, int, int);

private:
	int coffee, water, sugar;

	const std::tuple<int, int, int>& ESPRESSO_MATERIAL = std::make_tuple(1, 1, 0);
	const std::tuple<int, int, int>& AMERICANO_MATERIAL = std::make_tuple(1, 2, 0);
	const std::tuple<int, int, int>& SUGARCOFFEE_MATERIAL = std::make_tuple(1, 2, 1);

	void drinkCoffee(const std::tuple<int, int, int>&);
};