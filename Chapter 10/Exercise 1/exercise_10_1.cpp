/**
 * @file exercise_10_1.cpp
 * @author Steven Aquino
 * @brief Provide method definitions for the class described in Chapter Review
 * Question 5 and write a short program that illustrates all the
 * features.Provide method definitions for the class described in Chapter
 * Review Question 5 and write a short program that illustrates all the
 * features.
 *
 * Define a class to represent a bank account. Data members should include the
 * depositor’s name, the account number (use a string),and the balance. Member
 * functions should allow the following:
 *
 * Creating an object and initializing it.
 * Displaying the depositor’s name,account number,and balance
 * Depositing an amount of money given by an argument
 * Withdrawing an amount of money given by an argument
 *
 * Just show the class declaration, not the method implementations. (Programming
 * Exercise 1 provides you with an opportunity to write the implementation.)
 *
 * @version 0.1
 * @date 2022-07-07
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <string>

class Account {
   private:
    std::string m_name;
    std::string m_number;
    double m_balance;

   public:
    /**
     * @brief Construct a new Account object
     *
     * @param name The name of depositor
     * @param number The account number
     * @param balance The balance in the account
     */
    Account(std::string name, std::string number, double balance);

    /**
     * @brief Shows the depositor’s name, account number, and balance
     *
     */
    void show();

    /**
     * @brief Deposits the amount given into account
     *
     * @param n
     */
    void deposit(double n);

    /**
     * @brief Withdraws the amount given from account
     *
     * @param n
     */
    void withdraw(double n);
};

int main()
{
    Account bob("Bob Jones", "1234567890", 100.0);
    bob.show();

    bob.deposit(50.0);
    bob.show();

    bob.withdraw(50.0);
    bob.show();

    return 0;
}

Account::Account(std::string name, std::string number, double balance)
{
    m_name = name;
    m_number = number;
    m_balance = balance;
}

void Account::show()
{
    std::cout << "Depositor's name: " << m_name << "\n";
    std::cout << "Account #: " << m_number << "\n";
    std::cout << "Balance: " << m_balance << "\n";
}

void Account::deposit(double n) { m_balance += n; }

void Account::withdraw(double n) { m_balance -= n; }