#include <iostream>
using namespace std;

int space[129][129];
int blue = 0, white = 0;

void check(int x, int y, int n) {
    int color = space[x][y]; //������ ����
    bool cut = false;

    for (int i = x; i < x + n; i++) {  //����������
        for (int j = y; j < y + n; j++) {
            if (color != space[i][j]) { //�޶����� �ڸ�
                cut = true;
                break;
            }
        }
    }

    if (cut) {
        check(x, y, n/2); // 4���
        check(x, y + n/2, n/2);
        check(x + n/2, y, n/2);
        check(x + n/2, y + n/2, n/2); 
    }
    else {
        if (color == 1) blue++; //1�̸� �Ķ�
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
