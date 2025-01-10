#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N, K;
int knapSack[101][100001] = { 0 }; //dp를 이용하여 저장할 배열 생성(이차원 배열 생성)

int main()
{
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {//배낭에 넣을 수 있는 물건의 개수만큼 반복

		int W, V;

		cin >> W >> V;  //가치와 무게입력 받음

		for (int j = 0; j <= K; j++) { //가방의 용량을 0부터 진짜 가방의 용량만큼 1씩늘려가서면서 최적해 탐색 

			if (W > j) { //만약 임시 배낭의 가방의 용량보다 넘친다면 넣지 않음
				knapSack[i][j] = knapSack[i - 1][j];
			}
			else { 
				knapSack[i][j] = max(knapSack[i - 1][j], knapSack[i - 1][j - W] + V);
				//두가지 선택 중 하나를 택함 전에 들어 있는 물건을 빼고 현재 물건을 넣을지 or 현 상태 유지하고 현재 물건을 넣지 않을지
				// 두가지 중에 더 많은 가치를 지니고 있는 쪽을 택해야 함으로 max를 이용해서 택함
			}

		}
	}

	cout << knapSack[N][K] << endl; // 출력

}