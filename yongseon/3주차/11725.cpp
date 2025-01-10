#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
//백준 11725번

vector<vector<int>> tree;// 입력 받은 트리 
vector<bool> visited; // 방문했는지 확인 하기 위해 방문 백터 
int ans[100001]; // 부모 노드 출력 배열 
int N;
ostringstream buffer;


void bfs() { //bfs를 이용해서 출력 할 메서드 생성

	visited.assign(N + 1, false);  // 마찬가지로 방문 확인 백터를 N+1로 할당하여 인덱스를 사용 할 수 있도록 함
	queue<int> que;

	que.push(1);  // 루트는 항상 1이므로 1을 queue에 입력 
	visited[1] = true; //1은 방문 항상 방문하기에 true로 설정

	while (!que.empty()) { //큐에 더이상 남아 있지 않을 경우 종료 

		int check = que.front(); que.pop(); //가장 앞의 노드 꺼내고 pop 시킴 

		for (int i = 0; i < tree[check].size(); i++) { //인접 리스트를 이용하여 하나씩 확인

			int next = tree[check][i];

			if (!visited[next]) { //다음 노드가 true가 아닐경우(방문을 해야함)
				ans[next] = check;	//일단 정답 배열에 하나씩 입력 (부모가 누구인지)
				que.push(next);  // 큐에 넣고 
				visited[next] = true;			//방문했다고 표시 	
			}
		}

	}
}

int main()
{


	cin >> N;

	tree.resize(N + 1); //백터의 사이즈를 N보다 1큰 수로 할당하여 인덱스 값을 이용 할 수 있게 함


	//tree[0].push_back(1);

	for (int i = 0; i < N - 1; i++) {
		int node1, node2;

		cin >> node1 >> node2;

		tree[node1].push_back(node2); //서로 연결 시킴 
		tree[node2].push_back(node1); // 서로 연결을 시키면 이미 들어가 있는지 확인 할 필요가 없음 

	}


	bfs(); //bfs 시작 


	for (int i = 2; i <= N; i++) { // 정답 배열에서 출력 
		cout << ans[i] << "\n";
	}

}
