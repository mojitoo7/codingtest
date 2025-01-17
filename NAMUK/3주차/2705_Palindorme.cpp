#include <iostream>
#include <vector>

using namespace std;


int count_palin(int n) {
	
	int x = 0;
	if (n == 0) {
		//palin_count++;
		return 1;
	}
	else {
		if (n & 1) {
			for (int i = 1; n - i >= 0;  i += 2) {
				i += 2;
				x +=count_palin(n-i/2); // 여기서 빠져서 for문의 i+=2를 못한다
			}
			
		}
		else {
			for (int i = 0; n - i >= 0;  i += 2) {
				cout << n - i;
				x +=count_palin(n - i / 2);
			}
			
		}
		return x;
	}
}
int main() {
	int case_count;

	cin >> case_count;
	cout << 1;

	//count_palin(7);
	cout << count_palin(7);

	return 0;
}