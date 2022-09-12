/**
 * @file exercise_2.cpp
 * @author Steven Aquino
 * @brief The operator+() function should create an object whose qcode and zcode
 * members concatenate the corresponding members of the operands. Provide code
 * that implements move semantics for the move constructor and the move
 * assignment operator. Write a program that uses all the methods. For testing
 * purposes, make the various methods verbose so that you can see when they are
 * used.
 *
 * @version 0.1
 * @date 2022-09-08
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "cpmv.h"
#include <iostream>
#include <string>

int main()
{
    Cpmv empty;
    Cpmv qz("q", "z");
    Cpmv copy(qz);
    Cpmv add(qz + copy);
    add = add + qz;
    add.Display();
    return 0;
}