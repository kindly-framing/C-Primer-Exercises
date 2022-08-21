// exe_mean.h -- exception classes for hmean(), gmean()
#include <iostream>
#include <stdexcept> // logic_error class
#include <string>

class bad_hmean : public std::logic_error
{
  public:
    explicit bad_hmean(double a = 0, double b = 0)
        : std::logic_error("hmean(" + std::to_string(a) + ", " +
                           std::to_string(b) +
                           "): " + "invalid arguments: a = -b/n")
    {
    }
    const char *what() const noexcept { return std::logic_error::what(); }
};

class bad_gmean : public std::logic_error
{
  public:
    double v1;
    double v2;
    bad_gmean(double a = 0, double b = 0)
        : v1(a), v2(b), std::logic_error("gmean() arguments should be >= 0\n")
    {
    }
    const char *what() const noexcept { return std::logic_error::what(); }
};
