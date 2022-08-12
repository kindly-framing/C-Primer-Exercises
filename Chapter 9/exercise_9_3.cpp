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
#include <new> // for placement new
const int BUF = 512;
const int N = 2;
char buffer[BUF]; // chunk of memory

struct chaff {
    char dross[20];
    int slag;
};

int main()
{
    using namespace std;
    chaff *pc;
    pc = new (buffer) chaff[N]; // using buffer array

    // assigning values
    for (int i = 0; i < N; i++) {
        strcpy(pc[i].dross, "Dross");
        pc[i].slag = i + 1;
    }

    // printing contents of array
    cout << "Chaffs:\n";
    for (int i = 0; i < N; i++) {
        cout << pc[i].dross << ' ' << pc[i].slag << endl;
    }

    delete[] pc;
    return 0;
}
