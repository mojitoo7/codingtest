#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N, K;
int knapSack[101][100001] = { 0 }; //dp�� �̿��Ͽ� ������ �迭 ����(������ �迭 ����)

int main()
{
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {//�賶�� ���� �� �ִ� ������ ������ŭ �ݺ�

		int W, V;

		cin >> W >> V;  //��ġ�� �����Է� ����

		for (int j = 0; j <= K; j++) { //������ �뷮�� 0���� ��¥ ������ �뷮��ŭ 1���÷������鼭 ������ Ž�� 

			if (W > j) { //���� �ӽ� �賶�� ������ �뷮���� ��ģ�ٸ� ���� ����
				knapSack[i][j] = knapSack[i - 1][j];
			}
			else { 
				knapSack[i][j] = max(knapSack[i - 1][j], knapSack[i - 1][j - W] + V);
				//�ΰ��� ���� �� �ϳ��� ���� ���� ��� �ִ� ������ ���� ���� ������ ������ or �� ���� �����ϰ� ���� ������ ���� ������
				// �ΰ��� �߿� �� ���� ��ġ�� ���ϰ� �ִ� ���� ���ؾ� ������ max�� �̿��ؼ� ����
			}

		}
	}

	cout << knapSack[N][K] << endl; // ���

}