/**
 * @file exercise_4_10.cpp
 * @author Steven Aquino
 * @brief Write a program that requests the user to enter three times for the
 * 40-yd dash (or 40-meter, if you prefer) and then displays the times and the
 * average. Use an array object to hold the data. (Use a built-in array if array
 * is not available.)
 * @version 0.1
 * @date 2022-05-25
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>

double average(double *arr, int size) {
    double sum;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

int main() {
    const int amountOfTimes = 3;
    double dashTimes[amountOfTimes];

    std::cout << "Please enter the first time: ";
    std::cin >> dashTimes[0];

    std::cout << "Please enter the second time: ";
    std::cin >> dashTimes[1];

    std::cout << "Please enter the third time: ";
    std::cin >> dashTimes[2];

    std::cout << average(dashTimes, amountOfTimes) << "\n";

    return 0;
}