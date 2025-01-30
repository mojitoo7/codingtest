#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;


int main() {
	string arr[1001];

	arr[1] = "SK"; arr[2] = "CY"; arr[3] = "SK";

	for (int i = 4; i < 1001; i++) {
		if ((arr[i - 3] == "SK") && (arr[i - 1] == "SK")) {
			arr[i] = "CY";
		}
		else
			arr[i] = "SK";
	}
	int N;
	cin >> N;

	cout << arr[N] << endl;

}
