// 1236.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{

    int row, col, i, j, result, col_count = 0, row_count = 0;
    int row_x = 0, col_x = 0;

    scanf("%d %d", &row, &col);
    cin.ignore();
    string* buffer = new string[row];

    for (i = 0; i < row; ++i) {
        getline(cin, buffer[i]);
    }
    for (i = 0; i < row; ++i) {
        for (j = 0; j < col; ++j) {
            if (buffer[i][j] == 'X') { col_x++; }
        }
        if (col_x == 0) { col_count++; }
        col_x = 0;
    }
    for (i = 0; i < col; ++i) {
        for (j = 0; j < row; ++j) {
            if (buffer[j][i] == 'X') { row_x++; }
        }
        if (row_x == 0) { row_count++; }
        row_x = 0;
    }

    result = (row_count > col_count) ? row_count : col_count;
    delete[] buffer;
    cout << row_count << col_count << result;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
