#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

//백준 2606
int N, M;
int result = 0;
vector<vector<int>> virus;
vector<bool> visited;

void bfs(int num) { // 바이러스 찾을 bfs 구현

	queue<int> que; //큐에 검사할 애들 넣어 놓기 위해 큐 선언
	que.push(num);

	visited.assign(N + 1, false); //방문한 노드 확인 
	visited[num] = true;
	while (!que.empty()) { //더 이상 큐가 남아 있지 않다는 것은 방문할 곳을 다 방문 했다는 의미 

		int check = que.front(); que.pop(); //큐에서 앞에거 빼고 

		for (int i = 0; i < virus[check].size(); i++) { //갈 수 있는 곳 전부 탐색
			int next = virus[check][i];

			if (!visited[next]) { //방문 노드가 false인 곳만 방문
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

	bfs(1); //1부터 노드 검색 시작

	cout << result << endl; // 결과 출력

}
