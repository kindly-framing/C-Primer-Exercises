/**
 * @file exercise_5_5.cpp
 * @author Steven Aquino
 * @brief You sell the book C++ for Fools. Write a program that has you enter a
 * year’s worth of monthly sales (in terms of number of books, not of money).
 * The program should use a loop to prompt you by month, using an array of
 * char* (or an array of string objects, if you prefer) initialized to the month
 * strings and storing the input data in an array of int. Then, the program
 * should find the sum of the array contents and report the total sales for the
 * year.
 * @version 0.1
 * @date 2022-06-03
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> months = {
        "January", "February", "March",     "April",   "May",      "June",
        "July",    "August",   "September", "October", "November", "December"};

    std::vector<int> sales;
    for (std::string month : months) {
        std::cout << "Enter book sales for " << month << ": ";
        int monthSales;
        std::cin >> monthSales;
        sales.push_back(monthSales);
    }

    int totalSales = 0;
    for (int sale : sales) {
        totalSales += sale;
    }

    std::cout << "Total sales: " << totalSales << "\n";
    return 0;
}