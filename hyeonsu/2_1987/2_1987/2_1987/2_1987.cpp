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

        if (nx >= 0 && nx < R && ny >= 0 && ny < C) { //��� Ȯ��
            int idx = board[nx][ny] - 'A';
            if (!alphabet[idx]) { // ���ĺ��� ó�� ����
                alphabet[idx] = true; //Ȱ��ȭ
                max_cnt = max(max_cnt, dfs(nx, ny, R, C, board, alphabet, cnt + 1));
                alphabet[idx] = false; // �Ⱥ��� Ȯ���� ���ؼ� �ٽ� ��Ȱ��ȭ
            }
        }
    }

    return max_cnt;
}

int main() {
    int R, C;
    cin >> R >> C;

    string board[MAX_R];   // ������ ���ڿ��� �Է¹���
    for (int i = 0; i < R; ++i) {
        cin >> board[i];
    }

    bool alphabet[26] = { false }; // ��� ���ĺ� ��Ȱ��ȭ
    alphabet[board[0][0] - 'A'] = true; // ù ���ĺ� Ȱ��ȭ

    int result = dfs(0, 0, R, C, board, alphabet, 1); // ��ȯ�� or �������� ����
    cout << result << endl;

    return 0;
}
