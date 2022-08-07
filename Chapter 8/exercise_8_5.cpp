/**
 * @file exercise_8_5.cpp
 * @author Steven Aquino
 * @brief Write a template function max5() that takes as its argument an array
 * of five items of type T and returns the largest item in the array. (Because
 * the size is fixed, it can be hard-coded into the loop instead of being passed
 * as an argument.) Test it in a program that uses the function with an array of
 * five int value and an array of five double values.
 *
 * @version 0.1
 * @date 2022-07-03
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>

template <typename T>
T max5(T[5]);

int main()
{
    int int_set[5] = {1, 2, 3, 4, 5};
    double double_set[5] = {1.1, 2.2, 3.3, 4.4, 5.5};

    std::cout << "Max of {1, 2, 3, 4, 5} = " << max5(int_set) << "\n";
    std::cout << "Max of {1.1, 2.2, 3.3, 4.4, 5.5} = " << max5(double_set)
              << "\n";

    return 0;
}

template <typename T>
T max5(T arr[])
{
    T max = arr[0];
    for (int i = 1; i < 5; i++) {
        max = (arr[i] > max) ? arr[i] : max;
    }
    return max;
}