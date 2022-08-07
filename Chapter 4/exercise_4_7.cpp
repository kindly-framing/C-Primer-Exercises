/**
 * @file exercise_4_7.cpp
 * @author Steven Aquino
 * @brief William Wingate runs a pizza-analysis service. For each pizza, he
 * needs to record the following information:
 * The name of the pizza company, which can consist of more than one word
 * The diameter of the pizza
 * The weight of the pizza
 * Devise a structure that can hold this information and
 * write a program that uses a structure variable of that type.The program
 * should ask the user to enter each of the preceding items of information,and
 * then the program should display that information. Use cin (or its methods)
 * and cout.
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
        std::cout << companyName << "\n";
        std::cout << diameter << "\n";
        std::cout << weight << "\n";
    }
};

int main() {
    Pizza example; // Saving the information entered here

    std::cout << "Enter the name of the company: ";
    // The name can consist of more than one word
    std::getline(std::cin, example.companyName);

    std::cout << "Enter the diameter of the pizza: ";
    std::cin >> example.diameter;

    std::cout << "Enter the weight of the pizza: ";
    std::cin >> example.weight;

    example.displayPizza();

    return 0;
}