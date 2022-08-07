#ifndef LIST_H_
#define LIST_H_

typedef int Item;

class List {
  private:
    enum { MAX = 5 };
    Item lst[MAX];
    int top = 0;

  public:
    // You can create an empty list
    List();
    // You can add items to the list
    bool add(const Item x);
    // You can determine whether the list is empty
    bool is_empty();
    // You can determine whether the list is full
    bool is_full();
    // You can visit each item in the list and perform some action on it.
    void visit(void (*pf)(Item &x));
};

#endif