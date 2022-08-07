#include "plorg.h"
#include <cstring>
#include <iostream>

Plorg::Plorg(const char name_[MAX])
{
    strcpy(name, name_);
    index = 50;
}

void Plorg::setCI(const int ci) { index = ci; }

void Plorg::report() const
{
    using namespace std;
    cout << "Plorg's Name: " << name << "\n";
    cout << "Plorg's CI: " << index << "\n";
}