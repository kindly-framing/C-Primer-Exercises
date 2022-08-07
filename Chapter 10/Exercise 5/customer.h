#ifndef CUSTOMER_H_
#define CUSTOMER_H_

struct Customer {
    char fullname[35];
    double payment;

    // asks the user for name and payment to assign to Customer
    void set();
};

#endif