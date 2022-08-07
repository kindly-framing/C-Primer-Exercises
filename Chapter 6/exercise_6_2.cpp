/**
 * @file exercise_6_2.cpp
 * @author Steven Aquino
 * @brief Write a program that reads up to 10 donation values into an array of
 * double. (Or, if you prefer, use an array template object.) The program should
 * terminate input on non-numeric input. It should report the average of the
 * numbers and also report how many numbers in the array are larger than the
 * average.
 * @version 0.1
 * @date 2022-06-10
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <string>
#include <vector>

int main() {
    const int DONATION_LIMIT = 10; // Only read up to 10 donations

    std::vector<double> donations; // Store donations
    std::string input;             // Store user input for testing
    int entries = 0;               // Track how many user entries

    // Can only read up to 10 donations or until non-numeric
    std::cout << "Enter donation values:\n";
    while (entries != DONATION_LIMIT) {
        std::getline(std::cin, input);

        // Testing for non-numeric entry
        double donation;
        try {
            donation = std::stod(input);
        } catch (const std::invalid_argument &e) {
            break;
        }
        donations.push_back(donation);
        entries++;
    }

    // Report average
    int average = 0;
    for (double donation : donations) {
        average += donation;
    }
    average /= donations.size();

    // Report how many numbers are larger than the average
    int count = 0;
    for (double donation : donations) {
        count += (donation > average) ? 1 : 0;
    }

    std::cout << "Average: " << average << "\n";
    std::cout << count << " numbers are larger than the average.\n";

    return 0;
}