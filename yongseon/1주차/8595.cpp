#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
	fastio;
	int n;
	long long result = 0;
	char hid; // �Է� ���� ����
	string num = "";

	cin >> n; // �� ���� �Է� �ޱ� 


	while (n--) { // ���� ��ŭ �ݺ� 
		cin >> hid;

		if (isdigit(hid)) {  // �����̸� �����ߴٰ�
			num += hid;
			if (n == 0) {
				result += stoi(num);
			}
		}

		else if (isalpha(hid)) {  /*���ĺ��̸� �����ߴ� ���ڵ���
									���� ���ڷ� �ٲٰ� ���*/
			if (num != "") {
				result += stoi(num);
				num = "";
			}
		}
	}
	cout << result << endl;

}