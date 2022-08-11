#include "classic2.h"
#include <cstring>
#include <iostream>

Classic::Classic(char *classic, char *s1, char *s2, int n, double x)
{
    location = Cd(s1, s2, n, x);

    int len = strlen(classic);
    track = new char[len + 1];
    strcpy(track, classic);
}

Classic::Classic(const Classic &c) { *this = c; }

Classic::Classic()
{
    location = Cd();

    track = new char[1];
    track[0] = '\0';
}

Classic::~Classic() { delete[] track; }

void Classic::Report() const
{
    std::cout << "Classic Track: " << track << '\n';
    location.Report();
}

Classic &Classic::operator=(const Classic &c)
{
    this->location = c.location;

    int len = strlen(c.track);
    this->track = new char[len + 1];
    strcpy(this->track, c.track);
}