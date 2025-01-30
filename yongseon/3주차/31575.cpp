#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int arr[300][300] = { 0 };
bool visited[300][300] = { false };
int N, M;

void dfs() {  //dfs�� �̿��ؿ� ����

	int dx[2] = { 1,0 }; int dy[2] = { 0,1 }; // ���� �ִ� ���� ������, �Ʒ� �ۿ� �����Ƿ� ��ǥ �� ����
	stack<pair<int, int>> bitcoin;  //������ �̿��Ͽ� �� ���� ����

	bitcoin.push({ 0,0 }); // ���� ���� ����
	visited[0][0] = true;

	while (!bitcoin.empty()) { // ������ �������� ����
		pair<int, int> next = bitcoin.top(); bitcoin.pop();  // ���ÿ��� �ϳ� ������ �� 

		for (int i = 0; i < 2; i++) { // �Ʒ���, ������ �˻��� ���� 2�� ����

			int x = dx[i] + next.first; int y = dy[i] + next.second;

			if (x >= M || y >= N) continue;  // ���� ���������� �Ѿ 
			if (visited[x][y] || arr[x][y] == 0) continue; // �̹� ���� ���̳� 0������ ���� �Ѿ

			visited[x][y] = true;
			bitcoin.push({ x, y }); //���� ����

		}
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;
			if (num == 1) arr[i][j] = 1;

		}
	}
	dfs();

	if (visited[M - 1][N - 1]) {  // ���� ��ǥ�� ������ �湮�� ���� ������ Yes �ƴϸ� No ���
		cout << "Yes";
	}
	else if (!visited[M - 1][N - 1]) {
		cout << "No";
	}

}