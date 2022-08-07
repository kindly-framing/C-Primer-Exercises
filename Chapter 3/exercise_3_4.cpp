/**
 * @file exercise_3_4.cpp
 * @author Steven Aquino
 * @brief Write a program that asks the user to enter the number of seconds as
 * an integer value (use type long, or, if available, long long) and that then
 * displays the equivalent time in days, hours, minutes,and seconds. Use
 * symbolic constants to represent the number of hours in the day, the number of
 * minutes in an hour,and the number of seconds in a minute.The output should
 * look like this:
 * Enter the number of seconds: 31600000
 * 31600000 seconds = 365 days, 17 hours, 46 minutes, 40 seconds
 * @version 0.1
 * @date 2022-05-20
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <string>

const double hoursInDay = 24;
const double minutesInHour = 60;
const double secondsInMinute = 60;

std::string computeSecondsToTime(long long seconds) {
    std::string time;
    int s = seconds; // Leftover seconds

    // Converting to days, and calculating remaining seconds
    s *= 1 / secondsInMinute * 1 / minutesInHour * 1 / hoursInDay;
    int days = s;
    time.append(std::to_string(days) + " days, ");
    seconds -= days * hoursInDay * minutesInHour * secondsInMinute;
    s = seconds;

    // Converting leftover seconds to hours
    s *= 1 / secondsInMinute * 1 / minutesInHour;
    int hours = s;
    time.append(std::to_string(hours) + " hours, ");
    seconds -= hours * minutesInHour * secondsInMinute;
    s = seconds;

    // Converting leftover seconds to minutes
    s *= 1 / secondsInMinute;
    int minutes = s;
    time.append(std::to_string(minutes) + " minutes, ");
    seconds -= minutes * secondsInMinute;
    s = seconds;

    // No need to convert, already in seconds
    time.append(std::to_string(s) + " seconds\n");

    return time;
}

int main() {
    std::cout << "Enter the number of seconds: ";
    long long seconds;
    std::cin >> seconds;

    std::cout << seconds << " seconds = " << computeSecondsToTime(seconds);
    return 0;
}