/**
 * @file exercise_7.cpp
 * @author Steven Aquino
 * @brief Exercise 7 from C++ Primer Exercise 7
 * Write a program that asks the user to enter an hour value and a minute value.
 * The main() function should then pass these two values to a type void function
 * that displays the two values in the format shown in the following sample run:
 * Enter the number of hours: 9
 * Enter the number of minutes: 28
 * Time : 9:28
 * @version 0.1
 * @date 2022-05-20
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>

void displayTime(int hours, int minutes)
{
    std::cout << "Time : " << hours << ":" << minutes << "\n";
}

int main()
{
    std::cout << "Enter the number of hours: ";
    int hours;
    std::cin >> hours;

    std::cout << "Enter the number of minutes: ";
    int minutes;
    std::cin >> minutes;

    displayTime(hours, minutes);
}