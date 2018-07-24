#include <iostream>
#include <limits>

class Sample {
	int *p;
	int size;
public:
	Sample(const int n) : size(n), p(new int[n]) {}

	void read();
	void write();
	int big();
	~Sample();
};

void Sample::read() {
	for (int i(0); i < size; ++i) {
		std::cin >> p[i];
	}
}

void Sample::write() {
	for (int i(0); i < size; ++i) {
		std::cout << p[i];
	}
}

int Sample::big() {
	int top = INT_MIN;
	for (int i(0); i < size; ++i) {
		top = top > p[i] ? top : p[i];
	}
	return top;
}

Sample::~Sample() {
	delete p;
}

int main() {
	Sample s(10);
	s.read();
	s.write();
	std::cout << "가장 큰 수는 " << s.big() << std::endl;
}