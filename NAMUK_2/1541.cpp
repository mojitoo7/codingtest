// 1541.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;
int main()
{
    string input;
    int i, result = 0 , temp = 0;
    char sign = ' ';

    cin >> input;

    for (i = 0; i < input.size(); ++i) {
        if ('0' <= input[i] && input[i] <= '9') {
                temp = temp * 10 + (input[i] - '0');
        }

        else {
            if (sign == ' ') {
                result = result + temp; 
                temp = 0; 
                if (input[i] == '-') {
                    sign = '-';
                }
            }
            else if (sign == '-') {
                result = result - temp;
                sign = '-';
                temp = 0;
            }
        }
    }
    if(sign == ' '){ result = result + temp; }
    else if (sign == '-') { result = result - temp; }

    cout << result;
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
