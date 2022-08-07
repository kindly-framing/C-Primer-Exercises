#include "exercise_10_4.h"
#include <iostream>
using namespace SALES;

Sales::Sales() {}

Sales::Sales(const double ar[], int n)
{
    for (int i = 0; i < QUARTERS; i++) {
        if (i < n) {
            sales[i] = ar[i];
        }
        else {
            sales[i] = 0.0;
        }
    }

    double sum, max_, min_;
    sum = max_ = min_ = sales[0];
    for (int i = 1; i < QUARTERS; i++) {
        sum += sales[i];
        max_ = std::max(sales[i], max_);
        min_ = std::min(sales[i], min_);
    }

    average = sum / QUARTERS;
    max = max_;
    min = min_;
}

void Sales::setSales()
{
    // Gather sales from user
    double sales[QUARTERS];
    std::cout << "Enter sales for quarters\n";
    for (int i = 0; i < QUARTERS; i++) {
        std::cout << "Quarter " << i + 1 << ": ";
        std::cin >> sales[i];
    }

    // Calculate average, min, and max
    double sum, max, min;
    sum = max = min = sales[0];
    for (int i = 1; i < QUARTERS; i++) {
        sum += sales[i];
        max = std::max(sales[i], max);
        min = std::min(sales[i], min);
    }

    // Store in the invoking object
    Sales x(sales, QUARTERS);
    *this = x;
    this->average = sum / QUARTERS;
    this->max = max;
    this->min = min;
}

void Sales::showSales()
{
    std::cout << "Sales:\n";
    for (int i = 0; i < QUARTERS; i++) {
        std::cout << i + 1 << ": " << sales[i] << "\n";
    }
    std::cout << "Average: " << average << "\n";
    std::cout << "Max: " << max << "\n";
    std::cout << "Min: " << min << "\n";
}