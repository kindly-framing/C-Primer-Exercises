/**
 * @file exercise_9_4.cpp
 * @author Steven Aquino
 * @brief The first file should be a header file that contains the namespace.The
 * second file should be a source code file that extends the namespace to
 * provide definitions for the three prototyped functions.The third file should
 * declare two Sales objects. It should use the interactive version of
 * setSales() to provide values for one structure and the non-interactive
 * version of setSales() to provide values for the second structure. It should
 * display the contents of both structures by using showSales().
 *
 * @version 0.1
 * @date 2022-07-07
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>

#include "exercise_9_4.h"

int main()
{
    using namespace SALES;

    // Using interactive version
    Sales s1;
    setSales(s1);
    showSales(s1);

    // Using non-interactive version
    Sales s2;
    double sales[3];
    std::cout << "Enter sales for each quarter:\n";
    for (int i = 0; i < 3; i++) {
        std::cout << i + 1 << ": ";
        std::cin >> sales[i];
    }
    setSales(s2, sales, 3);
    showSales(s2);

    return 0;
}