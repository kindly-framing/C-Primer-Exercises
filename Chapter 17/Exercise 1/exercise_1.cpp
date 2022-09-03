/**
 * @file exercise_1.cpp
 * @author Steven Aquino
 * @brief Write a program that counts the numbers of characters up to the first
 * $ in input and that leaves the $ in the input stream.
 *
 * @version 0.1
 * @date 2022-09-02
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <string>

int main()
{
    using namespace std;
    cout << "Enter characters (end with $): ";
    string input, leftover;
    getline(cin, input, '$');
    cin.putback('$');
    getline(cin, leftover);
    cout << "Characters before $: " << input << '\n';
    cout << "Number of characters: " << input.size() << '\n';
    cout << "Leftover characters: " << leftover << '\n';
    return 0;
}