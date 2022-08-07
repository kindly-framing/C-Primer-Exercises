/**
 * @file exercise_10_3.cpp
 * @author Steven Aquino
 * @brief Do Programming Exercise 1 from Chapter 9 but replace the code shown
 * there with an appropriate golf class declaration. Replace setgolf(golf &,
 * const char*, int) with a constructor with the appropriate argument for
 * providing initial values. Retain the interactive version of setgolf() but
 * implement it by using the constructor. (For example, for the code for
 * setgolf(), obtain the data, pass the data to the constructor to create a
 * temporary object,and assign the temporary object to the invoking object,
 * which is *this.)
 *
 * @version 0.1
 * @date 2022-07-08
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "exercise_10_3.h"
#include <iostream>

int main()
{
    const int len = 3;
    Golf arr[len];

    std::cout << "Using interactive version\n";
    for (int i = 0; i < len; i++) {
        if (!arr[i].setgolf()) {
            break;
        }
    }
    for (int i = 0; i < len; i++) {
        std::cout << i << ": ";
        arr[i].showgolf();
    }

    std::cout << "\nUsing non-interactive version\n";
    Golf arr2[len];
    for (int i = 0; i < len; i++) {
        std::string name;
        int handicap = 0;

        std::getline(std::cin, name);
        if (!name.empty()) {
            std::cin >> handicap;
            std::cin.ignore(); // Needed for getline()
        }

        Golf tmp(name, handicap);
        arr2[i] = tmp;

        if (name.empty()) {
            break;
        }
    }
    for (int i = 0; i < len; i++) {
        std::cout << i << ": ";
        arr2[i].showgolf();
    }

    return 0;
}

Golf::Golf() {}

Golf::Golf(std::string name, int hc)
{
    fullname = name;
    handicap = hc;
}

int Golf::setgolf()
{
    std::string name;
    int handicap = 0;

    std::getline(std::cin, name);
    if (!name.empty()) {
        std::cin >> handicap;
        std::cin.ignore(); // Needed for getline()
    }

    Golf temp(name, handicap);
    *this = temp;
    return !name.empty();
}

void Golf::set_handicap(int hc) { handicap = hc; }

void Golf::showgolf() const
{
    std::cout << fullname << " " << handicap << "\n";
}