/*
    Copyright 2018 Moreal
*/

#include <iostream>

bool average(int arr[], int size, int& const avg) {
    if (size <= 0) {
        return false;
    } else {
        int sum(0);
        for (int i(0); i < size; ++i) {
            sum += arr[i];
        }
        avg = sum / size;
        return true;
    }
}

int main() {
    int arr[] = { 0, 1, 3, 4, 8, 11 };
    int avg;

    if (average(arr, 6, avg))
        std::cout << avg;
    else
        std::cout << "Args.. Error..";

    if (average(arr, -12, avg))
        std::cout << avg;
    else
        std::cout << "Args.. Error..";

    return 0;
}