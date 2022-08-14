/**
 * @file exercise_3.cpp
 * @author Steven Aquino
 * @brief Revise the baseDMA-lacksDMA-hasDMA class hierarchy so that all three
 * classes are derived from an DMA. Test the result with a program similar to
 * the one in Listing 13.10. That is, it should feature an array of pointers to
 * the DMA and allow the user to make runtime decisions as to what types of
 * objects are created. Add virtual View() methods to the class definitions to
 * handle displaying the data.
 *
 * @version 0.1
 * @date 2022-08-10
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "dma.h"
#include <iostream>
#include <string>
const int N = 3;
const int SIZE = 40;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    DMA *p_dma[N];
    char label[SIZE];
    int rating;

    for (int i = 0; i < N; i++) {
        cout << "Enter the label: ";
        cin >> label;
        cout << "Enter the rating: ";
        cin >> rating;
        char kind;
        cout << "Enter 1 for baseDMA, 2 for lacksDMA, or 3 for hasDMA: ";
        while (cin >> kind && (kind != '1' && kind != '2' && kind != '3')) {
            cout << "Enter either 1, 2, or 3: ";
        }
        if (kind == '1') {
            p_dma[i] = new baseDMA(label, rating);
        }
        else if (kind == '2') {
            char color[SIZE];
            cout << "Enter color: ";
            cin >> color;
            p_dma[i] = new lacksDMA(color, label, rating);
        }
        else {
            char style[SIZE];
            cout << "Enter style: ";
            cin >> style;
            p_dma[i] = new hasDMA(style, label, rating);
        }
        while (cin.get() != '\n') {
            continue;
        }
    }
    cout << endl;
    for (int i = 0; i < N; i++) {
        p_dma[i]->View();
        cout << endl;
    }

    for (int i = 0; i < N; i++) {
        delete p_dma[i];
    }
    cout << "Done\n";
    return 0;
}