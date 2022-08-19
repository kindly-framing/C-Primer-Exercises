// person.h -- class declaration
#ifndef PERSON_H_
#define PERSON_H_

#include <string>

class Person
{
  private:
    std::string fullname;

  protected:
    virtual void Data() const;
    virtual void Get();

  public:
    Person() : fullname("no one") {}
    Person(std::string name) : fullname(name) {}
    Person(const Person &p) : fullname(p.fullname) {}
    virtual void Set();
    virtual void Show() const;
};

class Gunslinger : virtual public Person
{
  private:
    double drawTime;
    int notches;

  protected:
    virtual void Data() const;
    virtual void Get();

  public:
    Gunslinger() : Person(), drawTime(0.0), notches(0) {}
    Gunslinger(double dt, int n, std::string name)
        : Person(name), drawTime(dt), notches(n)
    {
    }
    Gunslinger(const Gunslinger &p);
    virtual double Draw() const;
    virtual void Set();
    virtual void Show() const;
};

class PokerPlayer : virtual public Person
{
  public:
    PokerPlayer() : Person() {}
    PokerPlayer(std::string name) : Person(name) {}
    PokerPlayer(const PokerPlayer &p);
    virtual int Draw() const;
    virtual void Set();
    virtual void Show() const;
};

class BadDude : public Gunslinger, public PokerPlayer
{
  public:
    BadDude() : Gunslinger(), PokerPlayer() {}
    BadDude(double dt, int n, std::string name)
        : Gunslinger(dt, n, name), PokerPlayer(name)
    {
    }
    BadDude(const BadDude &b);
    double Gdraw();
    int Cdraw();
    void Set();
    void Show() const;
};

#endif