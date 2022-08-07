/**
 * @file exercise_6_3.cpp
 * @author Steven Aquino
 * @brief Write a precursor to a menu-driven program.The program should display
 * a menu offering four choices, each labeled with a letter. If the user
 * responds with a letter other than one of the four valid choices, the program
 * should prompt the user to enter a valid response until the user complies.
 * Then the program should use a switch to select a simple action based on the
 * user’s selection. A program run could look something like this:
 *
 * Please enter one of the following choices:
 * c) carnivore p) pianist t) tree g) game
 * f
 * Please enter a c, p, t, or g: q
 * Please enter a c, p, t, or g: t
 * A maple is a tree.
 * @version 0.1
 * @date 2022-06-10
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <string>

int main() {
    std::cout << "Please enter one of the following choices:\n";
    std::cout << "c) carnivore\tp) pianist\nt) tree\tg) game\n";

    std::string in;
    std::getline(std::cin, in);

    bool selected = false;
    while (!selected) {
        switch (in[0]) {
        case 'c':
            std::cout << "A lion is a carnivore.\n";
            selected = false;
            break;
        case 'p':
            std::cout << "Max is a pianist.\n";
            selected = false;
            break;
        case 't':
            std::cout << "A maple is a tree.\n";
            selected = false;
            break;
        case 'g':
            std::cout << "Doom is a game\n";
            selected = false;
            break;
        default:
            std::cout << "Please enter a c, p, t, or g: ";
            std::getline(std::cin, in);
            break;
        }
    }

    return 0;
}