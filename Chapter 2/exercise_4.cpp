/**
 * @file exercise_4.cpp
 * @author Steven Aquino
 * @brief Exercise 4 from C++ Primer Chapter 2
 * Write a program that asks the user to enter his or her age.The program then
 * should display the age in months:
 * Enter your age: 29
 * Your age in months is 384.
 * @version 0.1
 * @date 2022-05-20
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>

int ageToMonths(int age)
{
    // 1 age = 12 months
    return age * 12;
}

int main()
{
    std::cout << "Enter your age: ";
    int age;
    std::cin >> age;

    std::cout << "Your age in months: " << ageToMonths(age);
}