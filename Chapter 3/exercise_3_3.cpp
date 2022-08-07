/**
 * @file exercise_3_3.cpp
 * @author Steven Aquino
 * @brief Write a program that asks the user to enter a latitude in degrees,
 * minutes,and seconds and that then displays the latitude in decimal
 * format.There are 60 seconds of arc to a minute and 60 minutes of arc to a
 * degree; represent these values with symbolic constants.You should use a
 * separate variable for each input value. A sample run should look like this:
 * Enter a latitude in degrees, minutes, and seconds:
 * First, enter the degrees: 37
 * Next, enter the minutes of arc: 51
 * Finally, enter the seconds of arc: 19
 * 37 degrees, 51 minutes, 19 seconds = 37.8553 degrees
 * @version 0.1
 * @date 2022-05-20
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>

const double secondsToMinute = 1 / 60.0;
const double minuteToDegree = 1 / 60.0;

double latitudeDecimal(int degrees, int minutes, int seconds) {
    double latitude;

    double mins = minutes + seconds * secondsToMinute;
    latitude += mins * minuteToDegree + degrees;

    return latitude;
}

int main() {
    std::cout << "Enter a latitude in degrees, minutes, and seconds: \n";

    std::cout << "First, enter the degrees: ";
    int degrees;
    std::cin >> degrees;

    std::cout << "Next, enter the minutes of arc: ";
    int minutes;
    std::cin >> minutes;

    std::cout << "Finally, enter the seconds of arc: ";
    int seconds;
    std::cin >> seconds;

    std::cout << degrees << " degrees, " << minutes << " minutes, " << seconds
              << " seconds = ";
    std::cout << latitudeDecimal(degrees, minutes, seconds) << " degrees\n";
    return 0;
}