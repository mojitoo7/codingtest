#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int cnt=0;


	if (n%5==0) {
		cnt = n / 5; // 5kg��
	}
	else if (n % 5 == 1) { // ��ü���� 5kg�����ϰ� ��� �� ������ 6kg�� 3kg 2��

		cnt = n / 5 + 1;
	}
	else if (n % 5 == 2) { // ��ü���� 10kg(5kg*2)�����ϰ� ��� �� ������ 12kg�� 3kg 4��
		if(n==7) {
			cout << -1;
			return 0;
		}
		cnt = n / 5 + 2;
	}
	else if (n % 5 == 3) { // 3kg �� ������ 
		cnt += n / 5 + 1;
	}
	else if (n % 5 == 4) {// ��ü���� 5kg�����ϰ� ��� �� ������ 9kg�� 3kg 3��
		if (n == 4) {
			cout << -1;
			return 0;
		}		cnt = n / 5 + 2;
	}
	cout << cnt;
	
}