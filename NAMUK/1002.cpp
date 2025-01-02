// 1002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
int main()
{
	int count = 0;
	int x1, y1, r1, x2, y2, r2, square_dis, square_r1_r2_plus, square_r1_r2_sub;
	string result;
	cin >> count;
	for (int i = 0; i < count; ++i) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		if (x1 == x2 && y1 == y2) {
			 result += (r1 == r2) ?  ' - 1' : '0';
		}
		else {
			square_dis = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
			square_r1_r2_plus = (r1 + r2) * (r1 + r2);
			square_r1_r2_sub = (r1 - r2) * (r1 - r2);

			if (square_dis == square_r1_r2_plus || square_r1_r2_sub == square_dis) result += '1';
			else if (square_r1_r2_sub < square_dis && square_dis < square_r1_r2_plus ) result += '2';
			else if ( square_dis > square_r1_r2_plus) result +='0';
		}
		result += '\n';
	}
	cout << result;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
