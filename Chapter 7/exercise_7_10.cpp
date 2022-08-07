/**
 * @file exercise_7_10.cpp
 * @author Steven Aquino
 * @brief Design a function calculate() that takes two type double values and a
 * pointer to a function that takes two double arguments and returns a
 * double.The calculate() function should also be type double,and it should
 * return the value that the pointed-to function calculates, using the double
 * arguments to calculate(). For example, suppose you have this definition for
 * the add() function:
 *
 * double add(double x, double y)
 * {
 * return x + y;
 * }
 *
 * Then, the function call in the following would cause calculate() to pass the
 * values 2.5 and 10.4 to the add() function and then return the add() return
 * value (12.9):
 * double q = calculate(2.5, 10.4, add);
 *
 * Use these functions and at least one additional function in the add() mold in
 * a program.The program should use a loop that allows the user to enter pairs
 * of numbers. For each pair, use calculate() to invoke add() and at least one
 * other function. If you are feeling adventurous, try creating an array of
 * pointers to add()-style functions and use a loop to successively apply
 * calculate() to a series of functions by using these pointers. Hint: Here’s
 * how to declare such an array of three pointers:
 * double (*pf[3])(double, double);
 *
 * You can initialize such an array by using the usual array initialization
 * syntax and function names as addresses.
 * @version 0.1
 * @date 2022-07-01
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>

double calculate(double, double, double (*func)(double, double));
double add(double, double);
double subtract(double, double);

int main()
{
    freopen("in.txt", "r", stdin);

    double n1;
    double n2;

    while (scanf("%lf %lf", &n1, &n2) == 2) {
        std::cout << n1 << " + " << n2 << " = " << calculate(n1, n2, add);
        std::cout << "\n";

        std::cout << n1 << " - " << n2 << " = " << calculate(n1, n2, subtract);
        std::cout << "\n";
    }

    std::cout << "Done.\n";

    return 0;
}

double calculate(double n1, double n2, double (*arithmetic)(double, double))
{
    return arithmetic(n1, n2);
}

double add(double n1, double n2) { return n1 + n2; }

double subtract(double n1, double n2) { return n1 - n2; }