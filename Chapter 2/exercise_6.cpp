/**
 * @file exercise_6.cpp
 * @author Steven Aquino
 * @brief Exercise 6 from C++ Primer Chapter 2
 * Write a program that has main() call a user-defined function that takes a
 * distance in light years as an argument and then returns the distance in
 * astronomical units.
 * The program should request the light year value as input from the user and
 * display the result, as shown in the following code:
 * Enter the number of light years: 4.2
 * 4.2 light years = 265608 astronomical units.
 * @version 0.1
 * @date 2022-05-20
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>

double convertToAstronomicalUnits(double lightYears)
{
    return lightYears * 63240;
}

int main()
{
    std::cout << "Enter the number of light years: ";
    double lightYears;
    std::cin >> lightYears;

    double astro = convertToAstronomicalUnits(lightYears);

    std::cout << lightYears << " light years = " << astro
              << " astronomical units.\n";
    return 0;
}