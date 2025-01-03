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

    int temp = 1;  // ���� ���ÿ� ���� ����
    for (int i = 0; i < n; i++) {
        int target = num[i];

        while (temp <= target) { //��ǥ���ڱ��� �� push
            s.push(temp);
            output.push_back('+');
            temp++; 
        }

        if (!s.empty() && s.top() == target) { //�������� pop
            s.pop();
            output.push_back('-');
        }
        else { // �ᱹ �ѹ� ���� ���ڿ��� ������ ���������� �ȳ����� ex) 4 2 3 1
            cout << "NO" << endl;
            return 0;
        }
    }

    for (char op : output) {
        cout << op << '\n';
    }

    return 0;
}
