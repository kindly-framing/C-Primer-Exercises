/**
 * @file exercise_5.cpp
 * @author Steven Aquino
 * @brief Exercise 5 from C++ Primer Chapter 2
 * Write a program tht has main() call a user-defined functions that takes a
 * Celsius temperature value as an argument and then returns the equivalent
 * Fahrenheit value. The program should request the Celsius value as input from
 * the user and display the result, as shown in the following code:
 * Please enter a Celsius value: 20
 * 20 degrees Celsius is 68 degrees Fahrenheit.
 * @version 0.1
 * @date 2022-05-20
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>

int convertCelsiusToFahrenheit(int celsius) { return (1.8 * celsius) + 32.0; }

int main()
{
    std::cout << "Please enter a Celsius value: ";
    int celsius;
    std::cin >> celsius;

    int fahrenheit = convertCelsiusToFahrenheit(celsius);
    std::cout << celsius << " degrees Celsius is " << fahrenheit
              << " degrees Fahrenheit.\n";
    return 0;
}