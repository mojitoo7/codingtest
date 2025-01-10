#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

set<int> primeNum;  //소수 저장 할 집합

int main()
{
	int n;
	cin >> n;

	primeNum.insert(2); primeNum.insert(3); // 소수 2와 3을 미리 저장
	for (int i = 4; i <= 10000; i++) { // 4부터 범위까지의 수 중에 소수가 있는지 확인 
		bool prime = false;
		for (int j = 2; j * j <= i; j++) { //소수를 확인 할때는 무조건 제곱근 안에서 확인(제곱근 안에서 확인해도 충분함)
			if (i % j == 0) {
				prime = true;
				break;
			}
		}
		if (!prime) primeNum.insert(i); // 소수면 집합에 저장
	}




	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		int up = num / 2; int down = num / 2;  
		//수를 비교할때 무조건 짝수 이므로 반으로 나눈 후 하나씩 거리를 늘려가면서 비교를 진행 해야함
			

		while (true) {

			if (primeNum.count(up) == 1 && primeNum.count(down) == 1) {
				cout << down << " " << up << endl;
				break;
			}
			up++; down--;
		}
	}


}