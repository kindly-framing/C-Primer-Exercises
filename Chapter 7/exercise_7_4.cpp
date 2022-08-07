/**
 * @file exercise_7_4.cpp
 * @author Steven Aquino
 * @brief Many state lotteries use a variation of the simple lottery portrayed
 * by Listing 7.4. In these variations you choose several numbers from one set
 * and call them the field numbers. For example, you might select five numbers
 * from the field of 1–47).You also pick a single number (called a mega number
 * or a power ball, etc.) from a second range, such as 1–27.To win the grand
 * prize, you have to guess all the picks correctly.The chance of winning is the
 * product of the probability of picking all the field numbers times the
 * probability of picking the mega number. For instance, the probability of
 * winning the example described here is the product of the probability of
 * picking 5 out of 47 correctly times the probability of picking 1 out of 27
 * correctly. Modify Listing 7.4 to calculate the probability of winning this
 * kind of lottery.
 * @version 0.1
 * @date 2022-06-15
 *
 * @copyright Copyright (c) 2022
 *
 */
// lotto.cpp -- probability of winning
// #include <iostream>
// // Note: some implementations require double instead of long double
// long double probability(unsigned numbers, unsigned picks);
// int main() {
//   using namespace std;
//   double total, choices;
//   cout << "Enter the total number of choices on the game card and\n"
//           "the number of picks allowed:\n";
//   while ((cin >> total >> choices) && choices <= total) {
//     cout << "You have one chance in ";
//     cout << probability(total, choices); // compute the odds
//     cout << " of winning.\n";
//     cout << "Next two numbers (q to quit): ";
//   }
//   cout << "bye\n";
//   return 0;
// }
// // the following function calculates the probability of picking picks
// // numbers correctly from numbers choices
// long double probability(unsigned numbers, unsigned picks) {
//   long double result = 1.0; // here come some local variables
//   long double n;
//   unsigned p;
//   for (n = numbers, p = picks; p > 0; n--, p--)
//     result = result * n / p;
//   return result;
// }
// lotto.cpp-- probability of winning
#include <iostream>

// Note: some implementations require double instead of long double
long double probability(unsigned numbers, unsigned picks);

int main()
{
    double field = 47.0;
    const int FIELD_CHOICES = 5;
    double mega = 27.0;
    const int MEGA_CHOICES = 1;

    double prob_of_winning =
        probability(field, FIELD_CHOICES) * probability(mega, MEGA_CHOICES);

    std::cout << "The probability of winning is 1 out of " << prob_of_winning
              << ".\n";

    std::cout << "bye\n";
    return 0;
}

// the following function calculates the probability of picking picks
// numbers correctly from numbers choices
long double probability(unsigned numbers, unsigned picks)
{
    long double result = 1.0; // here come some local variables
    long double n;
    unsigned p;
    for (n = numbers, p = picks; p > 0; n--, p--)
        result = result * n / p;
    return result;
}