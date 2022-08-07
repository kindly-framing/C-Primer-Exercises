/**
 * @file exercise_6.cpp
 * @author Steven Aquino
 * @brief Create member function definitions and a program that exercises the
 * Move class.
 * @version 0.1
 * @date 2022-07-14
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "move.h"

int main()
{
    // test = 0,0 and test1 = 1.0, 2.0
    Move test;
    Move test1(1.0, 2.0);
    test.showmove();
    test1.showmove();

    // test = 1.0, 2.0 and test1 = 1.0, 2.0
    test = test.add(test1);
    test.showmove();
    test1.showmove();

    // test = 1.0, 2.0 and test1 = 0, 0
    test1.reset();
    test.showmove();
    test1.showmove();

    return 0;
}