#include <iostream>
using namespace std;


int main() {
    int t;
    cin >> t;

    while (t--) {
        int m, n, x, y;
        int ans = -1;

        cin >> m >> n >> x >> y;

        while (x <= m * n) { // �������� m*n�̰�
            if (x % n == y % n) { // �ᱹ x�� m�� ������ y�� n�� �������̴ϱ� y�� n�� ��������� �����ϸ� x�� �ű⿡ �����ָ��
                ans = x;
                break;
            }
            else x += m; //���� m����Ŭ
        }

        cout << ans << "\n";
    }
}