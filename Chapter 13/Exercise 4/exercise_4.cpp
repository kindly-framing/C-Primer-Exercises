/**
 * @file exercise_4.cpp
 * @author Steven Aquino
 * @brief The Benevolent Order of Programmers maintains a collection of bottled
 * port. To describe it, the BOP Portmaster has devised a Port class.
 *
 * The Portmaster completed the method definitions for the Port class and then
 * derived the VintagePort class as follows before being relieved of his
 * position for accidentally routing a bottle of '45 Cockburn to someone
 * preparing an experimental barbecue sauce.
 *
 * You get the job of completing the VintagePort work.
 *
 * a. Your first task is to re-create the Port method definitions because the
 * former Portmaster immolated his upon being relieved.
 * b. Your second task is to explain why certain methods are redefined and
 * others are not.
 * c. Your third task is to explain why operator=() and operator<<() are not
 * virtual.
 * d. Your fourth task is to provide definitions for the VintagePort methods.
 *
 * @version 0.1
 * @date 2022-08-13
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "port.h"

int main()
{
    Port pe("Gallo", "tawny", 20);
    VintagePort pe2("Philips", 10, "The Noble", 2000);

    VintagePort pe3(pe2);

    pe2 -= 10;
    cout << pe2 << endl;
    cout << pe3 << endl;
    cout << "------------------------\n";

    VintagePort pe4;
    pe4 = pe3;
    pe3 += 5;
    cout << pe3 << endl;
    cout << pe4 << endl;

    cout << "------------------------\n";
    Port *pt = &pe4;
    pt->Show();
    cout << pt->BottleCount() << " bottles\n";
    cout << "------------------------\n";
    cout << "Done\n";
}