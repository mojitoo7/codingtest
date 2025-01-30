#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<long long> list(n);
	for (int i = 0; i < n; i++) {
		cin >> list[i];
	}

	for (int i = 0; i < m; i++) { // ó������ �׳� �ѹ��� �����ؼ� ���������� m�� �״ٿ�� m-1�� ���ϴ°ɷ� �����ߴµ� ��ģ���� Ŀ���� ������ �𸣴� �Ź� �������ؾ���
		sort(list.begin(), list.end());
		long long a = list[0];
		long long b = list[1];
		list[0] = a + b;
		list[1] = a + b;
	}

	long long sum = 0;
	for (int i = 0; i < n; i++) { //n�� m���� �߸����� �� 20���ظ�
		sum += list[i];
	}

	cout << sum << endl;
	return 0;
}