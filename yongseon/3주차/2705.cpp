#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int T;
vector<int> ans;  //dp로 정답을 저장할 백터 (처음에 배열로 접근했으나 메모리 초과로 인하여 백터로 재생성)
vector<int> print;

int main()
{
	cin >> T;
	ans.push_back(0); ans.push_back(1); ans.push_back(2); ans.push_back(2); ans.push_back(4);
	//초기 4까지의 값을 저장 

	for (int i = 5; i < 1002; i++) {// 주어진 범위 전체에 대하여 반복

		if (i % 2 == 0) { //짝수와 홀수 일때를 구분 하여 진행 
			int num = 0; //i에 수를 빼서 진행
			int result = 1; //정답 백터에 저장할 변수 

			while (true) {
				if ((i - num) == 0) break; // 현재 수에서 num을 뺀 값이 0이 되면 마이너스가 되므로 종료 

				int re = (i - num) / 2; //num을 재외하고 양옆의 수에 대해 dp를 진행하여 값을 가져옴

				result = result + ans[re]; // 가져온 값을 재귀적으로 더함
				num = num + 2;
			}
			ans.push_back(result); // 값을 백터에 저장
		}
		else {  // 홀수일때는 짝수일때와 동일하게 진행 로직을 비슷하므로 생략
			int num = 1;
			int result = 1;

			while (true) {
				if ((i - num) == 0) break;

				int re = (i - num) / 2;

				result = result + ans[re];
				num = num + 2;
			}
			ans.push_back(result);
		}
	}

	for (int i = 0; i < T; i++) {  //입력받은 수에 대해서 백터에 저장

		int num;
		cin >> num;

		print.push_back(ans[num]);

	}

	for (int nums : print) { //백터 출력
		cout << nums << "\n";
	}



}
