/**
 * @file exercise_1.cpp
 * @author Provide the implementation for Cow class and write a short program
 * that uses all the member functions.
 *
 * @brief
 * @version 0.1
 * @date 2022-08-03
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "cow.h"
#include <iostream>

int main()
{
    // implement the constructors
    Cow empty;
    Cow bob("Bob", "Bowling", 250.0);
    Cow bob_cpy(bob);

    // implement ShowCow()
    empty.ShowCow();
    std::cout << '\n';
    bob.ShowCow();
    std::cout << '\n';
    bob_cpy.ShowCow();

    // implement operator=
    empty = bob_cpy;
    std::cout << "\nEmpty is now bob\n";
    empty.ShowCow();
    return 0;
}