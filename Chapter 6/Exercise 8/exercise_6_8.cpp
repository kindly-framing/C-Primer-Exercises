/**
 * @file exercise_6_8.cpp
 * @author Steven Aquino
 * @brief Write a program that opens a text file, reads it
 * character-by-character to the end of the file,and reports the number of
 * characters in the file.
 * @version 0.1
 * @date 2022-06-12
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream myfile("exercise_6_8.txt");
    std::string mystring;
    int numOfChrs = 0;

    if (myfile.is_open()) {
        while (myfile) {
            myfile.get();
            numOfChrs++;
        }
    } else {
        std::cout << "Couldn't open file\n";
    }

    std::cout << "Number of characters in the file: " << numOfChrs << "\n";

    return 0;
}