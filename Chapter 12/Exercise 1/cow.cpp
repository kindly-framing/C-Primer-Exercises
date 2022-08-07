#include "cow.h"
#include <cstring>
#include <iostream>

Cow::Cow()
{
    int len = strlen(name);
    std::memset(name, 0, len);
    hobby = new char[len + 1];
    std::memset(hobby, 0, len);
    weight = 0;
}

Cow::Cow(const char *nm, const char *ho, double wt)
{
    std::memcpy(name, nm, strlen(nm) + 1);
    int len = std::strlen(ho);
    hobby = new char[len + 1];
    std::strcpy(hobby, ho);
    weight = wt;
}

Cow::Cow(const Cow &c) { *this = c; }

Cow::~Cow() {}

Cow &Cow::operator=(const Cow &c)
{
    std::memcpy(this->name, c.name, strlen(c.name) + 1);
    this->hobby = c.hobby;
    this->weight = c.weight;
    return *this;
}

void Cow::ShowCow() const
{
    std::cout << "Cow's name: ";
    puts(name);
    std::cout << "Cow's hobby: ";
    puts(hobby);
    std::cout << "Cow's weight: " << weight << '\n';
}