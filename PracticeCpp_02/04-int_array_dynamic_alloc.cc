#include <iostream>
#include <functional>

int main() {
	int cnt;
	std::cout << "입력할 정수의 개수는? ";
	std::cin >> cnt;

	int sum(0);
	int* arr = new int[cnt];

	for (int i(0); i < cnt; ++i) {
		std::cout << i << "번째 정수: ";
		std::cin >> arr[i];

		sum += arr[i];
	}

	std::cout << "평균 = " << sum / cnt;
	
	return 0;
}