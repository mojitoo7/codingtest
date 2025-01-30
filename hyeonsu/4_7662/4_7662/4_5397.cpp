#include <iostream>
#include <stack>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string input;
        cin >> input;

        stack<char> left;  
        stack<char> right; 

        for (char ch : input) {
            if (ch == '<') {
                if (!left.empty()) {
                    right.push(left.top());
                    left.pop();
                }
            }
            else if (ch == '>') {
                if (!right.empty()) {
                    left.push(right.top());
                    right.pop();
                }
            }
            else if (ch == '-') {
                if (!left.empty()) {
                    left.pop();
                }
            }
            else {
                left.push(ch);
            }
        }
        while (!left.empty()) {
            right.push(left.top());
            left.pop();
        }
        while (!right.empty()) {
            cout << right.top();
            right.pop();
        }
        cout << '\n';
    }

    return 0;
}
