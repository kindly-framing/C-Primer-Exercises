/**
 * @file exercise_5.cpp
 * @author Steven Aquino
 * @brief Mat and Pat want to invite their friends to a party, much as they did
 * in Programming Exercise 8 in Chapter 16, except now they want a program that
 * uses files. They have asked you to write a program that does the following:
 *
 * Reads a list of Mat's friends' names from a text file called mat.dat, which
 * lists one friend per line. The names are stored in a container and then
 * displayed in sorted order.
 *
 * Reads a list of Pat's friends' names from a text file called pat.dat, which
 * lists one friend per line. The names are stored in a container and then
 * displayed in sorted order.
 *
 * Merges the two lists, eliminating duplicates and stores the result in the
 * file matnpat.dat, one friend per line.
 *
 * @version 0.1
 * @date 2022-09-03
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

typedef string Friend;
vector<Friend> readFriends(ifstream &file);

int main()
{
    // store friends from files
    ifstream mat("mat.dat");
    vector<Friend> mats = readFriends(mat);
    ifstream pat("pat.dat");
    vector<Friend> pats = readFriends(pat);

    // merge the two friend lists
    vector<Friend> matnpats(mats.size() + pats.size());
    sort(mats.begin(), mats.end()); // both lists must be sorted before merging
    sort(pats.begin(), pats.end());
    merge(mats.begin(), mats.end(), pats.begin(), pats.end(), matnpats.begin());

    // remove duplicates from the merged list
    vector<Friend>::iterator it;
    it = std::unique(matnpats.begin(), matnpats.end());
    matnpats.resize(std::distance(matnpats.begin(), it));

    // place the merged list in output file
    ofstream output("matnpat.dat");
    for (Friend f : matnpats)
    {
        output << f << '\n';
    }

    // cleanup
    mat.close();
    pat.close();
    output.close();
    return 0;
}

vector<Friend> readFriends(ifstream &file)
{
    vector<Friend> res;
    Friend temp;
    while (file >> temp)
    {
        res.push_back(temp);
    }
    return res;
}