#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

int main() {
	int t, n;
	int x1, x2;
	std::cin >> t;

	while (t--) {
		std::cin >> n;
		std::vector<std::pair<int, int>> v;
		for (int i = 0; i < n; ++i) {
			std::cin >> x1 >> x2;
			v.push_back(std::make_pair(x1, x2));
		}
		sort(v.begin(), v.end());
		int count = 0;
		int min_rank = n + 1;
		for (int i = 0; i < v.size(); ++i) {
			if (v[i].second < min_rank) {
				count++;
				min_rank = v[i].second;
				if (v[i].second == 1) {
					break;
				}
			}
		}
		std::cout << count << std::endl;
	}

	return 0;
}