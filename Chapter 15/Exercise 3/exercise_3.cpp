/**
 * @file exercise_3.cpp
 * @author Steven Aquino
 * @brief This exercise is the same a Programming Exercise 2, except that the
 * exceptions should be derived from a base class (itself derived from logic
 * error) that stores the two arguments values, the exceptions should have a
 * method that reports these values as well as the function name, and a single
 * catch block that catches the base-class exemption should be used for both
 * exceptions, with either exception causing the loop to terminate.
 *
 * @version 0.1
 * @date 2022-08-21
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "exc_mean2.h"
#include <cmath>
#include <iostream>
// function prototypes
double hmean(double a, double b);
double gmean(double a, double b);
int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    double x, y, z;

    cout << "Enter two numbers: ";
    while (cin >> x >> y)
    {
        try
        {
            z = hmean(x, y);
            cout << "Harmonic mean of " << x << " and " << y << " is " << z
                 << endl;
            cout << "Geometric mean of " << x << " and " << y << " is "
                 << gmean(x, y) << endl;
            cout << "Enter next set of numbers <q to quit>: ";
        }
        catch (bad_mean &bg)
        {
            cout << bg.what() << '\n';
            cout << "Sorry, you don't get to play any more.\n";
            break;
        }
    }
    cout << "Bye!\n";
    return 0;
}

double hmean(double a, double b)
{
    if (a == -b)
    {
        throw bad_hmean(a, b);
    }
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
    {
        throw bad_gmean(a, b);
    }
    return std::sqrt(a * b);
}