#ifndef WINEC_H_
#define WINEC_H_
#include <string>
#include <valarray>

// pair class
template <class T1, class T2> class Pair {
  private:
    T1 a;
    T2 b;

  public:
    T1 &first();
    T2 &second();
    T1 first() const { return a; }
    T2 second() const { return b; }
    Pair(const T1 &aval, const T2 &bval) : a(aval), b(bval) {}
    Pair() {}
};

// pair class methods
template <class T1, class T2> T1 &Pair<T1, T2>::first() { return a; }
template <class T1, class T2> T2 &Pair<T1, T2>::second() { return b; }

// simplifies the code
typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

// wine class
class Wine {
  private:
    std::string label;
    int years;
    PairArray yearAndBottles;

  public:
    // default constructor
    Wine();

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