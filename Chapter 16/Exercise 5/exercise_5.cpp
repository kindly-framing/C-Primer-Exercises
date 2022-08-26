/**
 * @file exercise_5.cpp
 * @author Steven Aquino
 * @brief Do the same problem as described in Programming Exercise 4, except
 * make it a template function:
 * template <class T>
 * int reduce(T ar[], int n);
 *
 * Test the function in a short program, using both a long instantiation and a
 * string instantiation.
 *
 * @version 0.1
 * @date 2022-08-26
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using std::string;
// function template
template <class T> int reduce(T ar[], int n);

int main()
{
    using std::cout;
    long nums[10] = {1, 1, 5, 3, 4, 4, 2, 2, 4, 5};
    cout << "Initial size: " << 10 << '\n';
    cout << "Removing duplicates...\n";
    cout << "New size: " << reduce(nums, 10) << '\n';

    string words[5] = {"abc", "cba", "abc", "zye", "zye"};
    cout << "Initial size: " << 5 << '\n';
    cout << "Removing duplicates...\n";
    cout << "New size: " << reduce(words, 5) << '\n';
}

template <class T> int reduce(T ar[], int n)
{
    // copying the array to a vector
    std::vector<T> copy;
    for (int i = 0; i < n; i++)
    {
        copy.push_back(ar[i]);
    }
    // remove duplicate values
    std::sort(copy.begin(), copy.end());
    typename std::vector<T>::iterator it;
    it = std::unique(copy.begin(), copy.end());
    copy.resize(std::distance(copy.begin(), it));
    // return new number of elements
    return copy.size();
}