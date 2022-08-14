// dma.h -- inheritance and dynamic memory allocation
#ifndef DMA_H_
#define DMA_H_
#include <iostream>

// Abstract Base Class for DMA
class DMA {
  public:
    virtual void View() const = 0;
    virtual ~DMA(){};
};

// Base Class Using DMA
class baseDMA : public DMA {
  private:
    char *label;
    int rating;

  public:
    baseDMA(const char *l = "null", int r = 0);
    baseDMA(const baseDMA &rs);
    virtual ~baseDMA();
    baseDMA &operator=(const baseDMA &rs);
    friend std::ostream &operator<<(std::ostream &os, const baseDMA &rs);
    void View() const;
};

// derived class without DMA
// no destructor needed
// used implicit copy constructor
// uses implicit assignment operator
class lacksDMA : public baseDMA {
  private:
    enum { COL_LEN = 40 };
    char color[COL_LEN];

  public:
    lacksDMA(const char *c = "blank", const char *l = "null", int r = 0);
    lacksDMA(const char *c, const baseDMA &rs);
    friend std::ostream &operator<<(std::ostream &os, const lacksDMA &rs);
    void View() const;
};

// derived class with DMA
class hasDMA : public baseDMA {
  private:
    char *style;

  public:
    hasDMA(const char *s = "none", const char *l = "null", int r = 0);
    hasDMA(const char *s, const baseDMA &rs);
    hasDMA(const hasDMA &hs);
    ~hasDMA();
    hasDMA &operator=(const hasDMA &rs);
    friend std::ostream &operator<<(std::ostream &os, const hasDMA &rs);
    void View() const;
};

#endif