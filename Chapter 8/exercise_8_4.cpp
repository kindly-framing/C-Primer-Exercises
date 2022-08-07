/**
 * @file exercise_8_4.cpp
 * @author Steven Aquino
 * @brief The following is a program skeleton:
 *
 * Complete this skeleton by providing the described functions and prototypes.
 * Note that there should be two show() functions, each using default
 * arguments. Use const arguments when appropriate. Note that set() should use
 * new to allocate sufficient space to hold the designated string.The techniques
 * used here are similar to those used in designing and implementing classes.
 * (You might have to alter the header filenames and delete the using directive,
 * depending on your compiler.)
 * @version 0.1
 * @date 2022-07-03
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <cstring>  // for strlen(), strcpy()
#include <iostream>

struct Stringy {
    char* str;  // points to a string
    int ct;     // length of string (not counting '\0')
};

// Prototypes for set(), show(), and show() go here
void set(Stringy&, const char[]);
void show(const Stringy, int ct = 1);
void show(const char[], int ct = 1);

int main()
{
    Stringy beany;
    char testing[] = "Reality isn't what it used to be.";

    set(beany, testing);  // first argument is a reference,
    // allocates space to hold copy of testing,
    // set str member of beany to point to the
    // new block, copies testing to new block,
    // and set ct member of beany

    show(beany);     // prints member string once
    show(beany, 2);  // prints member string twice
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);     // prints testing string once
    show(testing, 3);  // prints testing string thrice
    show("Done!");
    return 0;
}

void set(Stringy& x, const char str[])
{
    x.str = new char[strlen(str)];
    strcpy(x.str, str);

    x.ct = strlen(str);
}

void show(const Stringy x, int ct)
{
    for (int i = 0; i < ct; i++) {
        for (int j = 0; j < strlen(x.str); j++) {
            std::cout << x.str[j];
        }
        std::cout << "\n";
    }
}

void show(const char str[], int ct)
{
    for (int i = 0; i < ct; i++) {
        std::cout << str << "\n";
    }
}