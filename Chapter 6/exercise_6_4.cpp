/**
 * @file exercise_6_4.cpp
 * @author Steven Aquino
 * @brief When you join the Benevolent Order of Programmers, you can be known at
 * BOP meetings by your real name, your job title, or your secret BOP name.Write
 * a program that can list members by real name, by job title, by secret name,
 * or by a member’s preference. Base the program on the following structure:
 * // Benevolent Order of Programmers name structure
 * struct bop {
 *   char fullname[strsize]; // real name
 *   char title[strsize]; // job title
 *   char bopname[strsize]; // secret BOP name
 *   int preference; // 0 = fullname, 1 = title, 2 = bopname
 * };
 * In the program, create a small array of such structures and initialize it to
 * suitable values. Have the program run a loop that lets the user select from
 * different alternatives:
 * a. display by name b. display by title
 * c. display by bopname d. display by preference
 * q. quit
 *
 * Note that “display by preference” does not mean display the preference
 * member; it means display the member corresponding to the preference number.
 * For instance, if preference is 1, choice d would display the programmer’s job
 * title.A sample run may look something like the following:
 * Benevolent Order of Programmers Report
 * a. display by name b. display by title
 * c. display by bopname d. display by preference
 * q. quit
 * Enter your choice: a
 * Wimp Macho
 * Raki Rhodes
 * Celia Laiter
 * Hoppy Hipman
 * Pat Hand
 * Next choice: d
 * Wimp Macho
 * Junior Programmer
 * MIPS
 * Analyst Trainee
 * LOOPY
 * Next choice: q
 * Bye!
 * @version 0.1
 * @date 2022-06-10
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <string>
#include <vector>

// Benevolent Order of Programmers name strcuture
struct Bop {
    std::string fullname; // real name
    std::string title;    // job title
    std::string bopname;  // secret BOP name
    int preference;       // 0 = fullname, 1 = title, 2 = bopname

    Bop(std::string name_, std::string title_, std::string bopname_,
        int preference_) {
        fullname = name_;
        title = title_;
        bopname = bopname_;
        preference = preference_;
    }

    void displayName() { std::cout << fullname; }
    void displayTitle() { std::cout << title; }
    void displayBopName() { std::cout << bopname; }
    void displayPreference() {
        if (preference == 0) {
            displayName();
        } else if (preference == 1) {
            displayTitle();
        } else {
            displayBopName();
        }
    }
};

std::vector<Bop> initializeReport();

int main() {
    std::vector<Bop> members = initializeReport();

    std::cout << "a. display by name \tb. display by title \nc. display by "
                 "bopname \td. display by preference \nq. quit\n";

    char chr;
    std::cin >> chr; // Assuming input is always correct.

    while (chr != 'q') {
        switch (chr) {
        case 'a':
            for (Bop member : members) {
                member.displayName();
                std::cout << "\n";
            }
            break;
        case 'b':
            for (Bop member : members) {
                member.displayTitle();
                std::cout << "\n";
            }
            break;
        case 'c':
            for (Bop member : members) {
                member.displayBopName();
                std::cout << "\n";
            }
            break;
        case 'd':
            for (Bop member : members) {
                member.displayPreference();
                std::cout << "\n";
            }
            break;
        default:
            std::cout << "Not a valid option!\n";
            break;
        }

        std::cin >> chr;
    }

    std::cout << "Bye!\n";
    return 0;
}

std::vector<Bop> initializeReport() {
    std::vector<Bop> report;

    Bop wimp("Wimp Macho", "President", "BOP1", 0);
    Bop raki("Raki Rhodes", "Junior Programmer", "BOP2", 1);
    Bop celia("Celia Laiter", "Senior Programmer", "MIPS", 2);
    Bop hoppy("Hoppy Hipman", "Analyst Trainee", "BOP3", 1);
    Bop pat("Pat Hand", "Junior Programmer", "LOOPY", 2);

    report.push_back(wimp);
    report.push_back(raki);
    report.push_back(celia);
    report.push_back(hoppy);
    report.push_back(pat);

    return report;
}