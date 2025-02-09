#include <stdio.h> //재귀함수의return위치가 중요했던 문제, return을 남발해서 계속 프로그램이 끊겼음
#include <string.h>
#include <iostream>
//#define DEBUG /

int NS_tooth[4][8];

void rotate_tooth(int clockwise, int number) {
	int temp;
	if (clockwise == 1) {
		//std::cout << "number" << number << clockwise << std::endl; //debug
		temp = NS_tooth[number - 1][7];
		for (int i = 7; i > 0; --i) {
			NS_tooth[number - 1][i] = NS_tooth[number - 1][i - 1];
		}
		NS_tooth[number - 1][0] = temp;
	}
	else {
		//std::cout << "number" << number << clockwise << std::endl; //debug
		temp = NS_tooth[number - 1][0];
		for (int i = 0; i < 7; ++i) {
			NS_tooth[number - 1][i] = NS_tooth[number - 1][i + 1];
		}
		NS_tooth[number - 1][7] = temp;
	}
}

void turn(int clockwise, int number, int before_number) {
	int rigth, left;
	rigth = NS_tooth[number - 1][2];
	left = NS_tooth[number - 1][6];
	rotate_tooth(clockwise, number);

	if ((number - 1 != before_number )  && number != 1) {
		if (left != NS_tooth[number - 2][2]) { //맞닿은 곳이 서로 다르면
			turn(-1 * clockwise, number - 1, number);
		}
	}
	
	if ((number + 1 != before_number) && number != 4) {
		if (rigth != NS_tooth[number][6]) { //맞닿은 곳이 서로 다르면
			turn(-1 * clockwise, number + 1, number);
		}
	}
	return;
}

int main() {
	
	int k,number,clockwise;
	char y;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 8; ++j) {
			std::cin >> y;
			NS_tooth[i][j] = y - '0';
		}
	}

	std::cin >> k;
	while (k--) {
		std::cin >> number >> clockwise;
		turn(clockwise, number, 0);


#ifdef DEBUG
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 8; ++j) {
				std::cout << NS_tooth[i][j];
			}
			printf("\n");
		}
		printf("\n");
#endif
	}
	int x = 1, sum = 0;
		
	if (NS_tooth[0][0] == 1) {
		sum = 1;
	}

	for (int i = 1; i < 4; ++i) {
		//printf("a");
		x = x * 2;
		if (NS_tooth[i][0] == 1) {
			//std::cout << "출력";
			sum += x;
		}
	}
	std::cout << sum;
	return 0;
}