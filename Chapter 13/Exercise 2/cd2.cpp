#include "cd2.h"
#include <cstring>
#include <iostream>

Cd::Cd(char *s1, char *s2, int n, double x)
{
    int len1 = strlen(s1);
    performers = new char[len1 + 1];
    strcpy(performers, s1);

    int len2 = strlen(s2);
    label = new char[len2 + 1];
    strcpy(label, s2);

    selections = n;
    playtime = x;
}

Cd::Cd(const Cd &d) { *this = d; }

Cd::Cd()
{
    performers = new char[1];
    performers[0] = '\0';

    label = new char[1];
    label[0] = '\0';

    selections = playtime = 0;
}

Cd::~Cd()
{
    delete[] performers;
    delete[] label;
}

void Cd::Report() const
{
    std::cout << "Performers: " << performers << '\n';
    std::cout << "     Label: " << label << '\n';
    std::cout << "Selections: " << selections << '\n';
    std::cout << "  Playtime: " << playtime << '\n';
}

Cd &Cd::operator=(const Cd &d)
{
    int len1 = strlen(d.performers);
    this->performers = new char[len1 + 1];
    strcpy(this->performers, d.performers);

    int len2 = strlen(d.label);
    this->label = new char[len2 + 1];
    strcpy(this->label, d.label);

    this->selections = d.selections;
    this->playtime = d.playtime;
}