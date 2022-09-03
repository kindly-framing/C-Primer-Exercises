/**
 * @file exercise_2.cpp
 * @author Steven Aquino
 * @brief Write a program that copies your keyboard input (up to the simulated
 * end-of-file) to a file named on the command line.
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

int main()
{
    using namespace std;
    // get the file name for the output file from the user
    cout << "Enter the name for the output file: ";
    string filename;
    getline(cin, filename);
    ofstream output(filename);

    // read from input until simulated EOF is found (Ctrl+Z for Windows)
    cout << "File is open! Everything will be written to file. To terminate, "
            "use a simulated end-of-file\n";
    char c;
    while ((c = std::cin.get()) != EOF)
    {
        output << c;
    }
    output.close();
    cout << "Bye!\n";
    return 0;
}