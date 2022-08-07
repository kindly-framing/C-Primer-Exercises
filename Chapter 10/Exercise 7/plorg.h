#ifndef PLORG_H_
#define PLORG_H_

class Plorg {
  private:
    enum { MAX = 20 };
    char name[MAX]; // a plorg has a name with no more than 19 letters
    int index;      // a plorg has a contentment index (CI), which is an integer

  public:
    // a new plorg starts out with a name and a CI of 50
    // the default plorg has the name "Plorga"
    Plorg(const char name_[MAX] = "Plorga");

    // a plorg's CI can change
    void setCI(const int ci);

    // a plorg can report its name and CI.
    void report() const;
};

#endif