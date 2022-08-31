/**
 * @file exercise_7.cpp
 * @author Steven Aquino
 * @brief A common game is the lottery card. The card has numbered spots of
 * which a certain number are selected at random. Write a Lotto() function that
 * takes two arguments. The first should be the number of spots on a lottery
 * card, and the second should be the number of spots selected at random. The
 * function should return a vector<int> object that contains, in sorted order,
 * the numbers selected at random. For example, you could use the function as
 * follows:
 *
 * vector<int> winners;
 * winners = Lotto(51,6);
 *
 * This would assign to winners a vector that contains six numbers selected
 * random from the range 1 through 51. Note that simply using rand() doesn't
 * quite do the job because it may produce duplicate values. Suggestion: Have
 * the function create a vector that contains all the possible values, use
 * random_shuffle(), and then use the beginning of the shuffled vector to obtain
 * the values. Also write a short program that lets you test the function.
 *
 * @version 0.1
 * @date 2022-08-30
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>
using std::vector;

vector<int> Lotto(const int &spots, const int &selections);
void display(vector<int> vec);

std::random_device rd;
std::mt19937 g(rd());
const int NUM_OF_CARDS = 5;

int main()
{
    vector<int> winners; // stores the winning card
    for (int i = 0; i < NUM_OF_CARDS; i++)
    {
        winners = Lotto(51, 6);
        display(winners);
    }
    return 0;
}

vector<int> Lotto(const int &spots, const int &selections)
{
    // create a vector that contains all the possible values
    vector<int> card(spots);
    std::iota(card.begin(), card.end(), 1);
    // use random shuffle
    std::shuffle(card.begin(), card.end(), g);
    // use the beginning of the shuffled vector to obtain the values
    vector<int> res(card.begin(), card.begin() + selections);
    std::sort(res.begin(), res.end());
    return res;
}

void display(vector<int> vec)
{
    for (auto &&i : vec)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}