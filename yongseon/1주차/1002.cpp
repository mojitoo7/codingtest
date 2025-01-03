#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int T;

int main() {

	ostringstream buffer;

	cin >> T;

	double x1, x2, y1, y2, r1, r2;

	for (int i = 0; i < T; i++) {

		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		double dist;
		dist = pow(x2 - x1, 2) + pow(y2 - y1, 2);


		double distance, absdist;
		distance = r2 + r1;
		absdist = abs(r2 - r1);

		absdist = pow(absdist, 2);
		distance = pow(distance, 2);


		if (x1 == x2 && y1 == y2) {
			if (r1 == r2) {
				buffer << "-1" << "\n";
			}
			else {
				buffer << "0" << "\n";
			}
		}
		else {

			if (dist > distance || dist < absdist) {
				buffer << "0" << "\n";

			}
			else if (dist == distance || dist == absdist) {
				buffer << "1" << "\n";

			}
			else {
				buffer << "2" << "\n";
			}
		}
	}

	cout << buffer.str() << endl;

}
