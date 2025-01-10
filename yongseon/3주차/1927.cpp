#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int minHeap[100001] = { 0 };

int N;
int Nodenum = 0;

void addNode(int index) { //노드 추가  노드 추가시에 힙 구조를 벗어 나서는 안됨

	int rootIndex = index / 2; //부모 노드 인덱스 설정

	while (minHeap[index] < minHeap[rootIndex]) { //최소 힙은 부모가 항상 작아야 함

		swap(minHeap[index], minHeap[rootIndex]); //부모가 더 크면 서로 교환

		index = rootIndex;                      // 인덱스 값 재 설정
		rootIndex = index / 2;
	}

}

int getMin() {  //0 입력시에 루트 노드 출력 메서드

	if (Nodenum == 0) {  //만약 노드의 개수가 없는데 0입력시 0 출력

		return 0;
	}

	int temp = minHeap[1];  //리턴할 루트 노드 저장
	minHeap[1] = 0;
	swap(minHeap[1], minHeap[Nodenum]);  //가장 마지막 노드와 바꾸기


	Nodenum--; //루트 노드 제거 했으니 전체 개수 하나 줄임

	int index = 1;
	int leftchild = 2; int  rightchild = 3;

	while (true) {  //



		if (Nodenum < leftchild) {  //자식 노드가 아예 없을때

			break;
		}
		else if (Nodenum == leftchild) {    // 왼쪽 자식노드와 노드의 개수가 같을 경우 
			if (minHeap[index] > minHeap[leftchild]) { //부모가 크면 교환
				swap(minHeap[index], minHeap[leftchild]);
				index = leftchild;
			}
			else { // 크지 않으면 지금 구조 유지
				break;
			}

		}


		else if (min(minHeap[rightchild], minHeap[leftchild]) >= minHeap[index]) { //지금이 힙 구조와 같은 경우
			break;
		}

		else { // 바꿔야 할때

			if (minHeap[leftchild] > minHeap[rightchild]) { // 만약 rightchild가 더 작을 경우
				if (minHeap[index] > minHeap[rightchild]) {
					swap(minHeap[index], minHeap[rightchild]);
					index = rightchild;
				}


			}
			else if (minHeap[leftchild] <= minHeap[rightchild]) { //더 크거나 같을 경우
				if (minHeap[index] > minHeap[leftchild]) {
					swap(minHeap[index], minHeap[leftchild]);
					index = leftchild;
				}
			}
			else {
				break;
			}

		}

		leftchild = index * 2; //자식노드 인덱스 재 설정
		rightchild = index * 2 + 1;


	}
	return temp;
}

int main()
{
	ostringstream buffer;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;

		if (num == 0) {  // 0이면 루트노드 출력 후 힙 재 구조 

			int ans = getMin();
			buffer << ans << "\n";

		}
		else { //존재 할 경우에 입력 

			Nodenum++;
			minHeap[Nodenum] = num;
			addNode(Nodenum);

		}
	}

	cout << buffer.str();
}

