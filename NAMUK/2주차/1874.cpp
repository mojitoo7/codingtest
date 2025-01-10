// 1874.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;



int main()
{
    int n,input, temp;

    int push_count=0;
    string result;
    cin >> n;

    vector<int> stack;
    for (int i = 0; i < n; ++i) {
        cin >> input;
        if (push_count < input) { //pop하고자 하는 숫자가 아직 스택에 들어가지 않는 경우
            temp = input - push_count;
            for (int j = 0; j < temp; ++j) {
                result += '+';
                result += '\n';
                stack.push_back(push_count + 1);
                push_count++;
            }
        }
        else if (stack.back() != input) { //스택 안에 pop하고자 하는 숫자가 있는데 그 숫자가 스택 맨 위에 없는 경우
            cout << "NO";
            return 0;
        }
        result += '-';
        result += '\n';
        stack.pop_back();
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
