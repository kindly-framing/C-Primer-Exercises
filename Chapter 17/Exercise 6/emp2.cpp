#include "emp2.h"
#include <iostream>
using std::cin;
using std::cout;

// abstr_emp class methods

abstr_emp::abstr_emp() : fname("null"), lname("null"), job("none") {}

abstr_emp::abstr_emp(const std::string &fn, const std::string &ln,
                     const std::string &j)
    : fname(fn), lname(ln), job(j)
{
}

void abstr_emp::ShowAll() const
{
    cout << "First name: " << fname << '\n';
    cout << " Last name: " << lname << '\n';
    cout << "       Job: " << job << '\n';
}

void abstr_emp::SetAll()
{
    cout << "Enter first name: ";
    cin >> fname;
    cout << "Enter last name: ";
    cin >> lname;
    cout << "Enter job title: ";
    cin >> job;
}

void abstr_emp::WriteAll(std::ofstream &file)
{
    file << fname << ' ' << lname << ' ' << job;
}

void abstr_emp::GetAll(std::ifstream &file) { file >> fname >> lname >> job; }

std::ostream &operator<<(std::ostream &os, const abstr_emp &e)
{
    os << "First name: " << e.fname << '\n';
    os << " Last name: " << e.lname << '\n';
    return os;
}

abstr_emp::~abstr_emp() {}

// employee class methods

employee::employee() : abstr_emp() {}

employee::employee(const std::string &fn, const std::string &ln,
                   const std::string &j)
    : abstr_emp(fn, ln, j)
{
}

void employee::ShowAll() const
{
    cout << "Employee:\n";
    abstr_emp::ShowAll();
    cout << '\n';
}

void employee::SetAll() { abstr_emp::SetAll(); }

void employee::WriteAll(std::ofstream &file)
{
    file << Employee << '\n';
    abstr_emp::WriteAll(file);
    file << '\n';
}

void employee::GetAll(std::ifstream &file) { abstr_emp::GetAll(file); }

// manager class methods

manager::manager() : abstr_emp(), inchargeof(0) {}

manager::manager(const std::string &fn, const std::string &ln,
                 const std::string &j, int ico)
    : abstr_emp(fn, ln, j), inchargeof(ico)
{
}

manager::manager(const abstr_emp &e, int ico) : abstr_emp(e), inchargeof(ico) {}

manager::manager(const manager &m)
    : abstr_emp((const abstr_emp &)m), inchargeof(m.inchargeof)
{
}

void manager::ShowAll() const
{
    cout << "Manager:\n";
    abstr_emp::ShowAll();
    cout << "In charge of " << inchargeof << " employees.\n\n";
}

void manager::SetAll()
{
    abstr_emp::SetAll();
    cout << "Enter amount of abstr_emps managed: ";
    cin >> inchargeof;
}

void manager::WriteAll(std::ofstream &file)
{
    file << Manager << '\n';
    abstr_emp::WriteAll(file);
    file << ' ' << inchargeof << '\n';
}

void manager::GetAll(std::ifstream &file)
{
    abstr_emp::GetAll(file);
    file >> inchargeof;
}

// fink class methods

fink::fink() : abstr_emp(), reportsto("no one") {}

fink::fink(const std::string &fn, const std::string &ln, const std::string &j,
           const std::string &rpo)
    : abstr_emp(fn, ln, j), reportsto(rpo)
{
}

fink::fink(const abstr_emp &e, const std::string &rpo)
    : abstr_emp(e), reportsto(rpo)
{
}

fink::fink(const fink &e)
    : abstr_emp((const abstr_emp &)e), reportsto(e.reportsto)
{
}

void fink::ShowAll() const
{
    cout << "Fink:\n";
    abstr_emp::ShowAll();
    cout << "Reports to: " << reportsto << "\n\n";
}

void fink::SetAll()
{
    abstr_emp::SetAll();
    cout << "Enter who this fink reports to: ";
    cin >> reportsto;
}

void fink::WriteAll(std::ofstream &file)
{
    file << Fink << '\n';
    abstr_emp::WriteAll(file);
    file << ' ' << reportsto << '\n';
}

void fink::GetAll(std::ifstream &file)
{
    abstr_emp::GetAll(file);
    file >> reportsto;
}

// highfink class methods

highfink::highfink() : abstr_emp(), manager(), fink() {}

highfink::highfink(const std::string &fn, const std::string &ln,
                   const std::string &j, const std::string &rpo, int ico)
    : abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo)
{
}

highfink::highfink(const abstr_emp &e, const std::string &rpo, int ico)
    : abstr_emp(e), manager(e, ico), fink(e, rpo)
{
}

highfink::highfink(const fink &f, int ico)
    : abstr_emp((const abstr_emp &)f), manager((const abstr_emp &)f, ico),
      fink(f)
{
}

highfink::highfink(const manager &m, const std::string &rpo)
    : abstr_emp((const abstr_emp &)m), manager(m),
      fink((const abstr_emp &)m, rpo)
{
}

highfink::highfink(const highfink &h)
    : abstr_emp((const abstr_emp &)h), manager((const manager &)h),
      fink((const fink &)h)
{
}

void highfink::ShowAll() const
{
    cout << "High fink:\n";
    abstr_emp::ShowAll();
    cout << "In charge of " << manager::InChargeOf() << " employees.\n";
    cout << "Reports to: " << fink::ReportsTo() << "\n\n";
}

void highfink::SetAll()
{
    abstr_emp::SetAll();
    cout << "Enter amount of abstr_emp's managed: ";
    cin >> manager::InChargeOf();
    cout << "Enter who this high fink reports to: ";
    cin >> fink::ReportsTo();
}

void highfink::WriteAll(std::ofstream &file)
{
    file << HighFink << '\n';
    abstr_emp::WriteAll(file);
    file << ' ' << manager::InChargeOf() << ' ' << fink::ReportsTo() << '\n';
}

void highfink::GetAll(std::ifstream &file)
{
    abstr_emp::GetAll(file);
    file >> manager::InChargeOf();
    file >> fink::ReportsTo();
}

highfink::~highfink() {}