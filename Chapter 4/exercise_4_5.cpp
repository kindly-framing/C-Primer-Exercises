/**
 * @file exercise_4_5.cpp
 * @author Steven Aquino
 * @brief The CandyBar structure contains three members.The first member holds
 * the brand name of a candy bar.The second member holds the weight (which may
 * have a fractional part) of the candy bar,and the third member holds the
 * number of calories (an integer value) in the candy bar.Write a program that
 * declares such a structure and creates a CandyBar variable called snack,
 * initializing its members to "Mocha Munch", 2.3,and 350, respectively.The
 * initialization should be part of the declaration for snack. Finally, the
 * program should display the contents of the snack variable.
 * @version 0.1
 * @date 2022-05-25
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <string>

struct CandyBar {
    std::string brandName; // Brand name for the candy bar
    double weight;         // Weight may have a fractional part
    int calories;          // Calories won't have a fractional part

    CandyBar(std::string name_, double weight_, int calories_) {
        brandName = name_;
        weight = weight_;
        calories = calories_;
    }

    void displayBar() {
        std::cout << "Candy bar name: " << brandName << "\n";
        std::cout << "Weight of bar: " << weight << "\n";
        std::cout << "Amount of calories: " << calories << "\n";
    }
};

int main() {
    CandyBar snack("Mocha Munch", 2.3, 350);
    snack.displayBar();
    return 0;
}