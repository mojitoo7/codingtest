#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    set<string> list;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        list.insert(str);
    }

    int cnt = 0;
    for (int i = 0; i < m; i++) {
        string str;
        cin >> str;
        if (list.find(str) != list.end()) {
            cnt++;
        }
    }

    cout << cnt << endl;

}
