#include <iostream>
using namespace std;

// 이문제는 10^11mod 12를 구하는거고 10^11하는거는 숫자커지면 무조건 오류
//10^2mod12 = (10mod12)^2mod12의 특성을 구현
long long a, b, c, d;

long long power(long long b) {
	if (b == 0) return 1;
	if (b == 1) return a % c;

	d = power(b / 2) % c; // 2,1로 분해해서 구하기 
	if (b % 2 == 0) return d * d % c; //짝수면
	return d * d % c * a % c; //홀수면
}

int main(void) {
	cin >> a >> b >> c;
	cout << power(b);

	return 0;
}