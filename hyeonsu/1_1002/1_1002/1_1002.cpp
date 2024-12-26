#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int cnt;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		int x1, x2, y1, y2, r1, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		double distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

		if (distance == 0) {
			if (r1 == r2) cout << -1 << endl;
			else cout << 0 << endl;
		}
		else if (distance > r1 + r2 || distance < abs(r1 - r2)) {
			cout << 0 << endl;
		}
		else if (distance == r1 + r2 || distance == abs(r1 - r2)) {
			cout << 1 << endl;
		}
		else {
			cout << 2 << endl;
		}
	}
}