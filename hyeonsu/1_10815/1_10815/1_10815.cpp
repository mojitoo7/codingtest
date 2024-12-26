/*
=====================================================================================
��������: ����̰� n�� ī�� �������ְ� m�� ī�忡 ����, ���� ���ڰ� ������ 1 �ƴϸ� 0
�߿��Ѱ� �κ� ����Ž��, ����
=====================================================================================
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool search(const vector<int>& arr, int key) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return true;
        }
        else if (arr[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n;

    vector<int> sang(n);
    for (int i = 0; i < n; i++) {
        cin >> sang[i];
    }

    /*
    for (int i = 1; i < n; i++) {
        int key = sang[i];
        int j = i - 1;
        while (j >= 0 && sang[j] > key) {
            sang[j + 1] = sang[j];
            j--;
        }
        sang[j + 1] = key;
    }
    */

    sort(sang.begin(), sang.end());

    cin >> m;
    vector<int> list(m);
    for (int i = 0; i < m; i++) {
        cin >> list[i];
    }

    for (int i = 0; i < m; i++) {
        if (search(sang, list[i])) {
            cout << 1 << " ";
        }
        else {
            cout << 0 << " ";
        }
    }
    cout << endl;

    return 0;
}
