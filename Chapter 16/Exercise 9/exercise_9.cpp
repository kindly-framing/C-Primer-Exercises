/**
 * @file exercise_9.cpp
 * @author Steven Aquino
 * @brief Test the speed hypothesis with the following approach:
 *
 * a. Create a large vector<int> object vi0, using rand() to provide initial
 * values.
 *
 * b. Create a second vector<int> object vi and a list<int> object li of the
 * same size as the original and initialize them to values in the original
 * vector.
 *
 * c. Time how long program takes to sort vi using the STL sort() algorithm,
 * then time how long it takes to sort li using the list sort() method.
 *
 * d. Reset li to the unsorted contents of vi0. Time the combined operation of
 * copying li to vi, sorting vi, and copying the result back to li.
 *
 * To time these operations, you can use clock() from the ctime library. Then
 * use the following at the end of the operator to get the elapsed time:
 *
 * clock_t end = clock();
 * cout << (double) (end - start)/CLOCKS_PER_SEC;
 *
 * @version 0.1
 * @date 2022-09-01
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>
#include <vector>
using std::list;
using std::vector;

int main()
{
    using std::cin;
    using std::cout;
    const int SIZE = 1'000'000; // amount of initial values

    // (a)
    std::srand(time(0));
    vector<int> vi0;
    for (int i = 0; i < SIZE; i++)
    {
        vi0.push_back(rand() % RAND_MAX);
    }

    // (b)
    vector<int> vi = vi0;
    list<int> li(vi0.begin(), vi0.end());

    // (c)
    clock_t start, end;
    start = clock();
    std::sort(vi.begin(), vi.end());
    end = clock();
    cout << "Using STL sort(): " << (double)(end - start) / CLOCKS_PER_SEC
         << '\n';

    start = clock();
    li.sort();
    end = clock();
    cout << "Using list sort(): " << (double)(end - start) / CLOCKS_PER_SEC
         << '\n';

    //  (d)
    li = list<int>(vi0.begin(), vi0.end());
    start = clock();
    vi = vector<int>(li.begin(), li.end());
    std::sort(vi.begin(), vi.end());
    li = list<int>(vi.begin(), vi.end());
    end = clock();
    cout << "Using speed hypothesis: " << (double)(end - start) / CLOCKS_PER_SEC
         << '\n';

    cout << "Bye\n";
    return 0;
}