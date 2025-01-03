// 2596.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
    int a = 0;
    int x = 0;
    int turn = 0;
    int temp = 0;
    string str;
    string result;
    bool no_match = true;
    cin >> a >> str;
    

    for (int j = 1; j <= a; j++) {
        no_match = true;
        x = 0;
        for (int i = 0; i < 6; ++i) { 
            x += (str[6*j - i-1] - '0') << i;
           // cout << x;
        } // x구하기
       // cout << endl << x;
        //cout << 'a' << endl;
        if (x == 0) { result += 'A'; }
        else if (x == 15) { result += 'B'; }
        else if (x == 19) { result += 'C'; }
        else if (x == 28) { result += 'D'; }
        else if (x == 38) { result += 'E'; }
        else if (x == 41) { result += 'F'; }
        else if (x == 53) { result += 'G'; }
        else if (x == 58) { result += 'H'; } //x비교하기
        else { 
            for (int i = 0; i < 6; ++i) { //x에서 될 수 있는 모든 x마다 비교하기
                temp = x;
                if (str[6 * j - i - 1] == '0') {
                    temp += (1 << i);
                }
                else {
                    temp -= (1 << i);
                }
               // cout << temp << endl;


                if (temp == 0) { result += 'A'; no_match = false; }
                else if (temp == 15) { result += 'B'; no_match = false;}
                else if (temp == 19) { result += 'C'; no_match = false;}
                else if (temp == 28) { result += 'D'; no_match = false;}
                else if (temp == 38) { result += 'E'; no_match = false;}
                else if (temp == 41) { result += 'F'; no_match = false;}
                else if (temp == 53) { result += 'G'; no_match = false;}
                else if (temp == 58) { result += 'H'; no_match = false;}
            }
            if (no_match) { cout << j; return 0; }
        }
        
    }
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
