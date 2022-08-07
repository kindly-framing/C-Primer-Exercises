#include "move.h"
#include <iostream>

Move::Move(double a, double b)
{
    x = a;
    y = b;
}

void Move::showmove() const
{
    using namespace std;
    cout << "Values: " << x << ", " << y << "\n";
}

Move Move::add(const Move &m) const
{
    Move x(m.x + this->x, m.y + this->y);
    return x;
}

void Move::reset(double a, double b)
{
    this->x = a;
    this->y = b;
}