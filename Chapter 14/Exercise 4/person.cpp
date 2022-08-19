// person.cpp -- class definitions
#include "person.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using std::cin;
using std::cout;

// Person class methods

// protected methods
void Person::Data() const { cout << "Name: " << fullname << '\n'; }

void Person::Get() { getline(cin, fullname); }

// public methods
void Person::Set()
{
    cout << "Enter person's name: ";
    Get();
}

void Person::Show() const
{
    cout << "Category:  person\n";
    Data();
}

// Gunslinger class methods

// protected methods
void Gunslinger::Data() const
{
    cout << "Draw time: " << drawTime << '\n';
    cout << "Amount of notches: " << notches << '\n';
}

void Gunslinger::Get()
{
    cout << "Enter draw time: ";
    cin >> drawTime;
    while (cin.get() != '\n')
    {
        continue;
    }
    cout << "Enter amount of notches: ";
    cin >> notches;
    while (cin.get() != '\n')
    {
        continue;
    }
}

// public methods
Gunslinger::Gunslinger(const Gunslinger &p)
{
    Person((const Person &)p);
    drawTime = p.drawTime;
    notches = p.notches;
}

double Gunslinger::Draw() const { return drawTime; }

void Gunslinger::Set()
{
    cout << "Enter gunslinger's name: ";
    Person::Get();
    Get();
}

void Gunslinger::Show() const
{
    cout << "Category:  gunslinger\n";
    Person::Data();
    Data();
}

// PokerPlayer class methods

// public methods
PokerPlayer::PokerPlayer(const PokerPlayer &p) { Person((const Person &)p); }

int PokerPlayer::Draw() const { return 1 + (rand() % 52); }

void PokerPlayer::Set()
{
    cout << "Enter poker player's name: ";
    Person::Get();
}

void PokerPlayer::Show() const
{
    cout << "Category  poker player\n";
    Person::Data();
    cout << "Randomly drawn card: " << Draw() << '\n';
}

// BadDude class methods

BadDude::BadDude(const BadDude &b)
{
    Gunslinger((const Gunslinger &)b);
    PokerPlayer((const PokerPlayer &)b);
}

double BadDude::Gdraw() { return Gunslinger::Draw(); }

int BadDude::Cdraw() { return PokerPlayer::Draw(); }

void BadDude::Set() { Gunslinger::Set(); }

void BadDude::Show() const
{
    cout << "Category  bad dude\n";
    Person::Data();
    Gunslinger::Data();
    cout << "Randomly drawn card: " << PokerPlayer::Draw() << '\n';
}