#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
�̹����� �Ｚsw�����׽�Ʈ ���⹮���� �ѹ� Ǯ��þ���� �����ͺ�, 
���� ����� �˰��� ������ �����ϰ� ���븸 �����ؼ� �����ϸ� �Ǵµ� �������� ������
*/

int N, M, K; //n�� ũ��, m�� ���� ����, k�� 
int A[11][11]; //���� ���
int A_plus[11][11]; //�ų� �ܿ￡ �� ���
vector<int> arr[11][11]; /// ��ü ���� ����
int dead[11][11]; //���� ����
int dx[] = { 0,0,1,-1,1,-1,1,-1 }; //�밢������ ����ؼ� �� 8��
int dy[] = { 1,-1,0,0,1,-1,-1,1 };


void spring() { //������ �ڽ��� ���̸�ŭ ����� �԰�, ���� 1���� (� ���� ����) ��� �������� ���
    for (int i = 1; i <= N; i++) { // ��ȸ
        for (int j = 1; j <= N; j++) {
            if (!arr[i][j].empty()) {
                sort(arr[i][j].begin(), arr[i][j].end()); //���̼� ����
                for (int k = 0; k < arr[i][j].size(); k++) {
                    if (arr[i][j][k] <= A[i][j]) { // �ڽ��� ���̸�ŭ ��� O
                        A[i][j] -= arr[i][j][k]; //��� �԰�
                        arr[i][j][k]++; //���� 1 ����
                    }
                    else {// �ڽ��� ���̸�ŭ ��� X
                        dead[i][j] += arr[i][j][k] / 2; //���, ����/2 -> ����
                        arr[i][j].erase(arr[i][j].begin() + k); //����
                        k--; //�ε��� ���̱�
                    }
                }
            }
        }
    }
}

void summer() { // ����� ���� -> ������� ��ȯ (����/2 -> ���)
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            A[i][j] += dead[i][j]; //��� �ֱ�
            dead[i][j] = 0; //�ʱ�ȭ
        }
    }
}

void fall() { //���̰� 5�� ����� ������ 8�� ĭ�� ���� 1�� ���� ����
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 0; k < arr[i][j].size(); k++) {
                if (arr[i][j][k] % 5 == 0 && arr[i][j][k] >= 5) { //0�� �ƴ� 5�� ������
                    for (int a = 0; a < 8; a++) {
                        int nx = i + dx[a];
                        int ny = j + dy[a];
                        if (nx >= 1 && ny >= 1 && nx <= N && ny <= N)
                            arr[nx][ny].push_back(1); // ���� ĭ ���� ���� 1 ����
                    }
                }
            }
        }
    }
}

void winter() { //��� �߰� ->�� ĭ�� �߰��Ǵ� ����� ���� A[r][c]
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            A[i][j] += A_plus[i][j]; //��� �ֱ�
}


int main() {
    cin >> N >> M >> K; 

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
            cin >> A_plus[i][j]; //�ܿ︶�� �� ���
            A[i][j] = 5; //ó�� ����� 5
        }

    for (int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        arr[x][y].push_back(z); //���� �Է�
    }

    for (int i = 0; i < K; i++) { //K�� �ݺ�
        spring();
        summer();
        fall();
        winter();
    }

    int result = 0;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            result += arr[i][j].size(); //���� ���� ����

    cout << result;
}