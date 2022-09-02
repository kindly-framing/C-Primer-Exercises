/**
 * @file exercise_10.cpp
 * @author Steven Aquino
 * @brief Modify Listing 16.9 (vect3.cpp) as follows:
 *
 * a. Add a price member to the Review structure.
 *
 * b. Instead of using a vector of Review objects to hold the input, use a
 * vector of shared_ptr<Review> objects. Remember that a shared_ptr has to be
 * initialized with a pointer returned by new.
 *
 * c. Follow the input stage with a loop that allows the user the following
 * options for displaying books: in original order, in alphabetical order, in
 * order of increasing ratings, in order of decresing ratings, in order of
 * increasing price, in order of decreasing price, and quitting.
 *
 * Here’s one possible approach. After getting the initial input, create another
 * vector of shared_ptrs initialized to the original array. Define an
 * operator<() function that compares pointed-to structures and use it to sort
 * the second vector so that the shared_ptrs are in the order of the book names
 * stored in the pointed-to objects. Repeat the process to get vectors of
 * shared_ptrs sorted by rating and by price. Note that rbegin() and rend() save
 * you the trouble of also creating vectors of reversed order.
 *
 * @version 0.1
 * @date 2022-09-02
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <algorithm>
#include <iostream>
#include <memory>
#include <random> // shuffle()
#include <string>
#include <vector>

struct Review
{
    std::string title;
    int rating;
    double price; // (a)
};

bool operator<(const std::shared_ptr<Review> &r1,
               const std::shared_ptr<Review> &r2);
bool worseThan(const std::shared_ptr<Review> &r1,
               const std::shared_ptr<Review> &r2);
bool lowerPrice(const std::shared_ptr<Review> &r1,
                const std::shared_ptr<Review> &r2);
bool FillReview(Review &rr);
void ShowReview(const std::shared_ptr<Review> &rr);
int main()
{
    using namespace std;

    // (b)
    vector<shared_ptr<Review>> books;
    Review temp;
    while (FillReview(temp))
    {
        shared_ptr<Review> p1(new Review(temp));
        books.push_back(p1);
    }
    if (books.size() > 0)
    {
        // (c)
        // original order
        cout << "Thank you. You entered the following " << books.size()
             << " ratings:\n"
             << "Rating\tBook\tPrice\n";
        for_each(books.begin(), books.end(), ShowReview);

        // alphabetical order
        sort(books.begin(), books.end());
        cout << "Sorted by title:\nRating\tBook\tPrice\n";
        for_each(books.begin(), books.end(), ShowReview);

        // in order of increasing ratings
        sort(books.begin(), books.end(), worseThan);
        cout << "Sorted by increasing rating:\nRating\tBook\tPrice\n";
        for_each(books.begin(), books.end(), ShowReview);

        // in order of decreasing ratings
        sort(books.rbegin(), books.rend(), worseThan);
        cout << "Sorted by decreasing rating:\nRating\tBook\tPrice\n";
        for_each(books.begin(), books.end(), ShowReview);

        // in order of increasing price
        sort(books.begin(), books.end(), lowerPrice);
        cout << "Sorted by increasing price:\nRating\tBook\tPrice\n";
        for_each(books.begin(), books.end(), ShowReview);

        // in order of decreasing price
        sort(books.rbegin(), books.rend(), lowerPrice);
        cout << "Sorted by decreasing price:\nRating\tBook\tPrice\n";
        for_each(books.begin(), books.end(), ShowReview);
    }
    else
    {
        cout << "No entries. ";
    }
    cout << "Bye\n";
    return 0;
}

bool operator<(const std::shared_ptr<Review> &r1,
               const std::shared_ptr<Review> &r2)
{
    if (r1->title < r2->title)
    {
        return true;
    }
    else if (r1->title == r2->title && r1->rating < r2->rating)
    {
        return true;
    }
    else if (r1->rating == r2->rating && r1->price < r2->price)
    {
        return true;
    }
    return false;
}

bool worseThan(const std::shared_ptr<Review> &r1,
               const std::shared_ptr<Review> &r2)
{
    return r1->rating < r2->rating;
}

bool lowerPrice(const std::shared_ptr<Review> &r1,
                const std::shared_ptr<Review> &r2)
{
    return r1->price < r2->price;
}

bool FillReview(Review &rr)
{
    std::cout << "Enter book title (quit to quit): ";
    std::getline(std::cin, rr.title);
    if (rr.title == "quit")
    {
        return false;
    }
    std::cout << "Enter book rating: ";
    std::cin >> rr.rating;
    if (!std::cin)
    {
        return false;
    }
    std::cout << "Enter price: ";
    std::cin >> rr.price;
    if (!std::cin)
    {
        return false;
    }
    // get rid of rest of input line
    while (std::cin.get() != '\n')
    {
        continue;
    }
    return true;
}

void ShowReview(const std::shared_ptr<Review> &rr)
{
    std::cout << rr->rating << "\t" << rr->title << "\t" << rr->price
              << std::endl;
}