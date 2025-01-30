#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[100001];
int parent[100001];

void dfs(int node) { //dfs로 찾고 부모노드를 저장
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (parent[next] == 0) {
			parent[next] = node;
			dfs(next);
		}
	}

}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int from, to;
		cin >> from >> to;
		//양방향그래프
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	dfs(1);

	for (int i = 2; i <= n; i++) {
		cout << parent[i] << '\n';
	}

	return 0;
}