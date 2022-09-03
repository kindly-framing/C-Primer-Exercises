/**
 * @file exercise_3.cpp
 * @author Steven Aquino
 * @brief Write a program that copies one file to another. Have the program take
 * the filenames from the command line. Have the program report if it cannot
 * open a file.
 *
 * @version 0.1
 * @date 2022-09-02
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void copyFrom(ifstream &f1, ofstream &f2);

int main()
{
    // get the input and output file (report if it cannot open)
    cout << "Enter the file name to copy from: ";
    string filename;
    getline(cin, filename);
    ifstream inputFile(filename);
    if (inputFile.is_open())
    {
        cout << "Enter the file name to copy to: ";
        getline(cin, filename);
        ofstream outputFile(filename);
        copyFrom(inputFile, outputFile);
        inputFile.close();
        outputFile.close();
    }
    else
    {
        std::cout << "Unable to open input file!\n";
    }

    cout << "Bye!\n";
    return 0;
}

void copyFrom(std::ifstream &f1, std::ofstream &f2)
{
    char c;
    while ((c = f1.get()) != EOF)
    {
        f2 << c;
    }
}