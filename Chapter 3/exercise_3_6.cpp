/**
 * @file exercise_3_6.cpp
 * @author Steven Aquino
 * @brief Write a program that asks how many miles you have driven and how many
 * gallons of gasoline you have used and then reports the miles per gallon your
 * car has gotten. Or, if you prefer, the program can request distance in
 * kilometers and petrol in liters and then report the result European style, in
 * liters per 100 kilometers.
 * @version 0.1
 * @date 2022-05-20
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>

int main() {
    std::cout << "How many miles have you driven?: ";
    double miles;
    std::cin >> miles;

    std::cout << "How many gallons of gasoline have you used?: ";
    double gallons;
    std::cin >> gallons;

    double result = miles / gallons;
    std::cout << "Your car has gotten " << result << " miles per gallon.";

    return 0;
}