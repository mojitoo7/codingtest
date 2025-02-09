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
		room[y][x] = 2;  //û���ϱ� -> ++�� ���ֱ�
		count++;
		d_go = search_d(x, y, d);

		//printf("%d %d \n", x, y);
		if (d_go == -1) {//��ĭ�� ���� ���, �� 0 �� �ϳ��� ���� ��� d-�� 1�̸� �� �ƴϸ� 1������ ���ư���
			
			d = (d + 2) % 4; //�������� �ε��� ����
			int index_x = x + x_dir[d];
			int index_y = y + y_dir[d];
			//std::cout << index_x<< index_y <<  room[index_x][index_y];
			if (room[index_y][index_x] == 1) {
				break;
			}
			else {
				x = index_x;
				y = index_y;
				d = (d + 2) % 4; //���� �ٽ� �ٲ��ֱ�
			}
		}
		else {
			// 0�� �ϳ��� �ִ� ��� , �ݽð� �������� ��ȸ�ϰ� ó�� �ɷ����� ��ǥ �÷��� �ϰ� clean()
			x = x + x_dir[d_go];
			y = y + y_dir[d_go];
			d = d_go;
		}

	}
	printf("%d", count);
}


//1.���簰�� û�ҵǾ����� û��
//2.�����¿� �� û�ҵ�����

//3.�����¿� û�ҾȵȰ��� ������
//�ݽð�� 90ȸ��, ��ĭ�϶� ���� 


//scanf %c���ϴ� ���鵵 �о �Է��� ����� �ȵ��� ������ ������ �����ϴ� %d�����ڸ� �����
//