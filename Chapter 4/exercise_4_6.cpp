/**
 * @file exercise_4_6.cpp
 * @author Steven Aquino
 * @brief The CandyBar structure contains three members,as described in
 * Programming Exercise 5.Write a program that creates an array of three
 * CandyBar structures, initializes them to values of your choice,and then
 * displays the contents of each structure.
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

    CandyBar() {} // The first line won't work without this

    /**
     * @brief Construct a new Candy Bar object
     *
     * @param name_ The name of the bar
     * @param weight_ The weight of the bar (can be fractional)
     * @param calories_ The calories of the bar (cannot be fractional)
     */
    CandyBar(std::string name_, double weight_, int calories_) {
        brandName = name_;
        weight = weight_;
        calories = calories_;
    }

    /**
     * @brief Displays the bar's information.
     *
     */
    void displayBar() {
        std::cout << "Candy bar name: " << brandName << "\n";
        std::cout << "Weight of bar: " << weight << "\n";
        std::cout << "Amount of calories: " << calories << "\n";
    }
};

int main() {
    CandyBar bars[3]; // Declares array of candy bars

    // Assigning candy bars to the array
    bars[0] = CandyBar("Mocha Munch", 2.3, 350);
    bars[1] = CandyBar("Hershey", 2.1, 245);
    bars[2] = CandyBar("Snickers", 1.6, 250);

    // Displaying each bar in the array
    int len = sizeof(bars) / sizeof(bars[0]);
    for (int i = 0; i < len; i++) {
        bars[i].displayBar();
    }

    return 0;
}