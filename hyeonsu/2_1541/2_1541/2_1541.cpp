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
		if (str[i] == '+' || str[i] == '-' || str[i] == '\0') { // ��ȣ�� �������϶�
			if (minus) { //���������϶��� ������ ���ϱ�
				result -= stoi(temp); //����ȭ
			} 
			else {
				result += stoi(temp); //ó���� ������ ����
			}

			temp = "";

			if (str[i] == '-') { //�ѹ� ���Ⱑ ������ �ڿ��� ��ȣ���ڰ� �ļ� �� ���� ����ٰ� ����
				minus = true;
			}
			continue;
		}
		temp += str[i]; //���ڽױ�
	}
	cout << result << endl;
	return 0;
}