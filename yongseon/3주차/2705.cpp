#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int T;
vector<int> ans;  //dp�� ������ ������ ���� (ó���� �迭�� ���������� �޸� �ʰ��� ���Ͽ� ���ͷ� �����)
vector<int> print;

int main()
{
	cin >> T;
	ans.push_back(0); ans.push_back(1); ans.push_back(2); ans.push_back(2); ans.push_back(4);
	//�ʱ� 4������ ���� ���� 

	for (int i = 5; i < 1002; i++) {// �־��� ���� ��ü�� ���Ͽ� �ݺ�

		if (i % 2 == 0) { //¦���� Ȧ�� �϶��� ���� �Ͽ� ���� 
			int num = 0; //i�� ���� ���� ����
			int result = 1; //���� ���Ϳ� ������ ���� 

			while (true) {
				if ((i - num) == 0) break; // ���� ������ num�� �� ���� 0�� �Ǹ� ���̳ʽ��� �ǹǷ� ���� 

				int re = (i - num) / 2; //num�� ����ϰ� �翷�� ���� ���� dp�� �����Ͽ� ���� ������

				result = result + ans[re]; // ������ ���� ��������� ����
				num = num + 2;
			}
			ans.push_back(result); // ���� ���Ϳ� ����
		}
		else {  // Ȧ���϶��� ¦���϶��� �����ϰ� ���� ������ ����ϹǷ� ����
			int num = 1;
			int result = 1;

			while (true) {
				if ((i - num) == 0) break;

				int re = (i - num) / 2;

				result = result + ans[re];
				num = num + 2;
			}
			ans.push_back(result);
		}
	}

	for (int i = 0; i < T; i++) {  //�Է¹��� ���� ���ؼ� ���Ϳ� ����

		int num;
		cin >> num;

		print.push_back(ans[num]);

	}

	for (int nums : print) { //���� ���
		cout << nums << "\n";
	}



}
