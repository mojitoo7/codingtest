#include <iostream>
#include <string>


struct node {
	struct node* alpha_next[26];
	node() { 
		for (int i = 0; i < 26; i++) alpha_next[i] = nullptr;
	}
};

void insert_stinrg(std::string str , node *first_floor) {
	node *cur = first_floor;
	for (int i = 0; i < str.size(); ++i) {
		if (!cur->alpha_next[str[i] - 'a']) { // 0이면 node할당하기
			cur = cur->alpha_next[str[i] - 'a'] = new node(); //다음cur
		}
		else { //0이 아니면 그냥 다음거 받기
			cur = cur->alpha_next[str[i] - 'a'];
		}
	}
}

int find_string(std::string str, node* first_floor) {
	node* cur = first_floor;
	for (int i = 0; i < str.size(); ++i) {
		if (cur->alpha_next[str[i] - 'a'] == nullptr) { 
			return 0;
		}
		cur = cur->alpha_next[str[i] - 'a'];
	}
	return 1;
}


int main() {
	int s_count,str_count;

	std::cin >> s_count >> str_count;

	node *first_floor = new node();


	std::string temp_str;
	for (int i = 0; i < s_count; ++i) {
		std::cin >> temp_str;
		insert_stinrg(temp_str, first_floor);
	}

	int result = 0;

	for (int i = 0; i < str_count; ++i) {
		std::cin >> temp_str;
		result += find_string(temp_str, first_floor);
	}

	std::cout << result;
}