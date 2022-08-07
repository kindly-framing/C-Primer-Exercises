/**
 * @file exercise_7_6.cpp
 * @author Steven Aquino
 * @brief Write a program that uses the following functions:
 *
 * Fill_array() takes as arguments the name of an array of double values and an
 * array size. It prompts the user to enter double values to be entered in the
 * array. It ceases taking input when the array is full or when the user enters
 * non-numeric input,and it returns the actual number of entries.
 *
 * Show_array() takes as arguments the name of an array of double values and an
 * array size and displays the contents of the array.
 *
 * Reverse_array() takes as arguments the name of an array of double values and
 * an array size and reverses the order of the values stored in the array.
 *
 * The program should use these functions to fill an array, show the array,
 * reverse the array, show the array, reverse all but the first and last
 * elements of the array, and then show the array.
 *
 * @version 0.1
 * @date 2022-06-22
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <string>

int fill_array(double arr[], int arr_size);
void show_array(double arr[], int arr_size);
void reverse_array(double arr[], int arr_size);

int main()
{
    const int MAX_VALUES = 5;
    double nums[MAX_VALUES];

    int size = fill_array(nums, MAX_VALUES);
    show_array(nums, size);

    reverse_array(nums, size);
    show_array(nums, size);

    double first = nums[0];
    double last = nums[size - 1];
    reverse_array(nums, size);
    nums[0] = first;
    nums[size - 1] = last;
    show_array(nums, size);

    return 0;
}

int fill_array(double arr[], int arr_size)
{
    std::cout << "Enter double values until full or non-numeric to stop taking "
                 "input\n";

    std::string input;
    int size = 0;
    while (std::getline(std::cin, input)) {
        double n;
        try {
            n = std::stod(input);
        }
        catch (const std::invalid_argument &e) {
            break;
        }

        arr[size] = n;
        size++;
        if (size == arr_size) {
            break;
        }
    }

    return size;
}

void show_array(double arr[], int arr_size)
{
    for (int i = 0; i < arr_size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void reverse_array(double arr[], int arr_size)
{
    for (int i = 0; i < arr_size / 2; i++) {
        std::swap(arr[i], arr[arr_size - 1 - i]);
    }
}