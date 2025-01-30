#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
	ostringstream buffer;
	int N;

	string arr[8] = { "000000", "001111","010011","011100","100110" ,"101001" , "110101","111010" };
	string code = "";
	string answer = " ";
	cin >> N >> code;

	for (int i = 0; i < N; i++) {
		string ans;
		int num = i * 6;
		ans = code.substr(num, 6);
		int checked;
		bool add = false;

		for (int k = 0; k < 8; k++) {
			checked = 0;

			for (int j = 0; j < 6; j++) {
				if (arr[k][j] == ans[j]) {
					continue;
				}
				else
					checked++;
			}
			if (checked == 0 || checked == 1) {
				char word = k + 'A';
				buffer << word;
				add = true;
			}
		}
		if (!add) {
			cout << i + 1;
			return 0;
		}
	}

	string result = buffer.str();

	cout << result << endl;


}