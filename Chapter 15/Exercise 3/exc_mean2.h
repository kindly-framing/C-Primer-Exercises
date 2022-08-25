#ifndef EXC_MEAN2_H_
#define EXC_MEAN2_H_
#include <iostream>
#include <stdexcept>
#include <string>

// derived from a base class (itself derived from logic error)
// stores the two argument values
class bad_mean : public std::logic_error
{
  private:
    double v1;
    double v2;

  public:
    bad_mean(double a = 0, double b = 0, std::string msg = "")
        : v1(a), v2(b), std::logic_error(msg)
    {
    }
    void report_values() const
    {
        std::cout << "1st Value: " << v1 << '\n';
        std::cout << "2nd Value: " << v2 << '\n';
    }
};

// the exceptions should have a method that reports these values as well as the
// function name
class bad_hmean : public bad_mean
{
  public:
    bad_hmean(double a = 0, double b = 0)
        : bad_mean(a, b,
                   "hmean(" + std::to_string(a) + "," + std::to_string(b) +
                       "): invalid arguments: a = -b/n")
    {
    }
    const char *what() const noexcept
    {
        std::cout << "Thrown exception: hmean()\n";
        bad_mean::report_values();
        return bad_mean::what();
    }
};

class bad_gmean : public bad_mean
{
  public:
    bad_gmean(double a = 0, double b = 0)
        : bad_mean(a, b, "gmean() arguments should be >= 0")
    {
    }
    const char *what() const noexcept
    {
        std::cout << "Thrown exception: gmean()\n";
        bad_mean::report_values();
        return bad_mean::what();
    }
};

#endif