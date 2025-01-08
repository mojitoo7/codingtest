#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int  arr[129][129] = { 0 };
int whitecount = 0; int bluecount = 0;


void check(int startrow, int startcol, int num) {  //1인지 0인지 확인하는 메서드


	if (num == 1) { // 만약 더 나눠질 수 없는 한개의 정사각형이 되면 1일때
		if (arr[startcol][startrow] == 1) { // 그때의 인덱스 값이 1인 경우에 blucount 증가
			bluecount++;
			return;
		}
		else { //0이면 whitecount 증가
			whitecount++;
			return;
		}

	}

	int resultCheck = 0;  // 전부 1인지 0인지 확인 하는 변수 



	for (int i = startcol; i < startcol + num; i++) {  //잘린부분이 전부다 1 or 0인지를 확인 

		for (int j = startrow; j < startrow + num; j++) {

			resultCheck += arr[i][j];

		}
	}

	if (resultCheck == 0) {  //만약 전부다 0이면 다 더해도 0이므로 whitcount 증가 
		whitecount++;
		return;
	}
	else if (resultCheck == num * num) { //전부다 1이면 넓이 만큼의 수이므로 bluecount  증가 
		bluecount++;
		return;
	}
	else {
		resultCheck = 0;

		//int nextstartrow = startrow;
		//int nextstartcol = startcol;
		int nextnum = num / 2;

		check(startrow, startcol, nextnum);                       // 1사분면 재귀로 호출
		check(startrow + nextnum, startcol, nextnum);			  // 2사분면 재귀로 호출
		check(startrow, startcol + nextnum, nextnum);			  // 3사분면 
		check(startrow + nextnum, startcol + nextnum, nextnum);	  // 4사분면
	}

}

int main()
{
	int N;

	cin >> N;

	for (int i = 1; i <= N; i++) {       //배열 전체에 함수 채워 넣기
		for (int j = 1; j <= N; j++) {
			int num;
			cin >> num;

			if (num == 1) {
				arr[i][j] = 1;
			}
		}
	}

	check(1, 1, N);  // 처음 검사 시작 

	cout << whitecount << "\n" << bluecount << endl; // 결과 출력 

}

