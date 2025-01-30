#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<pair<int, int>> grade;

		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			grade.push_back({ x,y });
		}

		sort(grade.begin(), grade.end());
		int max = 1;
		int temp = 0;
		for (int i = 1; i < n; i++) {
			if (grade[temp].second > grade[i].second) {
				max++;
				temp = i;
			}
		}

		cout << max << endl;
	}
}