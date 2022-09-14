/**
 * @file exercise_3.cpp
 * @author Steven Aquino
 * @brief Write and test a variadic template function sum_values() that accepts
 * an arbitrarily long list of arguments with numeric values (they can be a
 * mixture of types) and returns the sum as a long double value.
 *
 * @version 0.1
 * @date 2022-09-12
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <typeinfo>

template <typename T> long double sum_values(T first)
{
    std::cout << "Adding: " << first << ' ' << typeid(first).name() << '\n';
    return first;
}

template <typename T, typename... Args>
long double sum_values(T first, Args... args)
{
    std::cout << "Adding: " << first << ' ' << typeid(first).name() << '\n';
    return first + sum_values(args...);
}

int main()
{
    std::cout << sum_values(10L, 15.5, 3.5F, 1) << std::endl;
    return 0;
}