/**
 * @file exercise_6.cpp
 * @author Steven Aquino
 * @brief The Bank of Heather would like to know what would happen if it added a
 * second ATM. Modify the simulation in this chapter so that it has two queues.
 * Assume that a customer will join the first queue if it has fewer people in it
 * than the second queue otherwise. Again, find a value for number of customers
 * per hour that leads to an average wait time of one minute. (NOTE: This is a
 * nonlinear problem in that doubling the number of ATMs doesn't double the
 * number of customers who can be handled per hour with a one-minute wait
 * maximum.)
 *
 * @version 0.1
 * @date 2022-08-05
 *
 * @copyright Copyright (c) 2022
 *
 */
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
    Queue line(qs);  // line queue holds up to qs people
    Queue line2(qs); // second line queue if first line is full

    cout << "Enter the number of simulation hours: ";
    int hours; // hours of simulation
    cin >> hours;

    double average_wait_time = 0;
    double perhour;
    for (perhour = 1; average_wait_time < 1.0; perhour++) {
        Queue line(qs);
        Queue line2(qs);

        // simulation will run 1 cycle per minute
        long cyclelimit = MIN_PER_HR * hours; // # of cycles
        double min_per_cust = MIN_PER_HR / perhour;

        Item temp;          // new customer data
        long turnaways = 0; // turned away by full queue
        long customers = 0; // joined the queue
        long served = 0;    // served during the simulation
        long sum_line = 0;  // cumulative line length
        int wait_time = 0;  // time until autoteller is free
        int wait_time2 = 0; // time until other autoteller is free
        long line_wait = 0; // cumulative time in line

        for (int cycle = 0; cycle < cyclelimit; cycle++) {
            if (newcustomer(min_per_cust)) // have newcomer
            {
                if (line.isfull() && line2.isfull()) {
                    turnaways++;
                }
                else {
                    customers++;
                    temp.set(cycle);
                    if (line.queuecount() < line2.queuecount()) {
                        line.enquene(temp); // add newcomer to line
                    }
                    else {
                        line2.enquene(temp); // add newcomer to second line
                    }
                }
            }
            if (wait_time <= 0 && !line.isempty()) {
                line.dequeue(temp);       // attend next customer
                wait_time = temp.ptime(); // for wait_time minutes
                line_wait += cycle - temp.when();
                served++;
            }
            if (wait_time2 <= 0 && !line2.isempty()) {
                line2.dequeue(temp);
                wait_time2 = temp.ptime();
                line_wait += cycle - temp.when();
                served++;
            }
            if (wait_time > 0) {
                wait_time--;
            }
            if (wait_time2 > 0) {
                wait_time2--;
            }
            sum_line += line.queuecount() + line2.queuecount();
        }

        average_wait_time = (double)line_wait / served;
    }

    cout << "\nNumber of customers per hour that leads to an average wait time "
            "of one minute: "
         << perhour << '\n';
    cout << "Average wait time: " << average_wait_time << '\n';

    return 0;
}

// x = average time, in minutes, between customers
// return value is true if customer shows up this minute
bool newcustomer(double x) { return (std::rand() * x / RAND_MAX < 1); }