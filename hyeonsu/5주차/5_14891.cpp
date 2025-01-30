#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> v(4, vector<int>(8)); // 톱니바퀴 배열
int ans = 0;

void rotate(vector<int>& gear, int r) {
    if (r == 1) { // 시계 방향 회전 (맨 뒤 값을 맨 앞으로 이동)
        int temp = gear[7];
        for (int i = 6; i >= 0; --i) {
            gear[i + 1] = gear[i];
        }
        gear[0] = temp;
    }
    else { // 반시계 방향 회전 (맨 앞 값을 맨 뒤로 이동)
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
    cin >> c; //회전 횟수
    vector<pair<int, int>> rotations;

    for (int i = 0; i < c; ++i) {
        int t1, t2;
        cin >> t1 >> t2;
        rotations.push_back(pair<int, int>(t1 - 1, t2)); // 시작은 인덱스로 0부터라 
    }

    for (int i = 0; i < rotations.size(); ++i) {
        int idx = rotations[i].first; //회전하는 톱니
        int dir = rotations[i].second; //회전방향

        vector<int> rotateDir(4, 0); // 각 톱니바퀴의 회전 방향 저장
        rotateDir[idx] = dir;

        for (int j = idx; j > 0; --j) { //idx~0까지
            if (v[j][6] != v[j - 1][2]) { //왼쪽 톱니랑 만나는 곳이 다르면
                rotateDir[j - 1] = -rotateDir[j]; //반대방향으로 회전
            }
            else {
                break;
            }
        }

        for (int j = idx; j < 3; ++j) { //idx~3까지
            if (v[j][2] != v[j + 1][6]) { //오른쪽 톱니랑 만나는 곳
                rotateDir[j + 1] = -rotateDir[j];
            }
            else {
                break;
            }
        }

        for (int j = 0; j < 4; ++j) {
            if (rotateDir[j] != 0) { // 1또는 -1로 바뀐거 -> 회전해야하는거
                rotate(v[j], rotateDir[j]);
            }
        }
    }

    if (v[0][0]) ans += 1;  // 1번 톱니바퀴
    if (v[1][0]) ans += 2;  // 2번 톱니바퀴
    if (v[2][0]) ans += 4;  // 3번 톱니바퀴
    if (v[3][0]) ans += 8;  // 4번 톱니바퀴

    cout << ans << endl;
}