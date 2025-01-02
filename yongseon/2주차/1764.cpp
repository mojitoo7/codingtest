#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N, M;



int main() {

	unordered_map<string, string> map; // 검색을 위한 map 구현
	vector<string> ans; // 듣도보도 못한 이름 저장할 백터 

	cin >> N >> M;

	for (int i = 0; i < N; i++) { //듣도 못한 이름을 map에 저장
		string nohear;
		cin >> nohear;

		map[nohear] = nohear;

	}
	for (int i = 0; i < M; i++) { //보도 못한 이름을 key값으로 map에서 검색 
		string nosee;
		cin >> nosee;

		if (nosee == map[nosee]) { // 있으면 백터에 저장 
			ans.push_back(nosee);
		}

	}
	sort(ans.begin(), ans.end());

	cout << ans.size() << "\n";

	for (string name : ans) {
		cout << name << "\n";
	}


}
