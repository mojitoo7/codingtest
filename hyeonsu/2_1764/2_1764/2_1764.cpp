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
        string name; //듣도못한사람 입력
        cin >> name;
        hear.push_back(name);
    }

    sort(hear.begin(), hear.end()); //이진 탐색용 정렬

    for (int i = 0; i < m; i++) {
        string name; // 보도못한사람 입력
        cin >> name;

        if (binary_search(hear.begin(), hear.end(), name)) { //듣도 못한 사람중 찾기, 이진탐색으로
            result.push_back(name);
        }
    }

    sort(result.begin(), result.end()); //사전순 출력용 정렬

    cout << result.size() << endl;
    for (const string& name : result) {
        cout << name << endl;
    }

    return 0;
}
