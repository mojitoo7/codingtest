#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
	fastio;
	int n;
	long long result = 0;
	char hid; // 입력 받을 문장
	string num = "";

	cin >> n; // 총 길이 입력 받기 


	while (n--) { // 길이 만큼 반복 
		cin >> hid;

		if (isdigit(hid)) {  // 숫자이면 저장했다가
			num += hid;
			if (n == 0) {
				result += stoi(num);
			}
		}

		else if (isalpha(hid)) {  /*알파벳이면 저장했던 숫자들을
									전부 숫자로 바꾸고 계산*/
			if (num != "") {
				result += stoi(num);
				num = "";
			}
		}
	}
	cout << result << endl;

}