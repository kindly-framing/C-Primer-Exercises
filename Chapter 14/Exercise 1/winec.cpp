#include "winec.h"
#include <iostream>

Wine::Wine() {}

Wine::Wine(const char *l, int y, const int yr[], const int bot[])
{
    label = l;
    years = y;
    yearAndBottles.first() = ArrayInt(y);
    yearAndBottles.second() = ArrayInt(y);
    for (int i = 0; i < y; i++) {
        yearAndBottles.first()[i] = yr[i];
        yearAndBottles.second()[i] = bot[i];
    }
}

Wine::Wine(const char *l, int y)
{
    label = l;
    years = y;
    yearAndBottles.first() = ArrayInt(y);
    yearAndBottles.second() = ArrayInt(y);
}

void Wine::GetBottles()
{
    std::cout << "Enter " << label << " data for " << years << " year(s):\n";
    for (int i = 0; i < years; i++) {
        std::cout << "Enter year: ";
        std::cin >> yearAndBottles.first()[i];
        std::cout << "Enter bottles for that year: ";
        std::cin >> yearAndBottles.second()[i];
    }
}

std::string Wine::Label() const { return label; }

int Wine::sum() const { return yearAndBottles.second().sum(); }

void Wine::Show() const
{
    std::cout << "Wine: " << label << '\n';
    std::cout << "\t\tYear\tBottles\n";
    for (int i = 0; i < years; i++) {
        std::cout << "\t\t" << yearAndBottles.first()[i];
        std::cout << "\t" << yearAndBottles.second()[i];
        std::cout << '\n';
    }
}