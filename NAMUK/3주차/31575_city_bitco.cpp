#include <iostream>

int arr[301][301];
bool visited[301][301];

using namespace std;

void dfs(int x,int y,int col, int row) {

	if (arr[x][y] == 1 && !visited[x][y]) {
			visited[x][y] = true;
			if (x < col-1 && y < row-1) {
				dfs(x, y + 1, col, row);
				dfs(x + 1, y, col, row);
			}
			else if (x < col-1  && y >= row-1) {
				dfs(x + 1, y, col, row);
			}
			else if (y < row-1 && x >= col-1) {
				dfs(x, y + 1, col, row);
			}
		
	}
	else {
		return;
	}
}
int main() {
	int  col,row,i,j;

	cin >> col >> row;
	for (i = 0; i < row; ++i) {
		for (j = 0; j < col; ++j) {
			cin >> arr[i][j];
		}
	}
	dfs(0, 0, col, row);

	if (visited[col-1][row-1]) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	return 0;
}