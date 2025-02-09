#include <iostream>

int triangle[500][500];

int main() {
	int floor,i,j;
	std::cin >> floor;
	
	for (i = 0; i < floor; ++i) {
		for (j = 0; j <= i; ++j) {
			std::cin >> triangle[i][j];
			if (i != 0) {
				if (j == 0) {
					triangle[i][j] = triangle[i][j] + triangle[i - 1][j];
				}
				else if (j == i) {
					triangle[i][j] = triangle[i][j] + triangle[i - 1][j-1];
				}
				else {
					int right =  triangle[i - 1][j], left =  triangle[i - 1][j - 1];
					right > left ? triangle[i][j] += right : triangle[i][j] += left;
				}
			}
		}
	}
	int max = 0;
	for (i = 0; i < floor; ++i) {
		if (max < triangle[floor - 1][i]) {
			max = triangle[floor - 1][i];
		}
	}

	std::cout << max;
	return 0;
}

//		if(max < triangle[floor - 1][i])
//max = triangle[floor - 1][i];