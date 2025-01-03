#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    stack<int> s;
    vector<char> output;

    int temp = 1;  // 현재 스택에 넣을 숫자
    for (int i = 0; i < n; i++) {
        int target = num[i];

        while (temp <= target) { //목표숫자까지 다 push
            s.push(temp);
            output.push_back('+');
            temp++; 
        }

        if (!s.empty() && s.top() == target) { //같아지면 pop
            s.pop();
            output.push_back('-');
        }
        else { // 결국 한번 나온 숫자에서 밑으로 수열순으로 안나오면 ex) 4 2 3 1
            cout << "NO" << endl;
            return 0;
        }
    }

    for (char op : output) {
        cout << op << '\n';
    }

    return 0;
}
