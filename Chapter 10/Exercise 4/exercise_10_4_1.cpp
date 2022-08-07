/**
 * @file exercise_10_4.cpp
 * @author Steven Aquino
 * @brief Do Programming Exercise 4 from Chapter 9 but convert the Sales
 * structure and its associated functions to a class and its methods. Replace
 * the setSales(Sales &, double [], int) function with a constructor. Implement
 * the interactive setSales(Sales &) method by using the constructor. Keep the
 * class within the namespace SALES.
 *
 * @version 0.1
 * @date 2022-07-14
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "exercise_10_4.h"
#include <iostream>

int main()
{
    using namespace SALES;

    // Using interactive version
    Sales s1;
    s1.setSales();
    s1.showSales();

    // Using non-interactive version
    double sales[3];
    std::cout << "Enter sales for each quarter:\n";
    for (int i = 0; i < 3; i++) {
        std::cout << i + 1 << ": ";
        std::cin >> sales[i];
    }
    Sales s2(sales, 3);
    s2.showSales();

    return 0;
}