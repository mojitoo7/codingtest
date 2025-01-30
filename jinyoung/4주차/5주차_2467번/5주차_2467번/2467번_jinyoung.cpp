#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int n;
long double liq[100000];
long double sum = 2000000000;
long double l1, l2;

void min() {
    for (int i = 0; i < n - 1; i++) {
        int left = i + 1, right = n - 1;
        long double target = -liq[i];
        while (left <= right) {
            int mid = (left + right) / 2;
            long double mix = liq[i] + liq[mid];

            if (fabsl(sum) > fabsl(mix)) {
                sum = mix;
                l1 = liq[i];
                l2 = liq[mid];
            }

            if (liq[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%Lf", &liq[i]);
    }

    min();

    printf("%0.Lf %0.Lf\n", l1, l2);
    return 0;
}