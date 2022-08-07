/**
 * @file exercise_6_9.cpp
 * @author Steven Aquino
 * @brief Do Programming Exercise 6 but modify it to get information from a
 * file.The first item in the file should be the number of contributors,and the
 * rest of the file should consist of pairs of lines, with the first line of
 * each pair being a contributor’s name and the second line being a
 * contribution.That is, the file should look like this:
 * 4
 * Sam Stone
 * 2000
 * Freida Flass
 * 100500
 * Tammy Tubbs
 * 5000
 * Rich Raptor
 * 55000
 * @version 0.1
 * @date 2022-06-12
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <fstream>
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
    std::fstream myfile("exercise_6_9.txt"); // Opening the text file

    // First line is the number of contributors
    int numOfContributors;
    myfile >> numOfContributors;
    Contributor *list = new Contributor[numOfContributors];

    int grandPatrons = 0; // Contributions greater than or equal to 10,000
    int patrons = 0;      // Contributions less than 10,000

    // Gathering the contributors from the text file
    if (myfile.is_open()) {
        int index = 0; // Needed to save to patron list

        while (myfile) {
            std::string name;
            myfile.ignore();
            std::getline(myfile, name);

            double contribution;
            myfile >> contribution;
            (contribution >= 10'000) ? grandPatrons++ : patrons++;

            Contributor x(name, contribution);
            list[index] = x;
            index++;

            // Ensures the last line isn't read again.
            if (myfile.eof()) {
                break;
            }
        }

    } else {
        std::cout << "Couldn't open file!\n";
    }

    // Displaying the list for grand patrons
    std::cout << "Grand Patrons\n";
    if (grandPatrons == 0) {
        std::cout << "none\n";
    } else {
        for (int i = 0; i < numOfContributors; i++) {
            Contributor x = list[i];
            if (x.contribution >= 10'000) {
                std::cout << "\t";
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
                std::cout << "\t";
                x.display();
            }
        }
    }

    return 0;
}