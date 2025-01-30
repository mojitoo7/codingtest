#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<long long> list(n);
	for (int i = 0; i < n; i++) {
		cin >> list[i];
	}

	for (int i = 0; i < m; i++) { // 처음에는 그냥 한번만 정렬해서 가장작은수 m번 그다움수 m-1번 더하는걸로 생각했는데 합친수가 커지는 정도를 모르니 매번 재정렬해야함
		sort(list.begin(), list.end());
		long long a = list[0];
		long long b = list[1];
		list[0] = a + b;
		list[1] = a + b;
	}

	long long sum = 0;
	for (int i = 0; i < n; i++) { //n을 m으로 잘못쓰고 한 20분해맴
		sum += list[i];
	}

	cout << sum << endl;
	return 0;
}