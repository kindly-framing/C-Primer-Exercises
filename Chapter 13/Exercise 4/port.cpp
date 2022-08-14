#include "port.h"
#include <cstring>

// Port methods

Port::Port(const char *br, const char *st, int b)
{
    brand = new char[strlen(br) + 1];
    strcpy(brand, br);
    strncpy(style, st, 20);
    bottles = b;
}

Port::Port(const Port &p) { *this = p; }

Port &Port::operator=(const Port &p)
{
    delete[] brand;
    brand = new char[strlen(p.brand) + 1];
    strcpy(brand, p.brand);
    strncpy(style, p.style, 20);
    bottles = p.bottles;
    return *this;
}

Port &Port::operator+=(int b)
{
    bottles += b;
    return *this;
}

Port &Port::operator-=(int b)
{
    bottles -= b;
    return *this;
}

void Port::Show() const
{
    cout << "   Brand: " << brand << '\n';
    cout << "    Kind: " << style << '\n';
    cout << " Bottles: " << bottles << '\n';
}

ostream &operator<<(ostream &os, const Port &p)
{
    os << p.brand << ", " << p.style << ", " << p.bottles;
    return os;
}

// VintagePort methods

VintagePort::VintagePort() : Port()
{
    nickname = new char[1];
    nickname[0] = '\0';
    year = 0;
}

VintagePort::VintagePort(const char *br, int b, const char *nm, int y)
    : Port(br, "Vintage", b)
{
    nickname = new char[strlen(nm) + 1];
    strcpy(nickname, nm);
    year = y;
}

VintagePort::VintagePort(const VintagePort &vp) { *this = vp; }

VintagePort &VintagePort::operator=(const VintagePort &vp)
{
    Port::operator=(vp);
    delete[] nickname;
    nickname = new char[strlen(vp.nickname) + 1];
    strcpy(nickname, vp.nickname);
    year = vp.year;
    return *this;
}

void VintagePort::Show() const
{
    Port::Show();
    cout << "Nickname: " << nickname << '\n';
    cout << "    Year: " << year << '\n';
}

ostream &operator<<(ostream &os, const VintagePort &vp)
{
    os << (const Port &)vp << ", " << vp.nickname << ", " << vp.year;
    return os;
}