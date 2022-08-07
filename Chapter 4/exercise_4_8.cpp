/**
 * @file exercise_4_8.cpp
 * @author Steven Aquino
 * @brief Do Programming Exercise 7 but use new to allocate a structure instead
 * of declaring a structure variable.Also have the program request the pizza
 * diameter before it requests the pizza company name.
 * @version 0.1
 * @date 2022-05-25
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <string>

struct Pizza {
    std::string companyName; // The company name of the pizza
    int diameter;            // The diameter of the pizza
    double weight;           // The weight of the pizza

    Pizza() {}

    /**
     * @brief Displays the pizza's information.
     *
     */
    void displayPizza() {
        std::cout << "Name of company: " << companyName << "\n";
        std::cout << "Diameter of the pizza: " << diameter << "\n";
        std::cout << "Weight of the pizza: " << weight << "\n";
    }
};

int main() {
    Pizza *example = new Pizza();

    std::cout << "Enter the diameter of the pizza: ";
    std::cin >> example->diameter; // -> is used when utilizing pointers

    std::cout << "Enter the name of the pizza company: ";
    std::cin.ignore(); // ignore() insures \n is removed and getline() works
    std::getline(std::cin, example->companyName);

    std::cout << "Enter the weight of the pizza: ";
    std::cin >> example->weight;

    example->displayPizza();

    delete example;

    return 0;
}