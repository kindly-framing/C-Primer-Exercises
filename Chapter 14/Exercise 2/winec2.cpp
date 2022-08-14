#include "winec2.h"
#include <iostream>

Wine::Wine(const char *l, int y, const int yr[], const int bot[])
    : PairArray(ArrayInt(yr, y), ArrayInt(bot, y))
{
    label = l;
    years = y;
}

Wine::Wine(const char *l, int y) : PairArray(ArrayInt(y), ArrayInt(y))
{
    label = l;
    years = y;
}

void Wine::GetBottles()
{
    std::cout << "Enter " << label << " data for " << years << " year(s):\n";
    for (int i = 0; i < years; i++) {
        std::cout << "Enter year: ";
        std::cin >> PairArray::first[i];
        std::cout << "Enter bottles for that year: ";
        std::cin >> PairArray::second[i];
    }
}

std::string Wine::Label() const { return label; }

int Wine::sum() const { return PairArray::second.sum(); }

void Wine::Show() const
{
    std::cout << "Wine: " << label << '\n';
    std::cout << "\t\tYear\tBottles\n";
    for (int i = 0; i < years; i++) {
        std::cout << "\t\t" << PairArray::first[i];
        std::cout << "\t" << PairArray::second[i];
        std::cout << '\n';
    }
}