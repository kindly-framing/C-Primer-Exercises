/**
 * @file exercise_4.cpp
 * @author Steven Aquino
 * @brief A Person class holds the first name and the last name of a person. In
 * addition to its constructors, it has a Show() method that displays both
 * names. A Gunslinger class derives virtually from the Person class. It has a
 * Draw() member that returns a type double value representing a gunslinger's
 * draw time. The class also has an int member representing the number of
 * notches of a gunslinger's gun. Finally, it has a Show() function that
 * displays all this information.
 *
 * A PokerPlayer class derives virtually from the person class. It has a Draw()
 * member that returns a random number in the range 1 through 52, representing a
 * card value. The PokerPlayer class uses the Person show() function. The
 * BadDude class dervies publicly from the Gunslinger and PokerPlayer classes.
 * It has a Gdraw() member that returns a bad dude's draw time aand a Cdraw()
 * member that returns the next card drawn. It has an appropriate Show()
 * function. Define all these classes and methods, along with any other
 * necessary methods (such as methods for setting object values) and test them
 * in a simple program similar to that in Listing 14.12.
 *
 * @version 0.1
 * @date 2022-08-17
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "person.h"
#include <cstring>
#include <iostream>
const int SIZE = 5;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;

    Person *people[5];

    for (int ct = 0; ct < SIZE; ct++)
    {
        char choice;
        cout << "Enter the Person category:\n"
             << "g: gunslinger  p: poker player  "
             << "b: bad dude  q: quit\n";
        cin >> choice;
        while (strchr("gpbq", choice) == NULL)
        {
            cout << "Please enter a g, p, b, or q: ";
            cin >> choice;
        }
        if (choice == 'q')
        {
            break;
        }
        switch (choice)
        {
        case 'g':
            people[ct] = new Gunslinger;
            break;
        case 'p':
            people[ct] = new PokerPlayer;
            break;
        case 'b':
            people[ct] = new BadDude;
            break;
        }
        cin.get();
        people[ct]->Set();
    }

    cout << "\nHere are your people:\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << endl;
        people[i]->Show();
    }
    for (int i = 0; i < SIZE; i++)
    {
        delete people[i];
    }
    cout << "Bye.\n";
    return 0;
}