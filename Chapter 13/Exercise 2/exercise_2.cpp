/**
 * @file exercise_2.cpp
 * @author Steven Aquino
 * @brief Do Programming Exercise 1 but use dynamic memory allocation instead of
 * fixed-size arrays for the various strings tracked by the two classes.
 *
 * @version 0.1
 * @date 2022-08-10
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
using namespace std;
#include "classic2.h" // which will contain #include cd2.h

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