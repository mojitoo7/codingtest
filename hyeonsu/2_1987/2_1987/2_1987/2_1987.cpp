#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_R = 20;
const int MAX_C = 20;

const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };

int dfs(int x, int y, int R, int C, const string board[MAX_R], bool alphabet[26], int cnt) {
    int max_cnt = cnt;

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < R && ny >= 0 && ny < C) { //경계 확인
            int idx = board[nx][ny] - 'A';
            if (!alphabet[idx]) { // 알파벳이 처음 등장
                alphabet[idx] = true; //활성화
                max_cnt = max(max_cnt, dfs(nx, ny, R, C, board, alphabet, cnt + 1));
                alphabet[idx] = false; // 안본곳 확인을 위해서 다시 비활성화
            }
        }
    }

    return max_cnt;
}

int main() {
    int R, C;
    cin >> R >> C;

    string board[MAX_R];   // 한줄을 문자열로 입력받음
    for (int i = 0; i < R; ++i) {
        cin >> board[i];
    }

    bool alphabet[26] = { false }; // 모든 알파벳 비활성화
    alphabet[board[0][0] - 'A'] = true; // 첫 알파벳 활성화

    int result = dfs(0, 0, R, C, board, alphabet, 1); // 반환값 or 전역변수 선언
    cout << result << endl;

    return 0;
}
