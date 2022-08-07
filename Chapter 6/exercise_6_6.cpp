/**
 * @file exercise_6_6.cpp
 * @author Steven Aquino
 * @brief . Put together a program that keeps track of monetary contributions to
 * the Society for the Preservation of Rightful Influence. It should ask the
 * user to enter the number of contributors and then solicit the user to enter
 * the name and contribution of each contributor.The information should be
 * stored in a dynamically allocated array of structures. Each structure
 * should have two members:a character array (or else a string object) to store
 * the name and a double member to hold the amount of the contribution.After
 * reading all the data, the program should display the names and amounts
 * donated for all donors who contributed $10,000 or more.This list should
 * Programming Exercises 303 be headed by the label Grand Patrons.After that,
 * the program should list the remaining donors.That list should be headed
 * Patrons. If there are no donors in one of the categories, the program should
 * print the word “none.”Aside from displaying two categories, the program need
 * do no sorting.
 * @version 0.1
 * @date 2022-06-12
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <string>

struct Contributor {
    std::string name;
    double contribution;

    Contributor() {}

    Contributor(std::string name_, double contribution_) {
        name = name_;
        contribution = contribution_;
    }

    void display() { std::cout << name << " " << contribution << "\n"; }
};

int main() {
    std::cout << "Enter number of contributors: ";
    int numOfContributors;
    std::cin >> numOfContributors;

    Contributor *list = new Contributor[numOfContributors];

    // Getting the contributors, contributions, and count of grand/reg patrons
    int grandPatrons = 0;
    int patrons = 0;
    for (int i = 0; i < numOfContributors; i++) {
        std::cout << "Enter name of contributor: ";
        std::cin.ignore();
        std::string name;
        std::getline(std::cin, name);

        std::cout << "Enter contribution of contributor: ";
        double contribution;
        std::cin >> contribution;

        Contributor x(name, contribution);
        list[i] = x;

        (contribution >= 10'000) ? grandPatrons++ : patrons++;
    }

    // Displaying the list for grand patrons
    std::cout << "Grand Patrons\n";
    if (grandPatrons == 0) {
        std::cout << "none\n";
    } else {
        for (int i = 0; i < numOfContributors; i++) {
            Contributor x = list[i];
            if (x.contribution >= 10'000) {
                x.display();
            }
        }
    }

    // Displaying the list for regular patrons
    std::cout << "Patrons\n";
    if (patrons == 0) {
        std::cout << "none\n";
    } else {
        for (int i = 0; i < numOfContributors; i++) {
            Contributor x = list[i];
            if (x.contribution < 10'000) {
                x.display();
            }
        }
    }

    delete list;

    return 0;
}