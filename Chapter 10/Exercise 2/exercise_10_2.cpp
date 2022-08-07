/**
 * @file exercise_10_2.cpp
 * @author Steven Aquino
 * @brief (It uses both a string object and a character array so that you can
 * compare how the two forms are used.) Write a program that completes the
 * implementation by providing code for the undefined methods.The program in
 * which you use the class should also use the three possible constructor calls
 * (no arguments, one argument, and two arguments) and the two display methods.
 * Here’s an example that uses the constructors and methods:
 *
 * Person one;                      // use default constructor
 * Person two("Smythecraft");       // use #2 with one default argument
 * Person three("Dimwiddy", "Sam"); // use #2, no defaults
 * one.Show();
 * cout << endl;
 * one.FormalShow();
 * // etc. for two and three
 *
 * @version 0.1
 * @date 2022-07-08
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <cstring>
#include <iostream>
#include <string>

class Person {
  private:
    static const int LIMIT = 25;
    std::string lname; // Persons's last name
    char fname[LIMIT]; // Person's first name

  public:
    Person()
    {
        lname = "";
        fname[0] = '\0';
    }

    Person(const std::string ln, const char *fn = "Heyyou");
    // the following methods display lname and fname
    void Show() const;
    void FormalShow() const;
};

int main()
{
    Person one;
    one.Show();
    one.FormalShow();
    std::cout << "\n";

    Person two("Smythecraft");
    two.Show();
    two.FormalShow();
    std::cout << "\n";

    Person three("Dimwiddy", "Sam");
    three.Show();
    three.FormalShow();
    std::cout << "\n";

    return 0;
}

Person::Person(const std::string ln, const char *fn)
{
    lname = ln;
    strcpy(fname, fn);
}

void Person::Show() const
{
    std::cout << "Last name: " << lname << "\n";
    std::cout << "First name: " << fname << "\n";
}

void Person::FormalShow() const { std::cout << lname << ", " << fname << "\n"; }