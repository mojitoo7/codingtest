#include <iostream>
#include <algorithm>
using namespace std;

bool desc(int a, int b) { return a > b; } // 내림차순

//그냥 가장 높은 자리숫자에 있는거에 높은숫자를 순서대로 지급하면 댐

int main(void) {
    int n;
    cin >> n;

    char arr[10][10]; //2차원 배열로 입력받음
    int len[10]; 
    int alpha[26] = {0};
   
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; 
        len[i] = string(arr[i]).length(); 
    }

    int cal;
    for (int i = 0; i < n; i++) {
        cal = 1;
        for (int j = len[i] - 1; j >= 0; j--) { //맨 뒷자리 부터 1, 10, 100으로 값을 지급
            alpha[arr[i][j] - 'A'] += cal; 
            cal *= 10;
        }
    }
    sort(alpha, alpha + 26, desc); // 내림차순으로 정렬

    int result = 0;
    for (int i = 0; i < 10; i++) {
        result += alpha[i] * (9 - i); // 높은 자릿수에 있는 알파벳부터 9를 지급하고 결과에 더한다고 생각(실제로 a가 뭔지 구하는게 중요한게 아님)
    }

    cout << result;
}