#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;

	int result = 0;
	string temp = "";
	bool minus = false;
	for (int i = 0; i <= str.size(); i++) {
		if (str[i] == '+' || str[i] == '-' || str[i] == '\0') { // 부호나 마지막일때
			if (minus) { //음수상태일때면 음수로 더하기
				result -= stoi(temp); //정수화
			} 
			else {
				result += stoi(temp); //처음은 무조건 숫자
			}

			temp = "";

			if (str[i] == '-') { //한번 빼기가 나오면 뒤에는 갈호예쁘게 쳐서 다 음수 만든다고 가정
				minus = true;
			}
			continue;
		}
		temp += str[i]; //숫자쌓기
	}
	cout << result << endl;
	return 0;
}