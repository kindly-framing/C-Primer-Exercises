#include "cd.h"
#include <cstring>
#include <iostream>

Cd::Cd(char *s1, char *s2, int n, double x)
{
    strcpy(performers, s1);
    strcpy(label, s2);
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd &d) { *this = d; }

Cd::Cd()
{
    performers[0] = '\0';
    label[0] = '\0';
    selections = 0;
    playtime = 0;
}

Cd::~Cd(){};

void Cd::Report() const
{
    std::cout << "Performers: " << performers << '\n';
    std::cout << "     Label: " << label << '\n';
    std::cout << "Selections: " << selections << '\n';
    std::cout << "  Playtime: " << playtime << " minutes\n";
}

Cd &Cd::operator=(const Cd &d)
{
    strcpy(this->performers, d.performers);
    strcpy(this->label, d.label);
    this->selections = d.selections;
    this->playtime = d.playtime;
}