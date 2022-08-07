/**
 * @file exercise_7_7.cpp
 * @author Steven Aquino
 * @brief Redo Listing 7.7, modifying the three array-handling functions to each
 * use two pointer parameters to represent a range.The fill_array() function,
 * instead of returning the actual number of items read, should return a pointer
 * to the location after the last location filled; the other functions can use
 * this pointer as the second argument to identify the end of the data.
 * @version 0.1
 * @date 2022-06-30
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
using namespace std;

const int Max = 5;

// function prototypes
double *fill_array(double *first, double *last);
void show_array(double *first, double *last);  // don't change data
void revalue(double *first, double *last, double factor);

int main()
{
    double properties[Max];
    double *last;

    last = fill_array(properties, properties + Max);
    show_array(properties, last);

    cout << "Enter revaluation factor: ";
    double factor;
    cin >> factor;

    revalue(properties, last, factor);
    show_array(properties, last);
    cout << "Done.\n";

    return 0;
}

double *fill_array(double *first, double *last)
{
    double temp;
    double *pt;
    int i = 0;
    for (pt = first; pt != last; pt++, i++) {
        cout << "Enter value #" << (i + 1) << ": ";
        cin >> temp;
        if (!cin) {
            cin.clear();
            while (cin.get() != '\n') {
                continue;
            }
            cout << "Bad input; input process terminated.\n";
            break;
        }
        else if (temp < 0) {
            break;
        }
        *pt = temp;
    }
    return pt;
}

// the following function can use, but not alter,
// the array whose address is ar
void show_array(double *first, double *last)
{
    double *pt;
    int i = 0;
    for (pt = first; pt < last; pt++, i++) {
        cout << "Property #" << (i + 1) << ": $";
        cout << *pt << endl;
    }
}

// multiplies each element of ar[] by r
void revalue(double *first, double *last, double factor)
{
    double *pt;
    for (pt = first; pt < last; pt++) {
        *pt *= factor;
    }
}