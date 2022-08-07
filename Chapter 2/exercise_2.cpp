/**
 * @file exercise_2.cpp
 * @author Steven Aquino
 * @brief Exercise 2 from C++ Primer Chapter 2
 * Write a C++ program that asks for a distance in furlongs and converts it to
 * yards. (One furlong is 220 yards)
 * @version 0.1
 * @date 2022-05-20
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>

/**
 * @brief Converts furlongs to yards. (1 furlong is 220 yards).
 *
 * @param furlongs Integer value.
 * @return Yards
 */
int convertFurlongsToYards(int furlongs) { return furlongs * 220; }

int main()
{
    std::cout << "Enter a distance in furlongs: ";

    int distance;
    std::cin >> distance;

    std::cout << convertFurlongsToYards(distance) << " yards.";
}