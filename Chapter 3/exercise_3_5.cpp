/**
 * @file exercise3_5.cpp
 * @author Steven Aquino
 * @brief Write a program that requests the user to enter the current world
 * population and the current population of the U.S. (or of some other nation of
 * your choice). Store the information in variables of type long long. Have the
 * program display the percent that the U.S. (or other nation’s) population is
 * of the world’s population.The output should look something like this:
 * Enter the world's population: 6898758899
 * Enter the population of the US: 310783781
 * The population of the US is 4.50492% of the world population.
 * @version 0.1
 * @date 2022-05-20
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>

int main() {
    std::cout << "Enter the world's population: ";
    long long worldPop;
    std::cin >> worldPop;

    std::cout << "Enter the population of the US: ";
    long long USPop;
    std::cin >> USPop;

    double result = static_cast<double>(USPop) / worldPop * 100.0;
    std::cout << "The population of the US is " << result
              << "% of the world population.";

    return 0;
}