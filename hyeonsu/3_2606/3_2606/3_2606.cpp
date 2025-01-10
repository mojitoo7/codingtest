#include <iostream>
using namespace std;

int network[101][101] = { 0, };
bool visit[101] = { 0, };
int computer;
int answer = 0;

void dfs(int x){
	visit[x] = 1;
	answer++;
	for(int i = 1; i <= computer; i++) {
		if(network[x][i] == 1 && visit[i] == 0) {
			dfs(i);
		}
	}
}
int main() {

	int cnt;
	cin >> computer >> cnt;

	for (int i = 0; i < cnt; i++) {
		int a, b;
		cin >> a >> b;
		network[a][b] = 1; //서로 연결
		network[b][a] = 1;
	}
	dfs(1);

	cout << answer - 1 << endl; //1번 제외해야댐
}