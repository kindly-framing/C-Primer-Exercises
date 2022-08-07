/**
 * @file exercise_5_3.cpp
 * @author Steven Aquino
 * @brief Write a program that asks the user to type in numbers. After each
 * entry, the program should report the cumulative sum of the entries to
 * date. The program should terminate when the user enters 0.
 * @version 0.1
 * @date 2022-06-03
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>

int main() {
    std::cout << "Enter numbers to find the cumulative sum of the entries: ";
    int n;
    std::cin >> n;

    int sum = 0;
    while (n != 0) {
        sum += n;
        std::cout << "Current sum: " << sum << "\n";
        std::cout << "Enter numbers or 0 to quit: ";
        std::cin >> n;
    }

    return 0;
}