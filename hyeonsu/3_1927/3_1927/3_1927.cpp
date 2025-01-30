#include <iostream>
#include <queue>
using namespace std;

//�� ������ �����ѵ� �켱����ť�� ���� �����Ϸ��� ����ü����ؼ� �����ɸ��� �����̰� ���� �ҷ��� 
// ���� �����ͻ���ؼ� �ϸ� �ɵ���
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> minHeap; 
    
    int x;
    for (int i = 0; i < n; i++) {

        cin >> x;

        if (x > 0) {
            minHeap.push(x);
        }
        else { 
            if (minHeap.empty()) {
                cout << 0 << "\n"; 
            }
            else {
                cout << minHeap.top() << "\n"; 
                minHeap.pop(); 
            }
        }
    }

    return 0;
}
