/**
 * @file exercise_7_9.cpp
 * @author Steven Aquino
 * @brief This exercise provides practice in writing functions dealing with
 * arrays and structures.The following is a program skeleton. Complete it by
 * providing the described functions:
 * @version 0.1
 * @date 2022-07-01
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>

const int SLEN = 30;
struct Student {
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};

// getinfo() has two arguments: a pointer to the first element of
// an array of student structures and an int representing the
// number of elements of the array. The function solicits and
// stores data about students. It terminates input upon filling
// the array or upon encountering a blank line for the student
// name. The function returns the actual number of array elements
// filled.
int getinfo(Student pa[], int n);

// display1() takes a student structure as an argument
// and displays its contents
void display1(Student st);

// display2() takes the address of student structure as an
// argument and displays the structure’s contents
void display2(const Student* ps);

// display3() takes the address of the first element of an array
// of student structures and the number of array elements as
// arguments and displays the contents of the structures
void display3(const Student pa[], int n);

int main()
{
    std::cout << "Enter class size : ";
    int class_size;
    std::cin >> class_size;
    while (std::cin.get() != '\n') {
        continue;
    }

    Student* ptr_stu = new Student[class_size];
    int entered = getinfo(ptr_stu, class_size);
    for (int i = 0; i < entered; i++) {
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu, entered);
    delete[] ptr_stu;
    std::cout << "Done\n";
    return 0;
}

int getinfo(Student pa[], int n)
{
    int i;

    for (i = 0; i < n; i++) {
        Student x;

        std::cout << "Enter student name: ";
        std::cin.getline(x.fullname, SLEN);
        if (x.fullname[0] == '\0') {
            break;
        }

        std::cout << "Enter your hobby: ";
        std::cin.getline(x.hobby, SLEN);

        std::cout << "Enter your OOP level: ";
        std::cin >> x.ooplevel;

        pa[i] = x;
        std::cin.ignore();
    }

    return i;
}

void display1(Student st)
{
    std::cout << "Full name: ";
    for (int i = 0; st.fullname[i] != '\0'; i++) {
        std::cout << st.fullname[i];
    }
    std::cout << "\n";

    std::cout << "Hobby: ";
    for (int i = 0; st.hobby[i] != '\0'; i++) {
        std::cout << st.hobby[i];
    }
    std::cout << "\n";

    std::cout << "OOP Level: " << st.ooplevel << "\n";
}

void display2(const Student* ps)
{
    Student x = *ps;

    std::cout << "Full name: ";
    for (int i = 0; x.fullname[i] != '\0'; i++) {
        std::cout << x.fullname[i];
    }
    std::cout << "\n";

    std::cout << "Hobby: ";
    for (int i = 0; x.hobby[i] != '\0'; i++) {
        std::cout << x.hobby[i];
    }
    std::cout << "\n";

    std::cout << "OOP Level: " << x.ooplevel << "\n";
}

void display3(const Student pa[], int n)
{
    for (int i = 0; i < n; pa++, i++) {
        Student st = *pa;
        display1(st);
    }
}