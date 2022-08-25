/**
 * @file exercise_1.cpp
 * @author Steven Aquino
 * @brief A palindrome is a string that is the same backward as it is forward.
 * For example, "tot" and "otto" are rather short palindromes. Write a program
 * that lets a user enter a string and that passes to a bool function a
 * reference to the string. The function should return true is the string is a
 * palindrome and false otherwise. At this point, don't worry about complication
 * such as capitalization, spaces, and punctuation. That is, this simple version
 * should reject "Otto" and "Madam, I'm Adam." Feel free to scan the list of
 * string methods in Appendix F for methods to simplify the task.
 *
 * @version 0.1
 * @date 2022-08-25
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <string>
// function prototypes
bool is_palindrome(const std::string &s);

int main()
{
    using std::cin;
    using std::cout;
    using std::string;
    cout << "Enter a string to see if it is a palindrome <q to quit>: ";
    string s;
    while (getline(cin, s))
    {
        if (s == "q")
        {
            break;
        }
        cout << s << ": " << (is_palindrome(s) ? "True" : "False") << '\n';
        cout << "Enter a string to see if it is a palindrome <q to quit>: ";
    }
    cout << "Bye!\n";
    return 0;
}

bool is_palindrome(const std::string &s)
{
    int size = s.size();
    if (size == 1)
    {
        return false;
    }
    for (int i = 0; i < size / 2; i++)
    {
        if (s[i] != s[size - 1 - i])
        {
            return false;
        }
    }
    return true;
}