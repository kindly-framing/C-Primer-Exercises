/**
 * @file exercise_10_5.cpp
 * @author Steven Aquino
 * @brief Consider the following structure declaration:
 *
 * struct customer {
 * char fullname[35];
 * double payment;
 * };
 *
 * Write a program that adds and removes customer structures from a stack,
 * represented by a Stack class declaration. Each time a customer is removed,
 * his or her payment should be added to a running total,and the running total
 * should be reported. Note: You should be able to use the Stack class
 * unaltered; just change the typedef declaration so that Item is type customer
 * instead of unsigned long.
 *
 * @version 0.1
 * @date 2022-07-14
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "customer.h"
#include "stack.h"
#include <iostream>

using namespace std;

int menu_input();
void add(Customer &x, Stack &y);
double remove(Customer &x, Stack &y);

int main()
{
    Stack customers;
    Customer tmp;

    double total = 0.0;
    do {
        cout << "Running removed total: " << total << "\n";
        int i = menu_input();

        switch (i) {
        case 1:
            add(tmp, customers);
            break;
        case 2:
            total += remove(tmp, customers);
            break;
        default:
            cout << "Try again!";
            break;
        }
    } while (!customers.isempty());

    cout << "Stack is empty! The final total is " << total << "\n";
    return 0;
}

int menu_input()
{
    int in;
    cout << "Would you like to add or remove customer from stack?\n";
    cout << "1: Add\n2: Remove\n";
    cin >> in;
    cin.ignore();
    return in;
}

void add(Customer &x, Stack &y)
{
    x.set();
    if (y.push(x)) {
        system("cls");
        cout << "Successfully added " << x.fullname << "'s payment of "
             << x.payment << ".\n";
    }
    else {
        cout << "The stack is full!\n";
    }
}

double remove(Customer &x, Stack &y)
{
    if (y.pop(x)) {
        system("cls");
        cout << "Removed " << x.fullname
             << " and added their payment to total.\n";
        return x.payment;
    }

    cout << "Stack is empty!\n";
    return 0;
}

void Customer::set()
{
    cout << "Enter the name of the customer: ";
    cin.getline(this->fullname, 35);

    cout << "Enter the payment of the customer: ";
    cin >> this->payment;
    cin.ignore();
}