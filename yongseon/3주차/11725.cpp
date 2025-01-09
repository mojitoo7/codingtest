#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
//���� 11725��

vector<vector<int>> tree;// �Է� ���� Ʈ�� 
vector<bool> visited; // �湮�ߴ��� Ȯ�� �ϱ� ���� �湮 ���� 
int ans[100001]; // �θ� ��� ��� �迭 
int N;
ostringstream buffer;


void bfs() { //bfs�� �̿��ؼ� ��� �� �޼��� ����

	visited.assign(N + 1, false);  // ���������� �湮 Ȯ�� ���͸� N+1�� �Ҵ��Ͽ� �ε����� ��� �� �� �ֵ��� ��
	queue<int> que;

	que.push(1);  // ��Ʈ�� �׻� 1�̹Ƿ� 1�� queue�� �Է� 
	visited[1] = true; //1�� �湮 �׻� �湮�ϱ⿡ true�� ����

	while (!que.empty()) { //ť�� ���̻� ���� ���� ���� ��� ���� 

		int check = que.front(); que.pop(); //���� ���� ��� ������ pop ��Ŵ 

		for (int i = 0; i < tree[check].size(); i++) { //���� ����Ʈ�� �̿��Ͽ� �ϳ��� Ȯ��

			int next = tree[check][i];

			if (!visited[next]) { //���� ��尡 true�� �ƴҰ��(�湮�� �ؾ���)
				ans[next] = check;	//�ϴ� ���� �迭�� �ϳ��� �Է� (�θ� ��������)
				que.push(next);  // ť�� �ְ� 
				visited[next] = true;			//�湮�ߴٰ� ǥ�� 	
			}
		}

	}
}

int main()
{


	cin >> N;

	tree.resize(N + 1); //������ ����� N���� 1ū ���� �Ҵ��Ͽ� �ε��� ���� �̿� �� �� �ְ� ��


	//tree[0].push_back(1);

	for (int i = 0; i < N - 1; i++) {
		int node1, node2;

		cin >> node1 >> node2;

		tree[node1].push_back(node2); //���� ���� ��Ŵ 
		tree[node2].push_back(node1); // ���� ������ ��Ű�� �̹� �� �ִ��� Ȯ�� �� �ʿ䰡 ���� 

	}


	bfs(); //bfs ���� 


	for (int i = 2; i <= N; i++) { // ���� �迭���� ��� 
		cout << ans[i] << "\n";
	}

}
