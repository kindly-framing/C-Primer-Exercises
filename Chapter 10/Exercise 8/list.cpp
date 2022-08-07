#include "list.h"

List::List() {}

bool List::add(const Item x)
{
    if (!is_full()) {
        lst[top++] = x;
        return true;
    }
    return false;
}

bool List::is_empty() { return (top == 0); }

bool List::is_full() { return (top == MAX); }

void List::visit(void (*pf)(Item &x))
{
    for (int i = 0; i < MAX; i++) {
        pf(lst[i]);
    }
}