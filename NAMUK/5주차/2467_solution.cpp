#include <iostream>
#include <stdio.h>
int solution[100000];
int main() {

	int n,i;
	std::cin >> n;

	for (i = 0; i < n; ++i) {
		std::cin >> solution[i];
	}
	
	int start = 0, end = n - 1;
	int temp = 2147483000, compare = solution[start] + solution[end];

	int result_1 = solution[start], result_2 = solution[end];

	for (i = 0; i < n; ++i) {
		temp = solution[start] + solution[end];
		//std::cout << start << end << std::endl;
		if (end == start) {
			break;
		}
		
		//std::cout << temp << std::endl;
		if (temp < 0) {
			temp = temp * -1;
			if (temp < compare) {
				compare = temp;
				result_1 = solution[start];
				result_2 = solution[end];
			}
			++start;
		}
		else {
			if (temp < compare) {
				compare = temp;
				result_1 = solution[start];
				result_2 = solution[end];
			}
			--end;
		}
		
		if (compare == 0)
			break;
	}
	printf("%d %d", result_1, result_2);
}