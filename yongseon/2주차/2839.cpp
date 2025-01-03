#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N;
int arr[5001] = { 0 }; //dp 배열 생성



int main() {
	arr[0] = 0; arr[1] = -1; arr[2] = -1; arr[3] = 1; arr[4] = -1; arr[5] = 1; //초기 값 설정

	for (int i = 6; i < 5002; i++) {
		if (arr[i - 3] == -1 && arr[i - 5] == -1) { // 둘다 -1일 경우에는 어떤 경우를 선택해도 -1 
			arr[i] = -1;
		}
		else if (arr[i - 3] == -1) { // 하나만 -1일 경우 다른 경우 선택
			arr[i] = arr[i - 5] + 1;

		}
		else if (arr[i - 5] == -1) { // 위와 동일
			arr[i] = arr[i - 3] + 1;
		}
		else {
			if (arr[i - 3] > arr[i - 5]) { // 둘다 -1이 아닌경우 더 작은쪽 선택 하고 +1
				arr[i] = arr[i - 5] + 1;
			}
			else {
				arr[i] = arr[i - 3] + 1;
			}
		}
	}

	cin >> N;
	int ans = arr[N];
	cout << ans << endl;

}
