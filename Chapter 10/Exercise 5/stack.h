// stack.h -- class definition for the stack ADT
#include "customer.h"

#ifndef STACK_H_
#define STACK_H_

typedef Customer Item;

class Stack {
  private:
    enum { MAX = 10 }; // constant specific to class
    Item items[MAX];   // holds stack items
    int top = 0;       // index for top stack item

  public:
    Stack();
    bool isempty() const;
    bool isfull() const;
    // push() returns false if stack already is full, true otherwise
    bool push(const Item &item); // add item to stack
    // pop() return false if stack already is empty, true otherwise
    bool pop(Item &item); // pop top into item
};

#endif