#include "dma.h"
#include <cstring>

// Base Class methods

baseDMA::baseDMA(const char *l, int r)
{
    label = new char[strlen(l) + 1];
    strcpy(label, l);
    rating = r;
}

baseDMA::baseDMA(const baseDMA &rs) { *this = rs; }

baseDMA::~baseDMA() { delete[] label; }

baseDMA &baseDMA::operator=(const baseDMA &rs)
{
    delete[] label;
    label = new char[strlen(rs.label) + 1];
    strcpy(label, rs.label);
    rating = rs.rating;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const baseDMA &rs)
{
    os << " Label: " << rs.label << '\n';
    os << "Rating: " << rs.rating << '\n';
    return os;
}

void baseDMA::View() const { std::cout << *this; }

// lacksDMA class methods

lacksDMA::lacksDMA(const char *c, const char *l, int r) : baseDMA(l, r)
{
    strncpy(color, c, COL_LEN);
}

lacksDMA::lacksDMA(const char *c, const baseDMA &rs) : baseDMA(rs)
{
    strncpy(color, c, COL_LEN);
}

std::ostream &operator<<(std::ostream &os, const lacksDMA &rs)
{
    os << (const baseDMA &)rs;
    os << "Color: " << rs.color << '\n';
    return os;
}

void lacksDMA::View() const { std::cout << *this; }

// hasDMA class methods

hasDMA::hasDMA(const char *s, const char *l, int r) : baseDMA(l, r)
{
    style = new char[strlen(s) + 1];
    strcpy(style, s);
}

hasDMA::hasDMA(const char *s, const baseDMA &rs) : baseDMA(rs)
{
    style = new char[strlen(s) + 1];
    strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA &hs) : baseDMA(hs)
{
    style = new char[strlen(hs.style) + 1];
    strcpy(style, hs.style);
}

hasDMA::~hasDMA() { delete[] style; }

hasDMA &hasDMA::operator=(const hasDMA &rs)
{
    baseDMA::operator=(rs);
    delete[] style;
    style = new char[strlen(rs.style) + 1];
    strcpy(style, rs.style);
    return *this;
}

std::ostream &operator<<(std::ostream &os, const hasDMA &rs)
{
    os << (const baseDMA &)rs;
    os << "Style: " << rs.style << '\n';
    return os;
}

void hasDMA::View() const { std::cout << *this; }