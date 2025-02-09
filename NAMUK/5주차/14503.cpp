#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<iostream>
#define N 11
#define M 50


int room[N][M];
int count;

int x_dir[4] = { 0,1,0,-1 };
int y_dir[4] = { -1,0,1,0 };

int search_d(int x,int y,int d) {
	//printf("%d %d ;\n", x, y); //debug
	int index_x, index_y;
	for (int i = 0; i < 4; ++i) {
		d = (d + 1) % 4;
		index_x = x + x_dir[d];
		index_y = y + y_dir[d];
		//printf("%d %d %d %d\n ", index_x, index_y,i,d);
		//printf("%d %d \n", index_x, index_y); //debug
		if (room[index_y][index_x] == 0) {
			
			return d;
		}
	}
	return -1;
}

int main() {
	int n, m;
	int x, y, d;

	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &x, &y,&d);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &room[i][j]);
		}
	}

	int d_go;
	while (1) {
		//printf("a");
		room[y][x] = 2;  //청소하기 -> ++도 해주기
		count++;
		d_go = search_d(x, y, d);

		//printf("%d %d \n", x, y);
		if (d_go == -1) {//빈칸이 없는 경우, 다 0 이 하나라도 없는 경우 d-가 1이면 끝 아니면 1번으로 돌아가기
			
			d = (d + 2) % 4; //후진방향 인덱스 설정
			int index_x = x + x_dir[d];
			int index_y = y + y_dir[d];
			//std::cout << index_x<< index_y <<  room[index_x][index_y];
			if (room[index_y][index_x] == 1) {
				break;
			}
			else {
				x = index_x;
				y = index_y;
				d = (d + 2) % 4; //방향 다시 바꿔주기
			}
		}
		else {
			// 0이 하나라도 있는 경우 , 반시계 방향으로 순회하고 처음 걸렸을때 좌표 플러스 하고 clean()
			x = x + x_dir[d_go];
			y = y + y_dir[d_go];
			d = d_go;
		}

	}
	printf("%d", count);
}


//1.현재같이 청소되었을떄 청소
//2.상하좌우 다 청소됐을때

//3.상하좌우 청소안된것이 있을떄
//반시계로 90회전, 빈칸일때 전진 


//scanf %c로하니 공백도 읽어서 입력이 제대로 안됐음 공백을 만나면 종료하는 %d서식자를 써야함
//