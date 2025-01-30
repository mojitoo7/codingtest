#include <iostream>
using namespace std;

// �̹����� 10^11mod 12�� ���ϴ°Ű� 10^11�ϴ°Ŵ� ����Ŀ���� ������ ����
//10^2mod12 = (10mod12)^2mod12�� Ư���� ����
long long a, b, c, d;

long long power(long long b) {
	if (b == 0) return 1;
	if (b == 1) return a % c;

	d = power(b / 2) % c; // 2,1�� �����ؼ� ���ϱ� 
	if (b % 2 == 0) return d * d % c; //¦����
	return d * d % c * a % c; //Ȧ����
}

int main(void) {
	cin >> a >> b >> c;
	cout << power(b);

	return 0;
}