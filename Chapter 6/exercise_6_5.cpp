/**
 * @file exercise_6_5.cpp
 * @author Steven Aquino
 * @brief The Kingdom of Neutronia, where the unit of currency is the tvarp, has
 * the following income tax code:
 * First 5,000 tvarps: 0% tax
 * Next 10,000 tvarps: 10% tax
 * Next 20,000 tvarps: 15% tax
 * Tvarps after 35,000: 20% tax
 * For example, someone earning 38,000 tvarps would owe 5,000 × 0.00 + 10,000 ×
 * 0.10 + 20,000 × 0.15 + 3,000 × 0.20, or 4,600 tvarps.Write a program that
 * uses a loop to solicit incomes and to report tax owed.The loop should
 * terminate when the user enters a negative number or non-numeric input.
 * @version 0.1
 * @date 2022-06-12
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <string>

double taxOwed(double income);

int main() {
    std::cout << "Enter income to report tax owed\n";

    std::string input;
    while (std::getline(std::cin, input)) {
        double income;

        // Non-numeric input
        try {
            income = std::stod(input);
        } catch (const std::invalid_argument &e) {
            std::cout << "Exiting...\n";
            break;
        }

        // Negative number
        if (income < 0) {
            std::cout << "Exiting...\n";
            break;
        }

        // Calculate Neutronia Tax
        std::cout << "Tax owed: " << taxOwed(income) << "\n";
    }

    return 0;
}

double taxOwed(double income) {
    double tax;

    while (income != 0) {
        double diff;

        if (income > 35'000) {
            diff = income - 35'000;
            tax += diff * 0.20;
        } else if (income - 20'000 > 0) {
            diff = 20'000;
            tax += diff * 0.15;
        } else if (income - 10'000 > 0) {
            diff = 10'000;
            tax += diff * 0.10;
        } else {
            diff = 5'000;
        }

        income -= diff;
    }

    return tax;
}