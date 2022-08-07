/**
 * @file exercise_3.cpp
 * @author Steven Aquino
 * @brief Exercise 3 from C++ Primer Chapter 2
 * Write a C++ program that uses three user-defined functions (counting main()
 * as one) and produces the following output:
 * Three blind mice
 * Three blind mice
 * See how they run
 * See how they run
 * @version 0.1
 * @date 2022-05-20
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>

void printFirstSaying() { std::cout << "Three blind mice\n"; }

void printSecondSaying() { std::cout << "See how they run\n"; }

int main()
{
    printFirstSaying();
    printFirstSaying();
    printSecondSaying();
    printSecondSaying();
}