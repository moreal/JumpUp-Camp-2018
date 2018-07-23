#include <mutex>

class Critter {
public:
	void Talk();
	void Eat();
	void Play();

	void PassTime();
	
	std::mutex mutex;

	Critter();

private:
	int m_Hunger, m_Boredom;

	void GetMood();
};