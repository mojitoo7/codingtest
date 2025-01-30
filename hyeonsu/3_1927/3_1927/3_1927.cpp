#include <iostream>
#include <queue>
using namespace std;

//이 문제는 간단한데 우선순위큐를 직접 구현하려면 구조체사용해서 오래걸릴듯 진영이가 어케 할려나 
// 대충 포인터사용해서 하면 될듯함
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
