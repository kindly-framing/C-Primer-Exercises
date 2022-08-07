/**
 * @file exercise_7_5.cpp
 * @author Steven Aquino
 * @brief Define a recursive function that takes an integer argument and returns
 * the factorial of that argument. Recall that 3 factorial, written 3!, equals 3
 * ×2!,and so on, with 0! defined as 1. In general, if n is greater than zero,
 * n! = n * (n - 1)!.Test your function in a program that uses a loop to allow
 * the user to enter various values for which the program reports the factorial.
 * @version 0.1
 * @date 2022-06-22
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <string>

int factorial(int num)
{
    if (num == 0) {
        return 1;
    }
    return num * factorial(num - 1);
}

int main()
{
    std::cout << "Enter an integer to calculate the factorial or anything else "
                 "to quit: \n";

    std::string in;
    while (std::cin >> in) {
        int num;

        try {
            num = stoi(in);
        }
        catch (const std::invalid_argument &e) {
            std::cout << "Bye!\n";
            break;
        }

        std::cout << num << "! = " << factorial(num) << "\n";
    }

    return 0;
}