/**
 * @file exercise_4_2.cpp
 * @author Steven Aquino
 * @brief Rewrite Listing 4.4, using the C++ string class instead of char
 * arrays.
 * @version 0.1
 * @date 2022-05-22
 *
 * @copyright Copyright (c) 2022
 *
 */

/**
Listing 4.4 -- instr2.cpp -- reading more than one word with getline
#include <iostream>
int main()
{
    using namespace std;
    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];
    cout << "Enter your name:\n";
    cin.getline(name, ArSize); // reads through newline
    cout << "Enter your favorite dessert:\n";
    cin.getline(dessert, ArSize);
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << ".\n";
    return 0;
}
**/
#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter your name:\n";
    std::string name;
    std::getline(std::cin, name);

    std::cout << "Enter your favorite dessert:\n";
    std::string dessert;
    std::getline(std::cin, dessert);

    std::cout << "I have some delicious " << dessert << " for you, " << name
              << "\n";

    return 0;
}