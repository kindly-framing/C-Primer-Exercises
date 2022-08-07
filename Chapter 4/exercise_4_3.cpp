/**
 * @file exercise_4_3.cpp
 * @author Steven Aquino
 * @brief Write a program that asks the user to enter his or her first name and
 * then last name,and that then constructs, stores,and displays a third string,
 * consisting of the user’s last name followed by a comma,a space,and first
 * name. Use char arrays and functions from the cstring header file. A sample
 * run could look like this:
 * Enter your first name: Flip
 * Enter your last name: Fleming
 * Here’s the information in a single string: Fleming, Flip
 * @version 0.1
 * @date 2022-05-22
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <cstring>
#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter your first name: ";
    char firstName[256];
    std::cin >> firstName;

    std::cout << "Enter your last name: ";
    char lastName[256];
    std::cin >> lastName;

    std::cout << "Here's the information in a single string: ";

    std::string res;
    res = lastName;
    res += ", ";
    res += firstName;
    std::cout << res << "\n";

    return 0;
}