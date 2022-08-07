/**
 * @file exercise_6_1.cpp
 * @author Steven Aquino
 * @brief Write a program that reads keyboard input to the @ symbol and that
 * echoes the input except for digits, converting each uppercase character to
 * lowercase, and vice versa. (Don’t forget the cctype family.)
 * @version 0.1
 * @date 2022-06-10
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <cctype>
#include <iostream>
#include <string>

int main() {
    std::cout << "Enter text for echo, and type @ to terminate input: ";

    char ch;
    std::cin.get(ch); // Get the character
    std::string echo; // Store the echo of the input
    while (ch != '@') {
        if (!isdigit(ch)) {
            if (isalpha(ch)) {
                // Convert each uppercase to lowercase, and vice versa
                echo += (isupper(ch)) ? tolower(ch) : toupper(ch);
            } else {
                // Echo anything else except digits
                echo += ch;
            }
        }

        std::cin.get(ch);
    }

    std::cout << echo << "\n";
    return 0;
}