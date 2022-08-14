#ifndef WINEC2_H_
#define WINEC2_H_
#include <string>
#include <utility>
#include <valarray>

typedef std::valarray<int> ArrayInt;
typedef std::pair<ArrayInt, ArrayInt> PairArray;

class Wine : ArrayInt, PairArray {
  private:
    std::string label;
    int years;

  public:
    // initialize label to 1, number of years to y, vintage years to yr[],
    // bottles to bot[]
    Wine(const char *l, int y, const int yr[], const int bot[]);

    // initialize label to l, number of years to y, create array objects of
    // length y
    Wine(const char *l, int y);

    // prompts the user to enter the corresponding number of vintage years and
    // bottle counts
    void GetBottles();

    // should return reference to the wine name
    std::string Label() const;

    // should return the total number of bottles
    int sum() const;

    // shows the contents of the Wine object
    void Show() const;
};

#endif