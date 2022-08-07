/**
 * @file exercise_5.cpp
 * @author Steven Aquino
 * @brief The Bank of Heather has performed a study showing that ATM customers
 * won't wait more than one minute in line. Using the simulation from
 * Listing 12.10, find a value for number of customers per hour that leads to an
 * average wait time of one minute. (Use at least a 100-hour trial period.)
 *
 * @version 0.1
 * @date 2022-08-05
 *
 * @copyright Copyright (c) 2022
 *
 */
// bank.cpp -- using the Queue interface
// compile with queue.cpp
#include "queue.h"
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
#include <iostream>
const int MIN_PER_HR = 60;

bool newcustomer(double x); // is there a new customer?

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
    // setting things up
    std::srand(std::time(0)); // random initializing of rand()

    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;

    cout << "Enter the number of simulation hours: ";
    int hours; // hours of simulation
    cin >> hours;

    // running the simulation until average wait time is at least one minute
    double average_wait_time = 0;
    double perhour;
    for (perhour = 1; average_wait_time < 1.0; perhour++) {
        Queue line(qs);
        long cyclelimit = MIN_PER_HR * hours; // # of cycles
        double min_per_cust = MIN_PER_HR / perhour;

        Item temp;          // new customer data
        long turnaways = 0; // turned away by full queue
        long customers = 0; // joined the queue
        long served = 0;    // served during the simulation
        long sum_line = 0;  // cumulative line length
        int wait_time = 0;  // time until autoteller is free
        long line_wait = 0; // cumulative time in line

        for (int cycle = 0; cycle < cyclelimit; cycle++) {
            if (newcustomer(min_per_cust)) // have newcomer
            {
                if (line.isfull()) {
                    turnaways++;
                }
                else {
                    customers++;
                    temp.set(cycle);    // cycle = time of arrival
                    line.enquene(temp); // add newcomer to line
                }
            }
            if (wait_time <= 0 && !line.isempty()) {
                line.dequeue(temp);       // attend next customer
                wait_time = temp.ptime(); // for wait_time minutes
                line_wait += cycle - temp.when();
                served++;
            }
            if (wait_time > 0) {
                wait_time--;
            }
            sum_line += line.queuecount();
        }

        average_wait_time = (double)line_wait / served;
    }

    std::cout << "\nNumber of customers per hour that leads to an average wait "
                 "time of one minute: "
              << perhour << '\n';
    std::cout << "Average wait time: " << average_wait_time << '\n';

    return 0;
}

// x = average time, in minutes, between customers
// return value is true if customer shows up this minute
bool newcustomer(double x) { return (std::rand() * x / RAND_MAX < 1); }