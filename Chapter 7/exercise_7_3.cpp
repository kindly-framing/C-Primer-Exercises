/**
 * @file exercise_7_3.cpp
 * @author Steven Aquino
 * @brief Here is a structure declaration:
 * struct box
 * {
 * char maker[40];
 * float height;
 * float width;
 * float length;
 * float volume;
 * };
 * a. Write a function that passes a box structure by value and that displays
 * the value of each member.
 * b. Write a function that passes the address of a box structure and that sets
 * the volume member to the product of the other three dimensions.
 * c. Write a simple program that uses these two functions.
 * @version 0.1
 * @date 2022-06-15
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <string>

struct Box {
    std::string maker;
    float height;
    float width;
    float length;
    float volume;
};

void display(Box a)
{
    std::cout << "Maker: " << a.maker << "\n";
    std::cout << "Box Length: " << a.length << "\n";
    std::cout << "Box Width: " << a.width << "\n";
    std::cout << "Box Height: " << a.height << "\n";
    std::cout << "Box Volume: " << a.volume << "\n";
}

void calculateBoxVolume(Box &a) { a.volume = a.height * a.length * a.width; }

int main()
{
    Box a;
    a.maker = "Steven";
    a.height = 5.0;
    a.length = 5.0;
    a.width = 5.0;

    calculateBoxVolume(a);
    display(a);

    return 0;
}