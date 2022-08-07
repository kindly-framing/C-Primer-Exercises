/**
 * @file exercise_7_8_a.cpp
 * @author Steven Aquino
 * @brief Redo Listing 7.15 without using the array class. Do two versions:
 *
 * a. Use an ordinary array of const char * for the strings representing the
 * season names,and use an ordinary array of double for the expenses.
 *
 * b. Use an ordinary array of const char * for the strings representing the
 * season names,and use a structure whose sole member is an ordinary array of
 * double for the expenses. (This design is similar to the basic design of the
 * array class.)

 * @version 0.1
 * @date 2022-06-30
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>

const int Seasons = 4;
const char* Snames[Seasons] = {"Spring", "Summer", "Fall", "Winter"};

// function to modify array object
void fill(double ar[Seasons]);
// function that uses array object without modifying it
void show(const double ar[Seasons]);

int main()
{
    double expenses[Seasons];
    fill(expenses);
    show(expenses);
    return 0;
}

void fill(double ar[Seasons])
{
    for (int i = 0; i < Seasons; i++) {
        std::cout << "Enter " << Snames[i] << " expenses: ";
        std::cin >> ar[i];
    }
}

void show(const double ar[Seasons])
{
    double total = 0.0;
    std::cout << "\nEXPENSES\n";
    for (int i = 0; i < Seasons; i++) {
        std::cout << Snames[i] << " : $" << ar[i] << std::endl;
        total += ar[i];
    }
    std::cout << "Total Expenses: $" << total << std::endl;
}