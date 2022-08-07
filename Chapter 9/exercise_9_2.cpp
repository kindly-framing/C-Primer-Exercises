/**
 * @file exercise_9_2.cpp
 * @author Steven Aquino
 * @brief Redo Listing 9.9, replacing the character array with a string
 * object. The program should no longer have to check whether the input string
 * fits,and it can compare the input string to "" to check for an empty line.
 *
 * @version 0.1
 * @date 2022-07-07
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <string>

using std::string;

void strcount(string str);

int main()
{
    string next;

    std::cout << "Enter a line:\n";
    while (std::getline(std::cin, next)) {
        if (next == "") {
            break;
        }
        strcount(next);
        std::cout << "Enter next line (empty line to quit):\n";
    }

    std::cout << "Bye\n";
    return 0;
}

void strcount(string str) { std::cout << str.size() << "\n"; }