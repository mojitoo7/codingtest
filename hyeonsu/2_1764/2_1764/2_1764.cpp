#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> hear;
    vector<string> result;

    for (int i = 0; i < n; i++) {
        string name; //�赵���ѻ�� �Է�
        cin >> name;
        hear.push_back(name);
    }

    sort(hear.begin(), hear.end()); //���� Ž���� ����

    for (int i = 0; i < m; i++) {
        string name; // �������ѻ�� �Է�
        cin >> name;

        if (binary_search(hear.begin(), hear.end(), name)) { //�赵 ���� ����� ã��, ����Ž������
            result.push_back(name);
        }
    }

    sort(result.begin(), result.end()); //������ ��¿� ����

    cout << result.size() << endl;
    for (const string& name : result) {
        cout << name << endl;
    }

    return 0;
}
