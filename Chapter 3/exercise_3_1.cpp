/**
 * @file exercise_3_1.cpp
 * @author Steven Aquino
 * @brief Write a short program that asks for your height in integer inches and
 * then converts your height to feet and inches. Have the program use the
 * underscore character to indicate where to type the response. Also use a const
 * symbolic constant to represent the conversion factor.
 * @version 0.1
 * @date 2022-05-20
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <string>

const int feetConversionFactor = 12;

std::string convertToFeet(int inches) {
    std::string res;
    int feet = inches / feetConversionFactor;
    int inch = inches % feetConversionFactor;

    res.append(std::to_string(feet));
    res.append("_");
    res.append(std::to_string(inch));

    return res;
}

int main() {
    std::cout << "Enter your height in inches: ";
    int inches;
    std::cin >> inches;

    std::cout << "Your height in feet and inches is: " << convertToFeet(inches)
              << "\n";
}