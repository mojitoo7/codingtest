#include <iostream>
#include <vector>
using namespace std;

bool computer[10001];
vector<int> graph[10001];

int dfs(int number) {
    int cnt = 1; // 처음거는 1
    computer[number] = true;
    for (int connect : graph[number]) {
        if (!computer[connect]) {
            cnt += dfs(connect);
        }
    }
    return cnt;
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int n, m;
        cin >> n >> m;
        graph[m].push_back(n); //b를 해킹하면 a도 해킹
    }

    int maxcnt = 0;
    vector<int> results;
    for (int i = 1; i <= N; i++) {
        fill(computer, computer + 10001, false); // 방문x로 초기화
        int cnt = dfs(i);
        if (cnt > maxcnt) { // 더크면 최신화
            maxcnt = cnt; 
            results.clear();
            results.push_back(i);
        }
        else if (cnt == maxcnt) {
            results.push_back(i); // 어차피 1부터쌓이니까 오름차순
        }
    }

    for (int result : results) {
        cout << result << " ";
    }
}
