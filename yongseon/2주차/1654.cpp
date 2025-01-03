#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;


int N, K;
long long mid;

int main() {

	vector<long int> lan;
	long long lansum = 0;

	cin >> K >> N;

	for (int i = 0; i < K; i++) {
		int num; cin >> num;
		lan.push_back(num);
	}
	sort(lan.begin(), lan.end());
	long long max = lan[lan.size() - 1];
	long long min = 1;

	while (min <= max) {
		lansum = 0;
		mid = (max + min) / 2;

		for (long int j = 0; j < lan.size(); j++) {
			lansum += (lan[j] / mid);
		}
		if (lansum >= N) {
			min = mid + 1;
		}
		else if (lansum < N) {
			max = mid - 1;
		}


	}

	if (lansum < N) {
		mid -= 1;
	}
	cout << mid;


	return 0;
}
