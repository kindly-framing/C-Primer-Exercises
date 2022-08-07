/**
 * @file exercise_9_3.cpp
 * @author Steven Aquino
 * @brief Write a program that uses placement new to place an array of two such
 * structures in a buffer.Then assign values to the structure members
 * (remembering to use strcpy() for the char array) and use a loop to display
 * the contents. Option 1 is to use a static array, like that in Listing 9.10,
 * for the buffer. Option 2 is to use regular new to allocate the buffer.
 *
 * @version 0.1
 * @date 2022-07-07
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <cstring>
#include <iostream>
#include <new>

char buffer[50];

struct chaff {
    char dross[20];
    int slag;
};

int main()
{
    chaff *p1, *p2;

    return 0;
}