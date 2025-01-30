#include <iostream>
#include <utility>
using namespace std;

// ����ð� ������ �����ϰ� ����ð� �������ο��� ���۽ð��� �ٷ� ������ �Ǵµ� 
// ���������ߴٰ� �ð��ʰ����� �����ķ� �ϴϱ� �������� �־��� ��찡 n^2�̶� �̰͵� �ð��ʰ����� �������� ����
void heapify(pair<int, int> arr[], int n, int root) {
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < n && (arr[left].second > arr[largest].second ||
        (arr[left].second == arr[largest].second && arr[left].first > arr[largest].first))) {
        largest = left;
    }

    if (right < n && (arr[right].second > arr[largest].second ||
        (arr[right].second == arr[largest].second && arr[right].first > arr[largest].first))) {
        largest = right;
    }

    if (largest != root) {
        swap(arr[root], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(pair<int, int> arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    cin >> n;

    pair<int, int> time[100000];

    for (int i = 0; i < n; i++) {
        cin >> time[i].first >> time[i].second;
    }

    heapSort(time, n);

    int cnt = 0;
    int finish = 0;

    for (int i = 0; i < n; i++) {
        if (time[i].first >= finish) {
            finish = time[i].second;
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}
