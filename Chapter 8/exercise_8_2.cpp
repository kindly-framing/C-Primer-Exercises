/**
 * @file exercise_8_2.cpp
 * @author Steven Aquino
 * @brief The CandyBar structure contains three members.The first member holds
 * the brand name of a candy bar.The second member holds the weight (which may
 * have a fractional part) of the candy bar,and the third member holds the
 * number of calories (an integer value) in the candy bar.Write a program that
 * uses a function that takes as arguments a reference to CandyBar,a
 * pointer-to-char, a double,and an int and uses the last three values to set
 * the corresponding members of the structure.The last three arguments should
 * have default values of “Millennium Munch,” 2.85,and 350. Also the program
 * should use a function that takes a reference to a CandyBar as an argument and
 * displays the contents of the structure. Use const where appropriate.
 * @version 0.1
 * @date 2022-07-01
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <string>

struct CandyBar {
    std::string brand_name;
    double weight;
    int calories;
};

void create(CandyBar& x, std::string name = "Millennium Crunch",
            double weight = 2.85, int calories = 350);
void display(const CandyBar);

int main()
{
    CandyBar def;
    create(def);
    display(def);

    CandyBar crunch;
    create(crunch, "Crunchy", 5.45, 220);
    display(crunch);

    return 0;
}

void create(CandyBar& x, std::string name, double weight, int calories)
{
    x.brand_name = name;
    x.weight = weight;
    x.calories = calories;
}

void display(const CandyBar x)
{
    std::cout << "Brand Name: " << x.brand_name << "\n";
    std::cout << "Weight: " << x.weight << "\n";
    std::cout << "Calories: " << x.calories << "\n";
}