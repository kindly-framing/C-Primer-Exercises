/**
 * @file exercise_6.cpp
 * @author Steven Aquino
 * @brief Refer to exercise.txt.
 *
 * @version 0.1
 * @date 2022-09-03
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "emp2.h"
#include <cstring>
using namespace std;

char menu_entry();
int main()
{
    using namespace std;
    const int MAX = 5;  // no more than 5 objects
    abstr_emp *pc[MAX]; // container for employees entered
    int entered = 0;    // amount of employees entered in current run
    int total = 0;      // amount of total employees

    // display save data, if it exists
    ifstream fin("savedata.dat");
    if (fin.is_open())
    {
        int classtype;
        char ch;
        while ((fin >> classtype).get(ch)) // newline seperates int from data
        {
            switch (classtype)
            {
            case Employee:
                pc[total] = new employee;
                break;
            case Manager:
                pc[total] = new manager;
                break;
            case Fink:
                pc[total] = new fink;
                break;
            case HighFink:
                pc[total] = new highfink;
                break;
            }
            pc[total++]->GetAll(fin);
        }
        cout << "Employees in save file:\n";
        for (int i = 0; i < total; i++)
        {
            pc[i]->ShowAll();
        }
        fin.close();
    }

    // menu entry for employees
    while (entered + total < MAX)
    {
        char choice = menu_entry();
        if (choice == 'q')
        {
            break;
        }

        int index = (total == 0) ? entered : total + entered;
        switch (choice - '0')
        {
        case Employee:
            pc[index] = new employee;
            break;
        case Manager:
            pc[index] = new manager;
            break;
        case Fink:
            pc[index] = new fink;
            break;
        case HighFink:
            pc[index] = new highfink;
            break;
        }
        cin.get();
        pc[index]->SetAll();
        entered++;
    }

    if (entered != 0)
    {
        // show all employees
        for (int i = 0; i < total + entered; i++)
        {
            pc[i]->ShowAll();
        }

        // write all NEW employees to output file
        ofstream fout("savedata.dat");
        for (int i = 0; i < total + entered; i++)
        {
            pc[i]->WriteAll(fout);
        }
        fout.close();
    }

    // cleanup
    for (int i = 0; i < total; i++)
    {
        delete pc[i];
    }
    cout << "Bye!\n";
    return 0;
}

char menu_entry()
{
    cout << "What employee would you like to add? <q to quit>\n"
         << "0.employee\t1.manager\n2.fink\t3.highfink\n";
    char choice;
    cin >> choice;
    while (strchr("0123q", choice) == NULL)
    {
        cout << "Please enter a 0, 1, 2, 3 or q: ";
        cin >> choice;
    }
    return choice;
}