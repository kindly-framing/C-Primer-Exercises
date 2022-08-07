/**
 * @file exercise_3_7.cpp
 * @author Steven Aquino
 * @brief Write a program that asks you to enter an automobile gasoline
 * consumption figure in the European style (liters per 100 kilometers) and
 * converts to the U.S. style of miles per gallon. Note that in addition to
 * using different units of measurement, the U.S.approach (distance / fuel) is
 * the inverse of the European approach (fuel / distance). Note that 100
 * kilometers is 62.14 miles,and 1 gallon is 3.875 liters.Thus, 19 mpg is
 * about 12.4 l/100 km,and 27 mpg is about 8.7 l/100 km.
 * @version 0.1
 * @date 2022-05-20
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>

const double kilometersPerMile = 62.14;
const double litersPerGallon = 3.875;

double convertToMPG(double european) {
    int mpg;

    european = 1 / european;        // Inverse the equation.
    mpg = european * 62.14 * 3.875; // Leaves behind mpg.

    return mpg;
}

int main() {
    std::cout << "Enter an automobile gasoline consumption (European): ";
    double european;
    std::cin >> european;

    std::cout << convertToMPG(european) << " mpg is about " << european
              << " l/100 km";
    return 0;
}