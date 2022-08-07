/**
 * @file exercise_5_2.cpp
 * @author Steven Aquino
 * @brief Redo Listing 5.4 using a type array object instead of a built-in array
 * and type long double instead of long long. Find the value of 100!
 * @version 0.1
 * @date 2022-06-03
 *
 * @copyright Copyright (c) 2022
 *
 */
// Listing 5.4
// #include <iostream>
// const int ArSize = 16; // example of external declaration
// int main() {
//     long long factorials[ArSize];
//     factorials[1] = factorials[0] = 1LL;
//     for (int i = 2; i < ArSize; i++)
//         factorials[i] = i * factorials[i - 1];
//     for (int i = 0; i < ArSize; i++)
//         std::cout << i << "! = " << factorials[i] << std::endl;
//     return 0;
// }
#include <iostream>

const int ArSize = 101;

int main() {
    long double factorials[ArSize];
    factorials[1] = factorials[0] = 1;

    for (int i = 2; i < ArSize; i++) {
        factorials[i] = i * factorials[i - 1];
    }

    for (int i = 0; i < ArSize; i++) {
        std::cout << i << "! = " << factorials[i] << "\n";
    }

    return 0;
}