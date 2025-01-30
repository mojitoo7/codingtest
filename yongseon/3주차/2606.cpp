#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

//���� 2606
int N, M;
int result = 0;
vector<vector<int>> virus;
vector<bool> visited;

void bfs(int num) { // ���̷��� ã�� bfs ����

	queue<int> que; //ť�� �˻��� �ֵ� �־� ���� ���� ť ����
	que.push(num);

	visited.assign(N + 1, false); //�湮�� ��� Ȯ�� 
	visited[num] = true;
	while (!que.empty()) { //�� �̻� ť�� ���� ���� �ʴٴ� ���� �湮�� ���� �� �湮 �ߴٴ� �ǹ� 

		int check = que.front(); que.pop(); //ť���� �տ��� ���� 

		for (int i = 0; i < virus[check].size(); i++) { //�� �� �ִ� �� ���� Ž��
			int next = virus[check][i];

			if (!visited[next]) { //�湮 ��尡 false�� ���� �湮
				que.push(next);
				visited[next] = true;
				result++;
			}
		}

	}

}
int main()
{
	cin >> N >> M;
	virus.resize(N + 1);

	for (int i = 0; i < M; i++) {

		int num1, num2;
		cin >> num1 >> num2;

		virus[num1].push_back(num2);
		virus[num2].push_back(num1);

	}

	bfs(1); //1���� ��� �˻� ����

	cout << result << endl; // ��� ���

}
