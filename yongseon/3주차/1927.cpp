#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int minHeap[100001] = { 0 };

int N;
int Nodenum = 0;

void addNode(int index) { //��� �߰�  ��� �߰��ÿ� �� ������ ���� ������ �ȵ�

	int rootIndex = index / 2; //�θ� ��� �ε��� ����

	while (minHeap[index] < minHeap[rootIndex]) { //�ּ� ���� �θ� �׻� �۾ƾ� ��

		swap(minHeap[index], minHeap[rootIndex]); //�θ� �� ũ�� ���� ��ȯ

		index = rootIndex;                      // �ε��� �� �� ����
		rootIndex = index / 2;
	}

}

int getMin() {  //0 �Է½ÿ� ��Ʈ ��� ��� �޼���

	if (Nodenum == 0) {  //���� ����� ������ ���µ� 0�Է½� 0 ���

		return 0;
	}

	int temp = minHeap[1];  //������ ��Ʈ ��� ����
	minHeap[1] = 0;
	swap(minHeap[1], minHeap[Nodenum]);  //���� ������ ���� �ٲٱ�


	Nodenum--; //��Ʈ ��� ���� ������ ��ü ���� �ϳ� ����

	int index = 1;
	int leftchild = 2; int  rightchild = 3;

	while (true) {  //



		if (Nodenum < leftchild) {  //�ڽ� ��尡 �ƿ� ������

			break;
		}
		else if (Nodenum == leftchild) {    // ���� �ڽĳ��� ����� ������ ���� ��� 
			if (minHeap[index] > minHeap[leftchild]) { //�θ� ũ�� ��ȯ
				swap(minHeap[index], minHeap[leftchild]);
				index = leftchild;
			}
			else { // ũ�� ������ ���� ���� ����
				break;
			}

		}


		else if (min(minHeap[rightchild], minHeap[leftchild]) >= minHeap[index]) { //������ �� ������ ���� ���
			break;
		}

		else { // �ٲ�� �Ҷ�

			if (minHeap[leftchild] > minHeap[rightchild]) { // ���� rightchild�� �� ���� ���
				if (minHeap[index] > minHeap[rightchild]) {
					swap(minHeap[index], minHeap[rightchild]);
					index = rightchild;
				}


			}
			else if (minHeap[leftchild] <= minHeap[rightchild]) { //�� ũ�ų� ���� ���
				if (minHeap[index] > minHeap[leftchild]) {
					swap(minHeap[index], minHeap[leftchild]);
					index = leftchild;
				}
			}
			else {
				break;
			}

		}

		leftchild = index * 2; //�ڽĳ�� �ε��� �� ����
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

		if (num == 0) {  // 0�̸� ��Ʈ��� ��� �� �� �� ���� 

			int ans = getMin();
			buffer << ans << "\n";

		}
		else { //���� �� ��쿡 �Է� 

			Nodenum++;
			minHeap[Nodenum] = num;
			addNode(Nodenum);

		}
	}

	cout << buffer.str();
}

