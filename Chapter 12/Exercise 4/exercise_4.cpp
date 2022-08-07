/**
 * @file exercise_4.cpp
 * @author Steven Aquino
 * @brief Consider the following variation of the Stack class defined in
 * stack2.h:
 *
 * As the private members suggest, this class uses a dynamically allocated array
 * to hold the stack items. Rewrite the methods to fit this new representation
 * and write a program that demonstrates all the methods, including the copy
 * constructor and assignment operator.
 *
 * @version 0.1
 * @date 2022-08-04
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "stack2.h"

int main()
{

    const int len = 5;
    std::cout << "testing constructor and pushing items to it until full:\n";
    Stack stack(len);
    for (int i = 0; i <= len; i++) {
        if (stack.push(i)) {
            std::cout << "\tSuccessfully added " << i << " to stack!\n";
        }
        else {
            std::cout << "\tThe stack is full!\n";
        }
    }
    std::cout << "\tStack: " << stack;

    std::cout << "\nCreating a copy of this stack using operator=:\n";
    Stack copy = stack;
    std::cout << "\tOriginal: " << stack;
    std::cout << "\tCopy: " << copy;

    std::cout << "\nRemoving all elements from original:\n";
    Item popped;
    while (stack.pop(popped)) {
        std::cout << "\tRemoved " << popped << " from stack\n";
    }
    std::cout << "\tRemoved all elements from original\n";
    std::cout << "Original: " << stack;
    std::cout << "Copy: " << copy;
    return 0;
}