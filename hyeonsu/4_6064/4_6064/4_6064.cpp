#include <iostream>
using namespace std;


int main() {
    int t;
    cin >> t;

    while (t--) {
        int m, n, x, y;
        int ans = -1;

        cin >> m >> n >> x >> y;

        while (x <= m * n) { // 마지막은 m*n이고
            if (x % n == y % n) { // 결국 x는 m의 나머지 y는 n의 나머지이니까 y가 n의 나머지라고 고정하면 x가 거기에 맞춰주면댐
                ans = x;
                break;
            }
            else x += m; //다음 m사이클
        }

        cout << ans << "\n";
    }
}