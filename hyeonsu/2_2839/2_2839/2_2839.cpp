#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int cnt=0;


	if (n%5==0) {
		cnt = n / 5; // 5kg만
	}
	else if (n % 5 == 1) { // 전체에서 5kg제외하고 계산 후 나머지 6kg를 3kg 2개

		cnt = n / 5 + 1;
	}
	else if (n % 5 == 2) { // 전체에서 10kg(5kg*2)제외하고 계산 후 나머지 12kg를 3kg 4개
		if(n==7) {
			cout << -1;
			return 0;
		}
		cnt = n / 5 + 2;
	}
	else if (n % 5 == 3) { // 3kg 딱 떨어짐 
		cnt += n / 5 + 1;
	}
	else if (n % 5 == 4) {// 전체에서 5kg제외하고 계산 후 나머지 9kg를 3kg 3개
		if (n == 4) {
			cout << -1;
			return 0;
		}		cnt = n / 5 + 2;
	}
	cout << cnt;
	
}