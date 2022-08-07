/**
 * @file exercise_8.cpp
 * @author Steven Aquino
 * @brief Design a List class to represent this abstract type. You should
 * provide a list.h header file with the class declaration and a list.cpp file
 * with the class method implementations. You should also create a short program
 * that utilizes your design. The main reason for keeping the list specification
 * simple is to simplify this programming exercise. You can implement the list
 * as an array or, if you’re familiar with the data type, as a linked list. But
 * the public interface should not depend on your choice. That is, the public
 * interface should not have array indices, pointers to nodes, and so on. It
 * should be expressed in the general concepts of creating a list, adding an
 * item to the list, and so on. The usual way to handle visiting each item and
 * performing an action is to use a function that takes a function pointer as an
 * argument:
 *
 * void visit(void (*pf)(Item &));
 *
 * Here pf points to a function (not a member function) that takes a reference
 * to Item argument, where Item is the type for items in the list. The visit()
 * function applies this function to each item in the list. You can use the
 * Stack class as a general guide.
 *
 * @version 0.1
 * @date 2022-07-15
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "list.h"
#include <iostream>

using namespace std;

void print(Item &x) { std::cout << x << " "; }

int main()
{
    using namespace std;

    List x;

    cout << "List should be empty: " << x.is_empty() << endl;

    cout << "Adding {1, 2, 3, 4, 5} to list..." << endl;
    for (int i = 1; i <= 5; i++) {
        x.add(i);
    }

    x.visit(print);
    cout << endl;

    cout << "The list should be full: " << x.is_full() << endl;

    return 0;
}