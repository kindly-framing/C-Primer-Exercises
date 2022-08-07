namespace SALES {
const int QUARTERS = 4;

class Sales {
  private:
    double sales[QUARTERS];
    double average;
    double max;
    double min;

  public:
    // default constructor
    Sales();

    // copies the lesser of 4 or n items from the array ar
    // to the sales member of s and computes and stores the
    // average, maximum, and minimum values of the entered items;
    // remaining elements of sales, if any, set to 0
    Sales(const double ar[], int n);

    // gathers sales for quarters interactively, stores them
    // in the sales member of s and computes and stores the
    // average, maximum, and minimum values
    void setSales();

    // display all information in structure s
    void showSales();
};

} // namespace SALES