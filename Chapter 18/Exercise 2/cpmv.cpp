// cpmv.cpp -- Definitions for cpmv header file
#include "cpmv.h"
#include <iostream>
using std::cout;

Cpmv::Cpmv()
{
    pi = new Info;
    pi->qcode = "";
    pi->zcode = "";
    cout << "default constructor called;\n\t";
    Display();
}

Cpmv::Cpmv(std::string q, std::string z)
{
    pi = new Info;
    pi->qcode = q;
    pi->zcode = z;
    cout << "(string, string) constructor called;\n\t";
    Display();
}

Cpmv::Cpmv(const Cpmv &cp)
{
    pi = new Info;
    pi->qcode = cp.pi->qcode;
    pi->zcode = cp.pi->zcode;
    cout << "copy constructor called;\n\t";
    Display();
}

Cpmv::Cpmv(Cpmv &&mv)
{
    pi = new Info;
    pi = mv.pi;      // steal address
    mv.pi = nullptr; // give old object nothing in return
    cout << "move constructor called;\n\t";
    Display();
}

Cpmv::~Cpmv()
{
    cout << "destructor called;\n";
    delete[] pi;
}

Cpmv &Cpmv::operator=(const Cpmv &cp)
{
    std::cout << "Entering operator=(&Cpmv)\n";
    if (this != &cp)
    {
        Info copy = *cp.pi;
        delete cp.pi;
        this->pi = new Info;
        pi->qcode = copy.qcode;
        pi->zcode = copy.zcode;
    }
    return *this;
}

Cpmv &Cpmv::operator=(Cpmv &&mv)
{
    cout << "Entering operator=(&&Cpmv)\n";
    this->pi = mv.pi;
    mv.pi = nullptr;
    cout << "Exiting operator=(&&Cpmv)\n";
    return *this;
}

Cpmv Cpmv::operator+(const Cpmv &obj) const
{
    cout << "Entering operator+()\n\t";
    cout << "Concatenate both objects:\n\t";
    this->Display();
    cout << "\t";
    obj.Display();
    std::string q = this->pi->qcode + obj.pi->qcode;
    std::string z = this->pi->zcode + obj.pi->zcode;
    Cpmv res(q, z);
    cout << "\tFinal result: ";
    res.Display();
    cout << "Exiting operator+()\n";
    return res;
}

void Cpmv::Display() const
{
    std::cout << "(" << pi->qcode << ", " << pi->zcode << ")\n";
}