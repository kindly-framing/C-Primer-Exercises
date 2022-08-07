/**
 * @file exercise_5_9.cpp
 * @author Steven Aquino
 * @brief Write a program that matches the description of the program in
 * Programming Exercise 8, but use a string class object instead of an array.
 * Include the string header file and use a relational operator to make the
 * comparison test.
 * @version 0.1
 * @date 2022-06-09
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line); // Splits the line word by word

    int count = 0;
    do {
        std::string word;
        iss >> word;
        if (word == "done") {
            break;
        }
        count++;
    } while (iss);

    std::cout << "You entered a total of " << count << " words.\n";
    return 0;
}