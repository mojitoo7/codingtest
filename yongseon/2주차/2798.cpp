#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
set<int> pro;

void combination(vector<int>& vect, vector<int>& ans, int r, int t) { // �־��� �����߿��� ������ �̿��Ͽ� ����� ��
	if (ans.size() == t) { // �־��� ������ ���ٸ� ������ ���߰� ����
		int reuslt = 0;
		for (int nums : ans) {  // �� ���
			reuslt += nums;
		}
		pro.insert(reuslt); // ���� ���տ� �߰�
		return;
	}
	for (int i = r; i < vect.size(); i++) {
		ans.push_back(vect[i]); // ���� �ε����� ���� ���Ϳ� �߰�
		combination(vect, ans, i + 1, t); // �ϳ� ���� �ε����� ������ ��ͷ� ���� 
		ans.pop_back(); // ������ �߰��ߴ� �ε����� ���� �� �ٽ� ����

	}



}


int main() {

	int N, M;
	vector<int> blackjack;
	vector<int> answer;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		blackjack.push_back(num);
	}
	combination(blackjack, answer, 0, 3);

	while (true) { // ���� ���տ� �ִ��� Ȯ�� ������ ���� �ϳ� �ٿ��� �ٽ� Ȯ��
		if (pro.count(M) == 1) {
			cout << M;
			return 0;
		}
		else { M--; }
	}

}
