/**
 * @file exercise_8_1.cpp
 * @author Steven Aquino
 * @brief Write a function that normally takes one argument, the address of a
 * string,and prints that string once. However, if a second, type int,argument
 * is provided and is nonzero, the function should print the string a number of
 * times equal to the number of times that function has been called at that
 * point. (Note that the number of times the string is printed is not equal
 * to the value of the second argument; it is equal to the number of times the
 * function has been called.) Yes, this is a silly function, but it makes you
 * use some of the techniques discussed in this chapter. Use the function in a
 * simple program that demonstrates how the function works.
 *
 * @version 0.1
 * @date 2022-07-01
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>

void func(std::string);
void func(std::string, int);

int main()
{
    std::string test = "Hello!";

    std::cout << "func(\"Hello!\")\n";
    func(test);

    std::cout << "func(\"Hello!\", 3)\n";
    func(test, 3);

    return 0;
}

void func(std::string str) { std::cout << str << "\n"; }

void func(std::string str, int n)
{
    if (n > 0) {
        std::cout << str << "\n";
        func(str, n - 1);  // n is the number of times the function is called
    }
}