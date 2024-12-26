#include <iostream>
using namespace std;

int main() {
	int row, col;
	cin >> row >> col;

	char castle[50][50];

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> castle[i][j];
		}
	}

	int cnt_row = row;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (castle[i][j] == 'X') {
				cnt_row--;
				break;
			}
		}
	}

	int cnt_col = col;
	for (int j = 0; j < col; j++) {
		for (int i = 0; i < row; i++) {
			if (castle[i][j] == 'X') {
				cnt_col--;
				break;
			}
		}
	}

	cout << (cnt_row > cnt_col ? cnt_row : cnt_col) << endl;

	return 0;
}