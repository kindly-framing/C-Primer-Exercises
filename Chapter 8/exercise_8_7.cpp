/**
 * @file exercise_8_7.cpp
 * @author Steven Aquino
 * @brief Modify Listing 8.14 so that it uses two template functions called
 * SumArray() to return the sum of the array contents instead of displaying the
 * contents.The program now should report the total number of things and the sum
 * of all the debts.
 *
 * @version 0.1
 * @date 2022-07-06
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>

template <typename T>  // template A
void ShowArray(T arr[], int n);

template <typename T>  // template B
void ShowArray(T* arr[], int n);

template <typename T>
T SumArray(T arr[], int n);

template <typename T>
T SumArray(T* arr[], int n);

struct debts {
    char name[50];
    double amount;
};

int main()
{
    int things[6] = {13, 31, 103, 301, 310, 130};
    struct debts mr_E[3] = {
        {"Ima Wolfe", 2400.0}, {"Ura Foxe", 1300.0}, {"Iby Stout", 1800.0}};
    double* pd[3];

    // set pointers to the amount members of the structures in mr_E
    for (int i = 0; i < 3; i++) {
        pd[i] = &mr_E[i].amount;
    }
    std::cout << "Listing Mr. E's counts of things:\n";

    // things is an array of int
    ShowArray(pd, 3);  // uses template B (more specialized)
    std::cout << SumArray(pd, 3) << "\n";

    return 0;
}

template <typename T>
void ShowArray(T arr[], int n)
{
    std::cout << "template A\n";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

template <typename T>
void ShowArray(T* arr[], int n)
{
    std::cout << "template B\n";
    for (int i = 0; i < n; i++) {
        std::cout << *arr[i] << ' ';
    }
    std::cout << std::endl;
}

template <typename T>
T SumArray(T arr[], int n)
{
    std::cout << "template A\n";
    T sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

template <typename T>
T SumArray(T* arr[], int n)
{
    std::cout << "template B\n";
    T sum = 0;
    for (int i = 0; i < n; i++) {
        sum += *arr[i];
    }
    return sum;
}