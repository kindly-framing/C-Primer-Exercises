/**
 * @file exercise_4.cpp
 * @author Steven Aquino
 * @brief Write a function with an old-style interface that has this prototype:
 * int reduce(long ar[], int n);
 *
 * The actual arguments should be the name of an array and the number of
 * elements in the array. The function should sort an array, remove duplicate
 * values, and return a value equal to the number of elements in the reduced
 * array. Write the function using STL functions. (If you decide to use the
 * general unique() function, note that it returns the end of the resulting
 * range.) Test the function in a short program.
 *
 * @version 0.1
 * @date 2022-08-26
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <algorithm>
#include <iostream>
#include <vector>
// function prototypes
int reduce(long ar[], int n);

int main()
{
    const int len = 10;
    long nums[len] = {1, 1, 5, 3, 4, 4, 2, 2, 4, 5};
    std::cout << "Initial size: " << len << '\n';
    std::cout << "Removing duplicates...\n";
    std::cout << "New size: " << reduce(nums, len) << '\n';
    return 0;
}

int reduce(long ar[], int n)
{
    // copying the array to a vector
    std::vector<long> copy;
    for (int i = 0; i < n; i++)
    {
        copy.push_back(ar[i]);
    }
    // remove duplicate values
    std::sort(copy.begin(), copy.end());
    std::vector<long>::iterator it;
    it = std::unique(copy.begin(), copy.end());
    copy.resize(std::distance(copy.begin(), it));
    // return new number of elements
    return copy.size();
}