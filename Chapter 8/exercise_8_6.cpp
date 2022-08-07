/**
 * @file exercise_8_6.cpp
 * @author Steven Aquino
 * @brief Write a template function maxn() that takes as its arguments an array
 * of items of type T and an integer representing the number of elements in the
 * array and that returns the largest item in the array.Test it in a program
 * that uses the function template with an array of six int value and an array
 * of four double values.The program should also include a specialization that
 * takes an array of pointers-to-char as an argument and the number of pointers
 * as a second argument and that returns the address of the longest string. If
 * multiple strings are tied for having the longest length, the function should
 * return the address of the first one tied for longest.Test the
 * specialization with an array of five string pointers.
 *
 * @version 0.1
 * @date 2022-07-04
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <cstring>
#include <iostream>

template <typename T>
T maxn(T[], const int);

template <>
char* maxn(char*[], const int);

int main()
{
    int ints[6] = {1, 2, 3, 4, 5, 6};
    std::cout << "Max of {1,2,3,4,5, 6}: " << maxn(ints, 6);
    std::cout << "\n";

    double doubles[4] = {1.1, 2.2, 3.3, 4.4};
    std::cout << "Max of {1.1, 2.2, 3.3, 4.4}: " << maxn(doubles, 4);
    std::cout << "\n";

    char* strings[5] = {"a", "abd", "abc", "rtf", "qw"};
    std::cout << "Max of {\"a\", \"abd\", \"abc\", \"rtf\", \"qw\"}: "
              << maxn(strings, 5);
    std::cout << "\n";

    return 0;
}

template <typename T>
T maxn(T arr[], const int size)
{
    T max = arr[0];
    for (int i = 1; i < size; i++) {
        max = (arr[i] > max) ? arr[i] : max;
    }
    return max;
}

template <>
char* maxn(char* arr[], const int size)
{
    char* max = arr[0];
    int max_len = strlen(arr[0]);

    for (int i = 1; i < size; i++) {
        int str_len = strlen(arr[i]);

        if (str_len > max_len) {
            max = arr[i];
            max_len = str_len;
        }
    }

    return max;
}