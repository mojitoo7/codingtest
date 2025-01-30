#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int  arr[129][129] = { 0 };
int whitecount = 0; int bluecount = 0;


void check(int startrow, int startcol, int num) {  //1���� 0���� Ȯ���ϴ� �޼���


	if (num == 1) { // ���� �� ������ �� ���� �Ѱ��� ���簢���� �Ǹ� 1�϶�
		if (arr[startcol][startrow] == 1) { // �׶��� �ε��� ���� 1�� ��쿡 blucount ����
			bluecount++;
			return;
		}
		else { //0�̸� whitecount ����
			whitecount++;
			return;
		}

	}

	int resultCheck = 0;  // ���� 1���� 0���� Ȯ�� �ϴ� ���� 



	for (int i = startcol; i < startcol + num; i++) {  //�߸��κ��� ���δ� 1 or 0������ Ȯ�� 

		for (int j = startrow; j < startrow + num; j++) {

			resultCheck += arr[i][j];

		}
	}

	if (resultCheck == 0) {  //���� ���δ� 0�̸� �� ���ص� 0�̹Ƿ� whitcount ���� 
		whitecount++;
		return;
	}
	else if (resultCheck == num * num) { //���δ� 1�̸� ���� ��ŭ�� ���̹Ƿ� bluecount  ���� 
		bluecount++;
		return;
	}
	else {
		resultCheck = 0;

		//int nextstartrow = startrow;
		//int nextstartcol = startcol;
		int nextnum = num / 2;

		check(startrow, startcol, nextnum);                       // 1��и� ��ͷ� ȣ��
		check(startrow + nextnum, startcol, nextnum);			  // 2��и� ��ͷ� ȣ��
		check(startrow, startcol + nextnum, nextnum);			  // 3��и� 
		check(startrow + nextnum, startcol + nextnum, nextnum);	  // 4��и�
	}

}

int main()
{
	int N;

	cin >> N;

	for (int i = 1; i <= N; i++) {       //�迭 ��ü�� �Լ� ä�� �ֱ�
		for (int j = 1; j <= N; j++) {
			int num;
			cin >> num;

			if (num == 1) {
				arr[i][j] = 1;
			}
		}
	}

	check(1, 1, N);  // ó�� �˻� ���� 

	cout << whitecount << "\n" << bluecount << endl; // ��� ��� 

}

