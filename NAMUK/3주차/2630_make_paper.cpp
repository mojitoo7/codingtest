// 2630_make_paper.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
int white_count = 0;
int blue_count = 0;

void paper_count(int (*arr)[128], int x, int y, int size) {

    int first = arr[x][y];
    bool cut = false;
    for (int i = x; i < x + size; ++i) {
        for (int j = y; j < y + size; ++j) {
            if (first != arr[i][j]) {
                cut = true;
                break;
            }
        }
    }
    if (cut && size > 1) {
        paper_count(arr, x, y, size / 2);

        paper_count(arr, x + size / 2, y, size / 2);

        paper_count(arr, x, y + size / 2, size / 2);

        paper_count(arr, x + size / 2, y + size / 2, size / 2);
    }
    else {
        if (first == 1) {
            blue_count++;
        }
        else {
            white_count++;
        }
    }

}

int main()
{
    int size,i,j;

    cin >> size;

    int arr[128][128];

    for (i = 0; i < size; ++i) {
        for (j = 0; j < size; ++j) {
            cin >> arr[i][j];
        }
    }
    paper_count(arr, 0, 0 ,size);

    cout << white_count << endl << blue_count;

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
