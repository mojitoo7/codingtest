#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N;
int arr[5001] = { 0 }; //dp �迭 ����



int main() {
	arr[0] = 0; arr[1] = -1; arr[2] = -1; arr[3] = 1; arr[4] = -1; arr[5] = 1; //�ʱ� �� ����

	for (int i = 6; i < 5002; i++) {
		if (arr[i - 3] == -1 && arr[i - 5] == -1) { // �Ѵ� -1�� ��쿡�� � ��츦 �����ص� -1 
			arr[i] = -1;
		}
		else if (arr[i - 3] == -1) { // �ϳ��� -1�� ��� �ٸ� ��� ����
			arr[i] = arr[i - 5] + 1;

		}
		else if (arr[i - 5] == -1) { // ���� ����
			arr[i] = arr[i - 3] + 1;
		}
		else {
			if (arr[i - 3] > arr[i - 5]) { // �Ѵ� -1�� �ƴѰ�� �� ������ ���� �ϰ� +1
				arr[i] = arr[i - 5] + 1;
			}
			else {
				arr[i] = arr[i - 3] + 1;
			}
		}
	}

	cin >> N;
	int ans = arr[N];
	cout << ans << endl;

}
