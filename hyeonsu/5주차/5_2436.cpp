#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
    int t;
    while (b) {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int a, b;
    cin >> a >> b;

    b = b / a;
    for (int i = (int)sqrt(b); i >= 1; i--) {
        if (b % i) continue;
        if (gcd(b / i, i) == 1) {
            cout << a * i << " " << (b / i) * a;
            break;
        }
    }
}