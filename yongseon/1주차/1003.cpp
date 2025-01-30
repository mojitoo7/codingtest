#include <iostream>
#include<algorithm>
#include<sstream>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N;
int dp1[41];
int dp2[41];

int main() {

	fastio;
	ostringstream buffer;

	cin >> N;

	dp1[0] = 1;
	dp2[0] = 0;
	dp2[1] = 1;
	dp1[1] = 0;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		for (int k = 2; k <= n; k++) {
			dp1[k] = dp1[k - 1] + dp1[k - 2];
			dp2[k] = dp2[k - 1] + dp2[k - 2];
		}
		buffer << dp1[n] << " " << dp2[n] << endl;
	}
	cout << buffer.str();

	return 0;
}
