/**
 * @file exercise_8.cpp
 * @author Steven Aquino
 * @brief Mat and Pat want to invite their friends to a party. They ask you to
 * write a program that does the following:
 *
 * Allows Mat to enter a list of his friends' names. The names are stored in a
 * container and then displayed in sorted order.
 *
 * Allows Pat to enter a list of her friends' names. The names are stored in a
 * second container and then displayed in sorted order.
 *
 * Creates a third container that mergers the two lists, eliminates duplicates,
 * and displays the contents of this container.
 *
 * @version 0.1
 * @date 2022-08-31
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;

vector<string> input_friends(const string &filename);
vector<string> merge_friends(const vector<string> &v1,
                             const vector<string> &v2);
void display_friends(const vector<string> &names, const string &name = "");

int main()
{
    vector<string> mat = input_friends("mat.txt");
    display_friends(mat, "Mat");

    vector<string> pat = input_friends("pat.txt");
    display_friends(pat, "Pat");

    vector<string> merged = merge_friends(mat, pat);
    display_friends(merged);

    return 0;
}

vector<string> input_friends(const string &filename)
{
    vector<string> friends;
    std::ifstream file(filename);
    if (file.is_open())
    {
        std::string name;
        while (std::getline(file, name))
        {
            friends.push_back(name);
        }
        file.close();
    }
    else
    {
        std::cout << "Unable to open file!";
    }
    std::sort(friends.begin(), friends.end());
    return friends;
}

vector<string> merge_friends(const vector<string> &v1, const vector<string> &v2)
{
    // merge() needs a container with enough elements to be replaced
    vector<string> res(v1.size() + v2.size());
    std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), res.begin());

    // removing duplicates from the merged list
    vector<string>::iterator it;
    it = std::unique(res.begin(), res.end());
    res.resize(std::distance(res.begin(), it));

    return res;
}

void display_friends(const vector<string> &names, const string &name)
{
    std::cout << ((name.empty()) ? "Friends:\n" : name + "'s friends:\n");
    for (auto &&n : names)
    {
        std::cout << n << '\n';
    }
    std::cout << '\n';
}