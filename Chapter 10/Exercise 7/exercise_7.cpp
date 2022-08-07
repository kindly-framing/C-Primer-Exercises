/**
 * @file exercise_7.cpp
 * @author Steven Aquino
 * @brief A Betelgeusean plorg has these properties:
 *
 * Data
 * A plorg has a name with no more than 19 letters.
 * A plorg has a contentment index (CI), which is an integer.
 *
 * Operations
 * A new plorg starts out with a name and a CI of 50.
 * A plorg’s CI can change.
 * A plorg can report its name and CI.
 * The default plorg has the name "Plorga".
 *
 * Write a Plorg class declaration (including data members and member function
 * prototypes) that represents a plorg. Write the function definitions for the
 * member functions. Write a short program that demonstrates all the features of
 * the Plorg class.
 *
 * @version 0.1
 * @date 2022-07-15
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "plorg.h"

int main()
{
    Plorg test;
    Plorg test1("Bob");
    test.report();
    test1.report();

    test.setCI(1);
    test1.setCI(2);
    test.report();
    test1.report();

    return 0;
}