/**
 * @file exercise_1.cpp
 * @author Steven Aquino
 * @brief Modify the Tv and Remote classes as follows:
 *
 * a. Make them mutual friends
 * b. Add a state variable member to the Remote class that describes whether the
 * remote control is in normal or interactive mode.
 * c. Add a Remote method that displays the mode.
 * d. Provide the Tv class with a method for toggling the new Remote member.
 * This method should work only if the TV is in the on state.
 *
 * Write a short program that tests these new features.
 *
 * @version 0.1
 * @date 2022-08-19
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "tv.h"
#include <iostream>

int main()
{
    std::cout << "Creating a default:\n\n";
    Tv flat_screen;
    Remote tv;
    flat_screen.settings();
    tv.display_mode();

    std::cout << "\nTry to toggle the remote state:\n\n";
    flat_screen.toggle_remote(tv);
    flat_screen.settings();
    tv.display_mode();

    std::cout << "\nTurning on Tv and trying again!\n\n";
    flat_screen.onoff();
    flat_screen.toggle_remote(tv);
    flat_screen.settings();
    tv.display_mode();

    return 0;
}