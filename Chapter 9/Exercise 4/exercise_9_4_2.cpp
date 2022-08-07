#include <iostream>

#include "exercise_9_4.h"

using namespace SALES;

void SALES::setSales(Sales &s)
{
    double sum = 0;
    double max;
    double min;

    std::cout << "Enter sales for each quarter:\n";
    for (int i = 0; i < QUARTERS; i++) {
        std::cout << i + 1 << ": ";
        std::cin >> s.sales[i];
        sum += s.sales[i];
        if (i == 0) {
            max = s.sales[i];
            min = s.sales[i];
        }
        else {
            max = std::max(s.sales[i], max);
            min = std::min(s.sales[i], min);
        }
    }

    s.average = sum / QUARTERS;
    s.max = max;
    s.min = min;
}

void SALES::setSales(Sales &s, const double ar[], int n)
{
    for (int i = 0; i < n; i++) {
        s.sales[i] = ar[i];
    }
    if (n < QUARTERS) {
        for (int i = n; i < QUARTERS; i++) {
            s.sales[i] = 0;
        }
    }

    double sum = 0;
    double max = s.sales[0];
    double min = s.sales[0];

    for (int i = 0; i < QUARTERS; i++) {
        double sale = s.sales[i];
        sum += sale;
        max = std::max(sale, max);
        min = std::min(sale, min);
    }
    s.average = sum / QUARTERS;
    s.max = max;
    s.min = min;
}

void SALES::showSales(const Sales &s)
{
    std::cout << "Sales for each quarter:\n";
    for (int i = 0; i < QUARTERS; i++) {
        std::cout << i + 1 << ": " << s.sales[i] << "\n";
    }
    std::cout << "Average: " << s.average << "\n";
    std::cout << "Max:     " << s.max << "\n";
    std::cout << "Min:     " << s.min << "\n";
}