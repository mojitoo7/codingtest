#include <iostream>
using namespace std;

int main() {
    int dp[1001] = { 0 };
    dp[1] = 1;

    for (int n = 2; n <= 1000; n++) {
        dp[n] = 1; 
        for (int i = 0; i <= n / 2; i++) {
            dp[n] += dp[i]; //����� �ƹ����� �ְ� ���ʿ� ���ڷ� �� ä���
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}
