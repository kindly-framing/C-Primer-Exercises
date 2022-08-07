/**
 * @file exercise_1.cpp
 * @author Steven Aquino
 * @brief Modify Listing 11.15 so that it writes the successive locations of the
 * random walker into a file. Label each position with the step number. Also
 * have the program write the initial conditions (target distance and step size)
 * and the summarized results to the file.
 *
 * @version 0.1
 * @date 2022-07-16
 *
 * @copyright Copyright (c) 2022
 *
 */
// randwalk.cpp -- using the Vector class
// compile with the vect.cpp
#include "vect.h"
#include <cstdlib> // rand(), srand prototypes
#include <ctime>   // time() prototype
#include <fstream>
#include <iostream>

int main()
{
    using namespace std;
    using VECTOR::Vector;

    srand(time(0)); // seed random-number generator
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;

    ofstream fout;
    fout.open("thewalk.txt");

    cout << "Enter target distance (q to quit): ";
    while (cin >> target) {
        cout << "Enter step length: ";
        if (!(cin >> dstep)) {
            break;
        }

        fout << "Target Distance: " << target << ", "
             << "Step size: " << dstep << "\n";
        fout << steps << ": " << result << "\n";

        while (result.magval() < target) {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++;
            fout << steps << ": " << result << "\n";
        }

        fout << "After " << steps
             << " steps, the subject has the following location:\n";
        fout << result << endl;
        result.polar_mode();
        fout << " or\n" << result << endl;
        fout << "Average outward distance per step = "
             << result.magval() / steps << endl;
        steps = 0;
        result.reset(0.0, 0.0);
        cout << "Enter target distance (q to quit): ";
    }

    cout << "Bye!\n";
    cin.clear();
    while (cin.get() != '\n') {
        continue;
    }
    return 0;
}