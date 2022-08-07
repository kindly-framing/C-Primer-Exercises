/**
 * @file exercise_4_1.cpp
 * @author Steven Aquino
 * @brief Write a C++ program that requests and displays information as shown in
 * the following example of output:
 * What is your first name? Betty Sue
 * What is your last name? Yewe
 * What letter grade do you deserve? B
 * What is your age? 22
 * Name: Yewe, Betty Sue
 * Grade: C
 * Age: 22
 *
 * Note that the program should be able to accept first names that comprise more
 * than one word.Also note that the program adjusts the grade downward—that is,
 * up one letter.Assume that the user requests an A,a B, or a C so that you
 * don’t have to worry about the gap between a D and an F
 * @version 0.1
 * @date 2022-05-22
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <string>

struct Student
{
    std::string firstName; // First or middle name of the student
    std::string lastName;  // Last name of the student
    char grade;            // The letter grade for the student
    int age;               // The age of the student

    void displayFullName()
    {
        std::cout << "Name: " << lastName << ", " << firstName << "\n";
    }

    void displayGrade() { std::cout << "Grade: " << grade << "\n"; }

    void displayAge() { std::cout << "Age: " << age << "\n"; }
};

char adjustGradeDownward(char grade)
{
    // Assuming grade is uppercase and valid letter
    char adjustedGrade;

    // Don't grade downward if D (68)
    if (grade > 68)
    {
        adjustedGrade = grade;
    }
    else
    {
        adjustedGrade = grade + 1; // Using ascii value
    }

    return adjustedGrade;
}

int main()
{
    Student example;

    std::cout << "What is your first name? ";
    std::getline(std::cin, example.firstName);

    std::cout << "What is your last name? ";
    std::getline(std::cin, example.lastName);

    // Adjust the grade downward
    std::cout << "What letter grade do you deserve? ";
    std::cin >> example.grade;
    example.grade = adjustGradeDownward(example.grade);

    std::cout << "What is your age? ";
    std::cin >> example.age;

    example.displayFullName();
    example.displayGrade();
    example.displayAge();

    return 0;
}