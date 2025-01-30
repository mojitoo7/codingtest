#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N, M;



int main() {

	unordered_map<string, string> map; // �˻��� ���� map ����
	vector<string> ans; // �赵���� ���� �̸� ������ ���� 

	cin >> N >> M;

	for (int i = 0; i < N; i++) { //�赵 ���� �̸��� map�� ����
		string nohear;
		cin >> nohear;

		map[nohear] = nohear;

	}
	for (int i = 0; i < M; i++) { //���� ���� �̸��� key������ map���� �˻� 
		string nosee;
		cin >> nosee;

		if (nosee == map[nosee]) { // ������ ���Ϳ� ���� 
			ans.push_back(nosee);
		}

	}
	sort(ans.begin(), ans.end());

	cout << ans.size() << "\n";

	for (string name : ans) {
		cout << name << "\n";
	}


}
