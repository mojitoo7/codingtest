#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> city;
vector<vector<bool>> visited;

bool dfs(int x, int y) {
    if (x == m - 1 && y == n - 1) {
        return true;
    }

    visited[x][y] = true;

    int dx[] = { 1, 0 };
    int dy[] = { 0, 1 };

    for (int i = 0; i < 2; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < m && ny < n && city[nx][ny] == 1 && !visited[nx][ny]) {
            if (dfs(nx, ny)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    city.resize(m, vector<int>(n));
    visited.resize(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> city[i][j];
        }
    }

    if (city[0][0] == 1 && dfs(0, 0)) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }

    return 0;
}
