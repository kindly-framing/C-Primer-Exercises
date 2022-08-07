/**
 * @file exercise_7_8.cpp
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
const char *Snames[Seasons] = {"Spring", "Summer", "Fall", "Winter"};
struct Expenses {
    double expenses[Seasons];
};

// function to modify array object
void fill(Expenses &x);
// function that uses array object without modifying it
void show(const Expenses x);

int main()
{
    Expenses x;
    fill(x);
    show(x);
    return 0;
}

void fill(Expenses &x)
{
    for (int i = 0; i < Seasons; i++) {
        std::cout << "Enter " << Snames[i] << " expenses: ";
        std::cin >> x.expenses[i];
    }
}

void show(const Expenses x)
{
    double total = 0.0;
    std::cout << "\nEXPENSES\n";
    for (int i = 0; i < Seasons; i++) {
        std::cout << Snames[i] << " : $" << x.expenses[i] << std::endl;
        total += x.expenses[i];
    }
    std::cout << "Total Expenses: $" << total << std::endl;
}