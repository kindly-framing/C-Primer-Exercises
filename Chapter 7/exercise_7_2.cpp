/**
 * @file exercise_7_2.cpp
 * @author Steven Aquino
 * @brief Write a program that asks the user to enter up to 10 golf scores,
 * which are to be stored in an array.You should provide a means for the user to
 * terminate input prior to entering 10 scores.The program should display all
 * the scores on one line and report the average score. Handle input,
 * display,and the average calculation with three separate array-processing
 * functions.
 * @version 0.1
 * @date 2022-06-15
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <vector>

void display(std::vector<double> scores)
{
    for (double score : scores) {
        std::cout << score << " ";
    }
    std::cout << "\n";
}

std::vector<double> input()
{
    std::vector<double> nums;

    std::cout << "Enter at least 10 golf scores or q to print average:\n";

    std::string input;
    while (std::cin >> input) {
        if (tolower(input[0]) == 'q' && input.size() == 1) {
            break;
        }

        double score;
        try {
            score = std::stod(input);
        }
        catch (const std::invalid_argument &e) {
            std::cout << "Not valid! Try again...";
        }
        nums.push_back(score);
    }

    return nums;
}

double average(std::vector<double> nums)
{
    double sum = 0;

    for (double n : nums) {
        sum += n;
    }

    return sum / nums.size();
}

int main()
{
    std::vector<double> scores = input();
    display(scores);
    std::cout << "Average of scores: " << average(scores);
    return 0;
}