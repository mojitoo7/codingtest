#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> list(n);
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }

    int left = 0;
    int right = n - 1;
    int min_sum = 2147483647;
    int ans1 = 0, ans2 = 0;

    while (left < right) {
        int sum = list[left] + list[right];

        if (abs(sum) < abs(min_sum)) {
            min_sum = sum;
            ans1 = list[left];
            ans2 = list[right];
        }

        if (sum < 0) {
            left++;
        }
        else {
            right--;
        }
    }

    cout << ans1 << " " << ans2 << endl;
    return 0;
}
