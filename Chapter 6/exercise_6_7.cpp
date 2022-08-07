/**
 * @file exercise_6_7.cpp
 * @author Steven Aquino
 * @brief Write a program that reads input a word at a time until a lone q is
 * entered.The program should then report the number of words that began with
 * vowels, the number that began with consonants,and the number that fit neither
 * of those categories. One approach is to use isalpha() to discriminate between
 * words beginning with letters and those that don’t and then use an if or
 * switch statement to further identify those passing the isalpha() test that
 * begin with vowels.A sample run might look like this:
 * Enter words (q to quit):
 * The 12 awesome oxen ambled
 * quietly across 15 meters of lawn. q
 * 5 words beginning with vowels
 * 4 words beginning with consonants
 * 2 others
 * @version 0.1
 * @date 2022-06-12
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <string>

int main() {
    int vowelCount = 0;
    int consonantCount = 0;
    int otherCount = 0;

    std::string input;
    while (std::cin >> input) {
        char chr = input[0];
        std::cout << input << " " << chr << "\n";

        if (input == "q") {
            break;
        } else if (isalpha(chr)) {
            switch (tolower(chr)) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                vowelCount++;
                break;
            default:
                consonantCount++;
                break;
            }
        } else {
            otherCount++;
        }
    }

    std::cout << vowelCount << " words beginning with vowels\n";
    std::cout << consonantCount << " words beginning with consonants\n";
    std::cout << otherCount << " others\n";

    return 0;
}