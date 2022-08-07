/**
 * @file exercise_5_10.cpp
 * @author Steven Aquino
 * @brief Write a program using nested loops that asks the user to enter a
 * value for the number of rows to display. It should then display that many
 * rows of asterisks, with one asterisk in the first row, two in the second
 * row,and so on. For each row, the asterisks are preceded by the number of
 * periods needed to make all the rows display a total number of characters
 * equal to the number of rows.A sample run would look like this:
 * Enter number of rows: 5
 * ....*
 * ...**
 * ..***
 * .****
 * *****
 * @version 0.1
 * @date 2022-06-09
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>

int main() {
    std::cout << "Enter number of rows: ";
    int rows;
    std::cin >> rows;

    for (int i = 0; i < rows; i++) {
        int startIndex = rows - i - 1;
        for (int j = 0; j < rows; j++) {
            if (startIndex <= j) {
                std::cout << "*";
            } else {
                std::cout << ".";
            }
        }
        std::cout << "\n";
    }

    return 0;
}