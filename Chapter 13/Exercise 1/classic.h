#ifndef CLASSIC_H_
#define CLASSIC_H_
#include "cd.h"

class Classic : public Cd {
  private:
    Cd location;
    char classic[50];

  public:
    Classic(char *classic, char *s1, char *s2, int n, double x);
    Classic(const Classic &c);
    Classic();
    ~Classic();
    void Report() const;
    Classic &operator=(const Classic &c);
};
#endif