#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
set<int> pro;

void combination(vector<int>& vect, vector<int>& ans, int r, int t) { // 주어진 개수중에서 조합을 이용하여 고르기로 함
	if (ans.size() == t) { // 주어진 개수와 같다면 조합을 멈추고 연산
		int reuslt = 0;
		for (int nums : ans) {  // 합 계산
			reuslt += nums;
		}
		pro.insert(reuslt); // 정답 집합에 추가
		return;
	}
	for (int i = r; i < vect.size(); i++) {
		ans.push_back(vect[i]); // 현재 인덱스의 값을 백터에 추가
		combination(vect, ans, i + 1, t); // 하나 다음 인덱스를 가지고 재귀로 조합 
		ans.pop_back(); // 직전에 추가했던 인덱스를 제거 후 다시 진행

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

	while (true) { // 정답 집합에 있는지 확인 없으면 숫자 하나 줄여서 다시 확인
		if (pro.count(M) == 1) {
			cout << M;
			return 0;
		}
		else { M--; }
	}

}
