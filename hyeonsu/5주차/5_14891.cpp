#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> v(4, vector<int>(8)); // ��Ϲ��� �迭
int ans = 0;

void rotate(vector<int>& gear, int r) {
    if (r == 1) { // �ð� ���� ȸ�� (�� �� ���� �� ������ �̵�)
        int temp = gear[7];
        for (int i = 6; i >= 0; --i) {
            gear[i + 1] = gear[i];
        }
        gear[0] = temp;
    }
    else { // �ݽð� ���� ȸ�� (�� �� ���� �� �ڷ� �̵�)
        int temp = gear[0];
        for (int i = 0; i < 7; ++i) {
            gear[i] = gear[i + 1];
        }
        gear[7] = temp;
    }
}

int main() {
    for (int i = 0; i < 4; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < 8; ++j) {
            v[i][j] = s[j] - '0';
        }
    }

    int c;
    cin >> c; //ȸ�� Ƚ��
    vector<pair<int, int>> rotations;

    for (int i = 0; i < c; ++i) {
        int t1, t2;
        cin >> t1 >> t2;
        rotations.push_back(pair<int, int>(t1 - 1, t2)); // ������ �ε����� 0���Ͷ� 
    }

    for (int i = 0; i < rotations.size(); ++i) {
        int idx = rotations[i].first; //ȸ���ϴ� ���
        int dir = rotations[i].second; //ȸ������

        vector<int> rotateDir(4, 0); // �� ��Ϲ����� ȸ�� ���� ����
        rotateDir[idx] = dir;

        for (int j = idx; j > 0; --j) { //idx~0����
            if (v[j][6] != v[j - 1][2]) { //���� ��϶� ������ ���� �ٸ���
                rotateDir[j - 1] = -rotateDir[j]; //�ݴ�������� ȸ��
            }
            else {
                break;
            }
        }

        for (int j = idx; j < 3; ++j) { //idx~3����
            if (v[j][2] != v[j + 1][6]) { //������ ��϶� ������ ��
                rotateDir[j + 1] = -rotateDir[j];
            }
            else {
                break;
            }
        }

        for (int j = 0; j < 4; ++j) {
            if (rotateDir[j] != 0) { // 1�Ǵ� -1�� �ٲ�� -> ȸ���ؾ��ϴ°�
                rotate(v[j], rotateDir[j]);
            }
        }
    }

    if (v[0][0]) ans += 1;  // 1�� ��Ϲ���
    if (v[1][0]) ans += 2;  // 2�� ��Ϲ���
    if (v[2][0]) ans += 4;  // 3�� ��Ϲ���
    if (v[3][0]) ans += 8;  // 4�� ��Ϲ���

    cout << ans << endl;
}