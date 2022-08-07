/**
 * @file exercise_7_1.cpp
 * @author Steven Aquino
 * @brief Write a program that repeatedly asks the user to enter pairs of
 * numbers until at least one of the pair is 0. For each pair, the program
 * should use a function to calculate the harmonic mean of the numbers.The
 * function should return the answer to main(), which should report the
 * result.The harmonic mean of the numbers is the inverse of the average of the
 * inverses and can be calculated as follows:
 * harmonic mean = 2.0 × x × y / (x + y)
 * @version 0.1
 * @date 2022-06-15
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>

double harmonic_mean(double n1, double n2)
{
    return (2.0 * n1 * n2) / (n1 + n2);
}

int main()
{
    std::cout << "Enter pair of numbers to find harmonic mean or 0 to quit\n";
    int num1;
    int num2;
    std::cin >> num1 >> num2;

    while (num1 != 0 && num2 != 0) {
        std::cout << "The harmonic mean for numbers entered are "
                  << harmonic_mean(num1, num2) << "\n";
        std::cin >> num1 >> num2;
    }

    std::cout << "Bye!\n";

    return 0;
}