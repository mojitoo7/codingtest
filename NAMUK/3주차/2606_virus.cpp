#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool visited[101];
int virus = 0;
vector<int> connect[101];

void dfs(int n) {
	visited[n] = true;

	for (int i = 0; i < connect[n].size(); ++i) {
		if (!visited[connect[n][i]]) {
			dfs(connect[n][i]);
			virus++;
		}
	}
}

int main()
{
	int com_count, com_pair;
	int x, y;
	cin >> com_count >> com_pair;

	for (int i = 0; i < com_pair; ++i) {
		cin >> x >> y;
		connect[x].push_back(y);
		connect[y].push_back(x);
	}
	dfs(1);

	cout << virus;
}