/**
 * @file exercise_4.cpp
 * @author Steven Aquino
 * @brief Write a program that opens two text files for input and one for
 * output. The program should concatenate the corresponding lines of the input
 * files, use a space as a seperator, and write the results to the output file.
 * If one file is shorter than the other, the remaining lines in the longer file
 * should also be copied to the output file. For example, suppose the first
 * input file has these contents:
 * eggs kites donuts
 * balloons hammers
 * stones
 *
 * And suppose the second input file has these contents:
 * zero lassitude
 * finance drama
 *
 * The resulting file would have these contents:
 * eggs kites donuts zero lassitude
 * balloons hammers finance drama
 * stones
 *
 * @version 0.1
 * @date 2022-09-02
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <fstream>
#include <string>

int main()
{
    using namespace std;
    // open both of the input files
    ifstream input1("in1.txt");
    ifstream input2("in2.txt");
    ofstream output("out.txt");

    // loop thorough both
    string line1, line2;
    while (!input1.eof() && !input2.eof())
    {
        getline(input1, line1);
        getline(input2, line2);
        output << line1 << " " << line2 << '\n';
    }
    while (!input2.eof())
    {
        getline(input2, line2);
        output << line2 << '\n';
    }
    while (!input1.eof())
    {
        getline(input1, line1);
        output << line1 << '\n';
    }

    // close files
    input1.close();
    input2.close();
    output.close();
    return 0;
}