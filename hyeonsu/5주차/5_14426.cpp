#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> temp(N);
    vector<string> find(M);

    for (int i = 0; i < N; i++) {
        cin >> temp[i];
    }

    for (int i = 0; i < M; i++) {
        cin >> find[i];
    }

    sort(temp.begin(), temp.end());

    int cnt = 0;
    for (const string& prefix : find) {
        auto it = lower_bound(temp.begin(), temp.end(), prefix);
        if (it != temp.end() && it->substr(0, prefix.length()) == prefix) {
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}
