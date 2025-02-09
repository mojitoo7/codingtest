#include <iostream>
#include<algorithm>
//long long 으로하니까 됨
long long card_list[1000];
int main() {

	int total_card, combine_count,i;
	std::cin >> total_card >> combine_count;
	for (i = 0; i < total_card; ++i) {
		std::cin >> card_list[i];
	}

	for (i = 0; i < combine_count; ++i) {
		std::sort(card_list, card_list + total_card);
		long long temp  = card_list[0] + card_list[1];
		card_list[0] = card_list[1] = temp;
	}
	long long result = 0;
	for (i = 0; i < total_card; ++i) {
		result += card_list[i];
	}
	std::cout << result;
}