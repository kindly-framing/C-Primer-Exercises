/**
 * @file exercise_5_6.cpp
 * @author Steven Aquino
 * @brief Do Programming Exercise 5 but use a two-dimensional array to store
 * input for 3 years of monthly sales. Report the total sales for each
 * individual year and for the combined years
 * @version 0.1
 * @date 2022-06-09
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <vector>

const int TOTAL_YEARS = 3;

int main() {
    std::vector<std::string> months = {
        "January", "February", "March",     "April",   "May",      "June",
        "July",    "August",   "September", "October", "November", "December"};

    std::vector<std::vector<int>> yearlySales(TOTAL_YEARS);

    // Getting the information from the user
    for (int year = 0; year < TOTAL_YEARS; year++) {
        std::cout << "Enter monthly sales for Year " << year << "\n";

        for (int month = 0; month < 12; month++) {
            std::cout << months[month] << ": ";
            int monthlySale;
            std::cin >> monthlySale;
            yearlySales[year].push_back(monthlySale);
        }
    }

    // Adding and displaying the yearly sums for each year
    for (int i = 0; i < yearlySales.size(); i++) {
        int yearlySum = 0;
        for (int j = 0; j < yearlySales[i].size(); j++) {
            yearlySum += yearlySales[i][j];
        }
        std::cout << "Year " << i << " sales: " << yearlySum << "\n";
    }

    return 0;
}