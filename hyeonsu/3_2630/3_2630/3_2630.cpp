#include <iostream>
using namespace std;

int space[129][129];
int blue = 0, white = 0;

void check(int x, int y, int n) {
    int color = space[x][y]; //왼쪽위 기준
    bool cut = false;

    for (int i = x; i < x + n; i++) {  //범위내에서
        for (int j = y; j < y + n; j++) {
            if (color != space[i][j]) { //달라지면 자름
                cut = true;
                break;
            }
        }
    }

    if (cut) {
        check(x, y, n/2); // 4등분
        check(x, y + n/2, n/2);
        check(x + n/2, y, n/2);
        check(x + n/2, y + n/2, n/2); 
    }
    else {
        if (color == 1) blue++; //1이면 파랑
		else white++;
    }
}

int main() {
    int n;
    cin >> n;

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> space[i][j];
        }
    }

    check(0, 0, n);

    cout << white << endl;
    cout << blue << endl;

    return 0;
}
