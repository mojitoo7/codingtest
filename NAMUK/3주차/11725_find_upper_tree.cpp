#include <iostream>
#include <vector>
#include <queue>

using namespace std;
bool visited[100001];
int upper[100001];
vector<int> tree[100001];

void tree_by_n(int n) {

	visited[n] = true;

	for (int i = 0; i < tree[n].size(); ++i) {
		if (!visited[tree[n][i]]) {
			upper[tree[n][i]] = n; //4�� �θ�� n�̶�� ����
			tree_by_n(tree[n][i]);//4�� ���ؼ� n���� ����
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n,node1, node2;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> node1 >> node2;
		tree[node1].push_back(node2); // ��¥�� 1�� ���ĵ� ���̱� ������ ���ʴ� �־��ְ� ��Ȱ��ȭ ��Ű�� ��������
		tree[node2].push_back(node1);
	}

	tree_by_n(1);

	for (int i = 2; i <= n; ++i) {
		cout << upper[i] << endl;
	}

}
