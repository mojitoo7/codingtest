#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int r, c, d;
    cin >> r >> c >> d;  // rc는 좌표, d는 방향 북동남서순(0123)
    int map[50][50];  // 지도 배열 (0: 빈 칸, 1: 벽, 2: 청소된 곳)

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
    }

    int dx[4] = { 0, 1, 0, -1 };
    int dy[4] = { -1, 0, 1, 0 };
    int count = 0;

    while (true) {
        if (map[r][c] == 0) {
            map[r][c] = 2;
            count++;
        }

        bool flag = false; //다막혀있는지
        for (int i = 0; i < 4; i++) {
            d = (d + 3) % 4;  // 왼쪽 회전 0->3, 1->0, 2->1, 3->2

            // 왼쪽으로 회전한 후 이동할 위치 계산
            int nr = r + dx[d];
            int nc = c + dy[d];

            if (map[nr][nc] == 0) {  // 왼쪽 방향에 청소하지 않은 공간이 존재
                r = nr;
                c = nc;
                flag = true;
                break;
            }
        }

        if (!flag) {
            int nr = r - dx[d];
            int nc = c - dy[d];
            if (map[nr][nc] == 1) //벽이면
                break;
            else {
                r = nr;
                c = nc;
            }
        }
    }

    cout << count << endl;
}
