#include <iostream>
#include <stdio.h>

bool common_divide_check(long long common_divide, long long i, long long x_i) {
	int j = 2;
	int k = 0;
	while (k <= i) {
		k = common_divide * j;
		if ((i % k == 0) && (x_i % k == 0)) {
			return false;
		}
		j++;
	}
	return true;

}

int main() {
	long long common_divide, common_multi;

	std::cin >> common_divide >> common_multi;

	long long x = common_divide * common_multi;

	long long temp_x;
	long long temp_y;

	long long out_x = common_multi, out_y = common_multi;


	for (long long i = common_divide; i <= common_multi; i += common_divide) {
		if (common_multi % i == 0 && common_multi % (x / i) ==0 && (x / i) % common_divide == 0) {
			if (common_divide_check(common_divide, i, x / i)) {
				temp_x = i;
				temp_y = x / i;
				//std::cout << temp_x << 'a' << temp_y << std::endl;
				if (out_x + out_y > temp_x + temp_y) {
					out_x = temp_x;
					out_y = temp_y;
				}
			}
		}



		//std::cout << out_x <<'b' << out_y << std::endl;
		//std::cout << i;
	}


	printf("%d %d", out_x, out_y);

	return 0;
}