/**
 * @file exercise_2.cpp
 * @author Steven Aquino
 * @brief Modify Listing 15.11 so that the two exception types are classes
 * derived from the logic_error class provided by the <stdexcept> header file.
 * Have each what() method report the function name and the nature of the
 * problem. The exception objects need not hold the bad values; they should just
 * support the what() method.
 *
 * @version 0.1
 * @date 2022-08-20
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "exc_mean.h"
#include <cmath> // or math.h, unix users may need -lm flag
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
        try // start of try block
        {
            z = hmean(x, y);
            cout << "Harmonic mean of " << x << " and " << y << " is " << z
                 << endl;
            cout << "Geometric mean of " << x << " and " << y << " is "
                 << gmean(x, y) << endl;
            cout << "Enter next set of numbers <q to quit>: ";
        }                     // end of try block
        catch (bad_hmean &bg) // start of catch block
        {
            cout << bg.what() << '\n';
            cout << "Try again.\n";
            continue;
        }
        catch (bad_gmean &hg)
        {
            cout << hg.what();
            cout << "Values used: " << hg.v1 << ", " << hg.v2 << endl;
            cout << "Sorry, you don't get to play any more.\n";
            break;
        } // end of catch block
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