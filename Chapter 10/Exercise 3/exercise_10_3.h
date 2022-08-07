#include <string>

class Golf {
  private:
    std::string fullname;
    int handicap;

  public:
    // default constructor
    Golf();

    // interactive version:
    // function solicits name an handicap from user
    // and sets the members of g to the values entered
    // returns 1 if name is entered, 0 if name is empty string
    int setgolf();

    //  function set golf structure to provided name, handicap using values
    //  passed as arguments to the function
    Golf(std::string name, int hc);

    // function resets handicap to new value
    void set_handicap(int hc);

    // function displays contents of golf structure
    void showgolf() const;
};
