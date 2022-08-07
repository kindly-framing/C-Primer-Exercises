#include "stack.h"

Stack::Stack() {}

bool Stack::isempty() const { return top == 0; }

bool Stack::isfull() const { return top == MAX; }

bool Stack::push(const Item &item)
{
    if (this->isfull()) {
        return false;
    }
    top++;
    items[top] = item;
    return true;
}
bool Stack::pop(Item &item)
{
    if (this->isempty()) {
        return false;
    }
    item = items[top];
    top--;
    return true;
}