/**
 * @file exercise_9_1.cpp
 * @author Steven Aquino
 * @brief Put together a multifile program based on this header. One file, named
 * golf.cpp, should provide suitable function definitions to match the
 * prototypes in the header file.A second file should contain main() and
 * demonstrate all the features of the prototyped functions. For example,a loop
 * should solicit input for an array of golf structures and terminate when the
 * array is full or the user enters an empty string for the golfer’s name.The
 * main() function should use only the prototyped functions to access the golf
 * structures.
 *
 * @version 0.1
 * @date 2022-07-06
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "exercise_9_1.h"

#include <cstring>
#include <iostream>

int main()
{
    const int len = 3;

    // Using interactive version
    Golf arr[len];
    for (int i = 0; i < len; i++) {
        if (!setgolf(arr[i])) {
            break;
        }
    }
    for (int i = 0; i < len; i++) {
        if (arr[i].fullname[0] == '\0') {
            break;
        }
        showgolf(arr[i]);
    }

    // Using non-interactive version
    Golf arr2[len];
    for (int i = 0; i < len; i++) {
        char name[Len];
        std::cin.getline(name, Len);

        if (name[0] == '\0') {
            setgolf(arr2[i], name, 0);
        }
        else {
            int handicap;
            std::cin >> handicap;
            std::cin.ignore();
            setgolf(arr2[i], name, handicap);
        }
    }
    for (int i = 0; i < len; i++) {
        showgolf(arr2[i]);
    }

    return 0;
}

void setgolf(Golf& g, const char* name, int hc)
{
    strcpy(g.fullname, name);
    g.handicap = hc;
}

int setgolf(Golf& g)
{
    char name[Len];
    std::cin.getline(name, Len);
    strcpy(g.fullname, name);
    if (name[0] == '\0') {
        return 0;
    }

    std::cin >> g.handicap;
    std::cin.ignore();
    return 1;
}

void handicap(Golf& g, int hc) { g.handicap = hc; }

void showgolf(const Golf& g)
{
    if (g.fullname[0] != '\0') {
        for (int i = 0; i < Len; i++) {
            if (g.fullname[i] == '\0') {
                break;
            }
            std::cout << g.fullname[i];
        }
        std::cout << "\n";

        std::cout << g.handicap << "\n";
    }
}