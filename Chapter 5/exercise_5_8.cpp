/**
 * @file exercise_5_8.cpp
 * @author Steven Aquino
 * @brief Write a program that uses an array of char and a loop to read one word
 * at a time until the word done is entered. The program should then report the
 * number of words entered (not counting done). A sample run could look like
 * this:
 *
 * Enter words (to stop, type the word done):
 * anteater birthday category dumpster envy finagle geometry done for sure
 * You entered a total of 7 words.
 *
 * You should include the cstring header file and use the strcmp() function to
 * make the comparison test.
 * @version 0.1
 * @date 2022-06-09
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <cstring>
#include <iostream>

int main() {
    char key[] = "done";
    char currentWord[256];
    int count = 0;

    std::cout << "Enter words (to stop, type the word done):\n";
    // Gets the next word in the stream
    while (std::cin >> currentWord) {
        if (strcmp(key, currentWord) == 0) {
            break;
        }
        count++;
    }

    std::cout << "You entered a total of " << count << " words.\n";

    return 0;
}