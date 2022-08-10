#include "classic.h"
#include <cstring>
#include <iostream>

Classic::Classic(char *track, char *s1, char *s2, int n, double x)
{
    location = Cd(s1, s2, n, x);
    strcpy(classic, track);
}

Classic::Classic(const Classic &c) { *this = c; }

Classic::Classic()
{
    location = Cd();
    classic[0] = '\0';
}

Classic::~Classic() {}

void Classic::Report() const
{
    std::cout << "Classic track: " << classic << '\n';
    std::cout << "         From:\n";
    location.Report();
}

Classic &Classic::operator=(const Classic &c)
{
    this->location = c.location;
    strcpy(this->classic, c.classic);
}