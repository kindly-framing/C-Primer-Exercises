/**
 * @file exercise_3.cpp
 * @author Steven Aquino
 * @brief Modify Listing 11.15 so that instead of reporting the results of a
 * single trial for a particular target/step combination, it reports the
 * highest, lowest,and average number of steps for N trials, where N is an
 * integer entered by the user.

 * @version 0.1
 * @date 2022-07-31
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "vect3.h"
#include <algorithm>
#include <cstdlib> // rand(), srand prototypes
#include <ctime>   // time() prototype
#include <iostream>
#include <numeric>
#include <vector>

void print_vector(std::vector<unsigned long> vec)
{
    for (unsigned long a : vec) {
        std::cout << a << " ";
    }
    std::cout << "\n";
}

int main()
{
    using namespace std;
    using VECTOR::Vector;

    srand(time(0)); // seed random-number generator
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;

    int trials;
    double target;
    double dstep;
    cout << "Enter amount of trials to run: ";
    cin >> trials;
    cout << "Enter target distance (q to quit): ";
    cin >> target;
    cout << "Enter step length: ";
    cin >> dstep;
    cout << "Amount of trials: " << trials << ", Target Distance: " << target
         << ", Step size: " << dstep << "\n";

    vector<unsigned long> trial_steps;
    for (int i = 0; i < trials; i++) {
        while (result.magval() < target) {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++;
        }
        trial_steps.push_back(steps);
        steps = 0;
        result.reset(0.0, 0.0);
    }

    cout << "Results from " << trials << " runs: \n";
    print_vector(trial_steps);
    cout << "Maximum = " << *max_element(trial_steps.begin(), trial_steps.end())
         << "\n";
    cout << "Minimum = " << *min_element(trial_steps.begin(), trial_steps.end())
         << "\n";
    cout << "Average = "
         << accumulate(trial_steps.begin(), trial_steps.end(), 0) /
                trial_steps.size()
         << "\n";

    cout << "Bye!\n";
    cin.clear();
    while (cin.get() != '\n') {
        continue;
    }
    return 0;
}