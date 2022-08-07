// stack2.cpp -- Stack class methods
#include "stack2.h"
#include <cstring>

Stack::Stack(int n) : size{n}, top{0} {}

Stack::Stack(const Stack &st) { *this = st; }

Stack::~Stack() { delete[] pitems; }

bool Stack::isempty() const { return top == 0; }

bool Stack::isfull() const { return top == size; }

bool Stack::push(const Item &item)
{
    if (!isfull()) {
        Item *result = new Item[top + 1];
        for (int i = 0; i < top; i++) {
            result[i] = pitems[i];
        }
        result[top] = item;
        delete[] pitems;
        pitems = new Item[top + 1];
        pitems = result;
        top++;
        return true;
    }
    return false;
}

bool Stack::pop(Item &item)
{
    if (!isempty()) {
        item = pitems[top - 1];
        Item *result = new Item[top - 1];
        for (int i = 0; i < top - 1; i++) {
            result[i] = pitems[i];
        }
        delete[] pitems;
        pitems = new Item[top - 1];
        pitems = result;
        top--;
        return true;
    }
    return false;
}

Stack &Stack::operator=(const Stack &st)
{
    Item *copy = new Item[st.top];
    for (int i = 0; i < st.top; i++) {
        copy[i] = st.pitems[i];
    }
    this->pitems = new Item[st.top];
    this->pitems = copy;

    this->size = st.size;
    this->top = st.top;
}

std::ostream &operator<<(std::ostream &os, const Stack &st)
{
    for (int i = 0; i < st.top; i++) {
        os << st.pitems[i] << ' ';
    }
    os << '\n';
    return os;
}