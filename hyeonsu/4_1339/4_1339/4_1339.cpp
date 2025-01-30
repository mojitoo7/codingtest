#include <iostream>
#include <algorithm>
using namespace std;

bool desc(int a, int b) { return a > b; } // ��������

//�׳� ���� ���� �ڸ����ڿ� �ִ°ſ� �������ڸ� ������� �����ϸ� ��

int main(void) {
    int n;
    cin >> n;

    char arr[10][10]; //2���� �迭�� �Է¹���
    int len[10]; 
    int alpha[26] = {0};
   
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; 
        len[i] = string(arr[i]).length(); 
    }

    int cal;
    for (int i = 0; i < n; i++) {
        cal = 1;
        for (int j = len[i] - 1; j >= 0; j--) { //�� ���ڸ� ���� 1, 10, 100���� ���� ����
            alpha[arr[i][j] - 'A'] += cal; 
            cal *= 10;
        }
    }
    sort(alpha, alpha + 26, desc); // ������������ ����

    int result = 0;
    for (int i = 0; i < 10; i++) {
        result += alpha[i] * (9 - i); // ���� �ڸ����� �ִ� ���ĺ����� 9�� �����ϰ� ����� ���Ѵٰ� ����(������ a�� ���� ���ϴ°� �߿��Ѱ� �ƴ�)
    }

    cout << result;
}