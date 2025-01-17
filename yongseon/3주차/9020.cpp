#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

set<int> primeNum;  //�Ҽ� ���� �� ����

int main()
{
	int n;
	cin >> n;

	primeNum.insert(2); primeNum.insert(3); // �Ҽ� 2�� 3�� �̸� ����
	for (int i = 4; i <= 10000; i++) { // 4���� ���������� �� �߿� �Ҽ��� �ִ��� Ȯ�� 
		bool prime = false;
		for (int j = 2; j * j <= i; j++) { //�Ҽ��� Ȯ�� �Ҷ��� ������ ������ �ȿ��� Ȯ��(������ �ȿ��� Ȯ���ص� �����)
			if (i % j == 0) {
				prime = true;
				break;
			}
		}
		if (!prime) primeNum.insert(i); // �Ҽ��� ���տ� ����
	}




	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		int up = num / 2; int down = num / 2;  
		//���� ���Ҷ� ������ ¦�� �̹Ƿ� ������ ���� �� �ϳ��� �Ÿ��� �÷����鼭 �񱳸� ���� �ؾ���
			

		while (true) {

			if (primeNum.count(up) == 1 && primeNum.count(down) == 1) {
				cout << down << " " << up << endl;
				break;
			}
			up++; down--;
		}
	}


}