/**
 * @file exercise_5_1.cpp
 * @author Steven Aquino
 * @brief Write a program that requests the user to enter two integers. The
 * program should then calculate and report the sum of all the integers between
 * and including the two integers. At this point,assume that the smaller integer
 * is entered first. For example, if the user enters 2 and 9, the program
 * should report that the sum of all the integers from 2 through 9 is 44.
 * @version 0.1
 * @date 2022-06-03
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>

int main() {
    int first;
    int second;
    std::cout << "Enter two numbers: ";
    std::cin >> first >> second;

    // Assuming that the smaller integer is entered first.
    int sum = 0;
    for (int i = first; i <= second; i++) {
        sum += i;
    }

    std::cout << "The sum of all the integers from " << first << " through "
              << second << " is " << sum << "\n";

    return 0;
}