/**
 * @file exercise_8_3.cpp
 * @author Steven Aquino
 * @brief Write a function that takes a reference to a string object as its
 * parameter and that converts the contents of the string to uppercase. Use the
 * toupper() function described in Table 6.4 of Chapter 6.Write a program that
 * uses a loop which allows you to test the function with different input.A
 * sample run might look like this:
 *
 * Enter a string (q to quit): go away
 * GO AWAY
 * Next string (q to quit): good grief!
 * GOOD GRIEF!
 * Next string (q to quit): q
 * Bye.
 *
 * @version 0.1
 * @date 2022-07-02
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <cctype>
#include <iostream>
#include <string>

std::string to_upper(std::string);

int main()
{
    std::cout << "Enter a string (q to quit): ";

    std::string input;
    while (std::getline(std::cin, input)) {
        if (input == "q") {
            break;
        }
        std::string upper = to_upper(input);
        std::cout << upper << "\n";
        std::cout << "Next string (q to quit): ";
    }

    std::cout << "Bye.\n";

    return 0;
}

std::string to_upper(std::string str)
{
    std::string upper;

    for (int i = 0; i < str.size(); i++) {
        char chr = str[i];
        if (isalpha(chr)) {
            upper.push_back(toupper(chr));
        }
        else {
            upper.push_back(chr);
        }
    }

    return upper;
}