#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int r, c, d;
    cin >> r >> c >> d;  // rc�� ��ǥ, d�� ���� �ϵ�������(0123)
    int map[50][50];  // ���� �迭 (0: �� ĭ, 1: ��, 2: û�ҵ� ��)

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

        bool flag = false; //�ٸ����ִ���
        for (int i = 0; i < 4; i++) {
            d = (d + 3) % 4;  // ���� ȸ�� 0->3, 1->0, 2->1, 3->2

            // �������� ȸ���� �� �̵��� ��ġ ���
            int nr = r + dx[d];
            int nc = c + dy[d];

            if (map[nr][nc] == 0) {  // ���� ���⿡ û������ ���� ������ ����
                r = nr;
                c = nc;
                flag = true;
                break;
            }
        }

        if (!flag) {
            int nr = r - dx[d];
            int nc = c - dy[d];
            if (map[nr][nc] == 1) //���̸�
                break;
            else {
                r = nr;
                c = nc;
            }
        }
    }

    cout << count << endl;
}
