/**
 * @file exercise_5_4.cpp
 * @author Steven Aquino
 * @brief Daphne invests $100 at 10% simple interest. That is, every year, the
 * investment earns 10% of the original investment, or $10 each and every year:
 *
 * interest = 0.10 × original balance
 *
 * At the same time, Cleo invests $100 at 5% compound interest. That is,
 * interest is 5% of the current balance, including previous additions of
 * interest:
 *
 * interest = 0.05 × current balance
 *
 * Cleo earns 5% of $100 the first year, giving her $105. The next year she
 * earns 5% of $105, or $5.25, and so on.
 * Write a program that finds how many years it takes for the value of Cleo’s
 * investment to exceed the value of Daphne’s investment and then displays the
 * value of both investments at that time.
 * @version 0.1
 * @date 2022-06-03
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>

int main() {
    double daphneBalance = 100.0;
    double cleoBalance = 100.0;

    int year = 1;
    while (daphneBalance >= cleoBalance) {
        daphneBalance += 0.10 * 100.0;
        cleoBalance += 0.05 * cleoBalance;

        std::cout << "Year " << year << "\n";
        std::cout << "Daphne's Balance: " << daphneBalance << "\n";
        std::cout << "Cleo's  Balance: " << cleoBalance << "\n\n";
        year++;
    }

    return 0;
}