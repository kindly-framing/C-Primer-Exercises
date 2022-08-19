/**
 * @file exercise_3.cpp
 * @author Steven Aquino
 * @brief Define a QueueTp template. Test it by creating a queue of
 * pointers-to-Worker (as defined in Listing 14.10) and using the queue in a
 * program similar to that in Listing 14.12.
 *
 * @version 0.1
 * @date 2022-08-15
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <cstring>
#include <iostream>

#include "queuetp.h"
#include "workermi.h"
const int SIZE = 5;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;

    Queue<Worker *> lolas;
    Worker *add;

    int ct;
    for (ct = 0; ct < SIZE; ct++)
    {
        char choice;
        cout << "Enter the employee category:\n"
             << "w: waiter s: singer  "
             << "t: singing waiter q: quit\n";
        cin >> choice;
        while (strchr("wstq", choice) == NULL)
        {
            cout << "Please enter a w, s, t, or q: ";
            cin >> choice;
        }
        if (choice == 'q')
        {
            break;
        }
        switch (choice)
        {
        case 'w':
            add = new Waiter;
            break;
        case 's':
            add = new Singer;
            break;
        case 't':
            add = new SingingWaiter;
            break;
        }
        cin.get();
        add->Set();
        lolas.enquene(add);
    }

    cout << "\nHere is your staff:\n";
    int i;
    for (i = 0; i < ct; i++)
    {
        cout << endl;
        Worker *removed;
        lolas.dequeue(removed);
        removed->Show();
    }
    lolas.~Queue();
    cout << "Bye.\n";
    return 0;
}