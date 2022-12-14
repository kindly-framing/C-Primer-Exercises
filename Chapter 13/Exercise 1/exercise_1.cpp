/**
 * @file exercise_1.cpp
 * @author Steven Aquino
 * @brief Using the CD class as the base class, derive a Classic class that adds
 * an array of char members that will hold a string identifying the primary work
 * on the CD. If the base class requires that any functions be virtual, modify
 * the base-class declaration to make it so. If a declared method is not needed,
 * remove it from the definition. Test your product with the following program:
 *
 * @version 0.1
 * @date 2022-08-10
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
using namespace std;
#include "classic.h" // which will contain #include cd.h

void Bravo(const Cd &disk);
int main()
{
    Cd c1("Beatles", "Capitol", 14, 35.5);
    Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",
                         "Alfred Brendel", "Philips", 2, 57.17);
    Cd *pcd = &c1;

    cout << "Using object directly:\n";
    c1.Report(); // use Cd method
    c2.Report(); // use classic method

    cout << "\nUsing type cd *pointer to objects:\n";
    pcd->Report(); // use Cd method for cd object
    pcd = &c2;
    pcd->Report(); // use Classic method for classic object

    cout << "\nCalling a function with a Cd reference argument:\n";
    Bravo(c1);
    Bravo(c2);

    cout << "\nTesting assignment: \n";
    Classic copy;
    copy = c2;
    copy.Report();

    return 0;
}

void Bravo(const Cd &disk) { disk.Report(); }