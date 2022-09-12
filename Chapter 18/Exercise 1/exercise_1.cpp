/**
 * @file exercise_1.cpp
 * @author Steven Aquino
 * @brief Here is part of a short program:
 * exercise_1.cpp
 *
 * Complete the program by supplying the average_list() function. It should be a
 * template function, with the type parameter being used to specify the kind of
 * initialized_list template to be used as the function parameter and also to
 * give the function return type.
 *
 * @version 0.1
 * @date 2022-09-08
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <initializer_list>
#include <iostream>

template <typename T> T average_list(std::initializer_list<T> list);

int main()
{
    using namespace std;
    // list of double deduced from list contents
    auto q = average_list({15.4, 10.7, 9.0});
    cout << q << endl;
    // list of int deduced from list contents
    cout << average_list({20, 30, 19, 17, 45, 38}) << endl;
    // forced list of double
    auto ad = average_list<double>({'A', 70, 65.33});
    cout << ad << endl;
    return 0;
}

template <typename T> T average_list(std::initializer_list<T> list)
{
    T tot = 0;
    std::cout << '(';
    for (auto p = list.begin(); p != list.end(); p++)
    {
        tot += *p;
        std::cout << *p << ((p + 1 != list.end()) ? " + " : "");
    }
    std::cout << ") / " << list.size() << " = ";
    return tot / list.size();
}