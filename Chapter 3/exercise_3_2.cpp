/**
 * @file exercise_3_2.cpp
 * @author Steven Aquino
 * @brief Write a short program that asks for your height in feet and inches and
 * your weight in pounds. (Use three variables to store the information.) Have
 * the program report your body mass index (BMI).To calculate the BMI, first
 * convert your height in feet and inches to your height in inches (1 foot = 12
 * inches).Then convert your height in inches to your height in meters by
 * multiplying by 0.0254. Then convert your weight in pounds into your mass in
 * kilograms by dividing by 2.2. Finally, compute your BMI by dividing your mass
 * in kilograms by the square of your height in meters. Use symbolic constants
 * to represent the various conversion factors.
 * @version 0.1
 * @date 2022-05-20
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <cmath>
#include <iostream>

const int inchToFeetFactor = 12;
const double inchToMetersFactor = 0.0254;
const double poundToKilogramFactor = (1 / 2.2);

double computeBMI(int feet, int inches, int lbs) {
    double bmi;
    double height; // Must be in meters
    double mass;   // Must be in kilograms

    int in = feet * inchToFeetFactor + inches;
    height = inchToMetersFactor * in;

    mass = lbs * poundToKilogramFactor;

    bmi = mass / std::pow(height, 2);
    return bmi;
}

int main() {
    std::cout << "Enter your height in feet and inches: ";
    int feet;
    int inches;
    std::cin >> feet >> inches;

    std::cout << "Enter your weight in pounds: ";
    int pounds;
    std::cin >> pounds;

    std::cout << "Your BMI is: " << computeBMI(feet, inches, pounds) << "\n";
    return 0;
}