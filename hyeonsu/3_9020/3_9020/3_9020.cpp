#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		int a = n / 2; //중간으로 시작(차이가 0일때)
		int b = n / 2;

		while (true) {
			bool isPrime = true;
			for (int j = 2; j * j <= a; j++) { //어차피 j*(a/j)=a이니까 제곱근(중간)까지만 확인
				if (a % j == 0) { // 나뉘어지면 소수가 아니고
					isPrime = false;
					break;
				}
			}

			if (isPrime) { // a는 만족상태 b 확인
				bool isPrime = true; 
				for (int j = 2; j * j <= b; j++) {
					if (b % j == 0) {
						isPrime = false;
						break;
					}
				}

				if (isPrime) { // 둘다 소수면 확인
					cout << a << b << endl;
					break;
				}
			}

			a--; // a가 더 작은거
			b++;//b는 커지는거
		}
	}
}