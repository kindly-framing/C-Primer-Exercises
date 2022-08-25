/**
 * @file exercise_2.cpp
 * @author Steven Aquino
 * @brief Do the same problem as given in Programming Exercise 1 but do worry
 * about complications such as capitalization, spaces, and punctuation. That is,
 * "Madam, I'm Adam" should test as a palindrome. For example, the testing
 * function could reduce the string to "madamimadam" and then test whether the
 * reverse is the same. Don't forget the useful cctype library. You might find
 * an STL function or two useful although not necessary.
 *
 * @version 0.1
 * @date 2022-08-25
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
// function prototypes
bool ispalindrome(std::string s);

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
        cout << s << ": " << (ispalindrome(s) ? "True" : "False") << '\n';
        cout << "Enter a string to see if it is a palindrome <q to quit>: ";
    }
    cout << "Bye!\n";
    return 0;
}

// is a palindrome, regardless of punctuation/capitalization
bool ispalindrome(std::string s)
{
    std::cout << "\tString given: " << s << '\n';
    if (s.size() == 1)
    {
        return false; // at least a length of 2
    }

    int i;
    for (i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        if (!isalpha(ch))
        {
            s.erase(i, 1);
            i--; // ensures the same place is checked
        }
        else
        {
            s[i] = std::tolower(s[i]);
        }
    }
    std::cout << "\tRevised string with only letters: " << s << '\n';
    std::string copy = s;
    std::reverse(copy.begin(), copy.end());
    std::cout << "\tIs " << s << " = " << copy << "?\n";
    return s == copy;
}