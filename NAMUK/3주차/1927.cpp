// baek_3wekk.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int, vector<int>, greater<int>> min_que;
    vector <int> input_v;
    int size,input, i;
    cin >> size;
    
    for (i = 0; i < size; ++i) {
        cin >> input;
        input_v.push_back(input);
    }
    
    for (i = 0; i < size; ++i) {
        if (input_v[i] == 0) {
            if (min_que.size() == 0) {
                cout << 0 << endl;
            }
            else {
                cout << min_que.top() << endl;
                min_que.pop();
            }
        }
        else {
            min_que.push(input_v[i]);
        }
    }




    
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
