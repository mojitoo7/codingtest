#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		int a = n / 2; //�߰����� ����(���̰� 0�϶�)
		int b = n / 2;

		while (true) {
			bool isPrime = true;
			for (int j = 2; j * j <= a; j++) { //������ j*(a/j)=a�̴ϱ� ������(�߰�)������ Ȯ��
				if (a % j == 0) { // ���������� �Ҽ��� �ƴϰ�
					isPrime = false;
					break;
				}
			}

			if (isPrime) { // a�� �������� b Ȯ��
				bool isPrime = true; 
				for (int j = 2; j * j <= b; j++) {
					if (b % j == 0) {
						isPrime = false;
						break;
					}
				}

				if (isPrime) { // �Ѵ� �Ҽ��� Ȯ��
					cout << a << b << endl;
					break;
				}
			}

			a--; // a�� �� ������
			b++;//b�� Ŀ���°�
		}
	}
}