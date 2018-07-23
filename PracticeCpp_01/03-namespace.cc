#include <iostream>

int main() {

	{
		// 1. using namespace
		using namespace std;
		cout << "Hello World!\n";
	}

	cout << "HIHI"; // this will occur compile error

	{
		// 2. using declaration
		using std::cout;
		cout << "Test";
	}
	return 0;
}