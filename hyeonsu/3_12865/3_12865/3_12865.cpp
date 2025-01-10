#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	int w[101];
	int v[101];
	
	for (int i = 1; i <= n; i++)
		cin >> w[i] >> v[i];

	int dp[101][100001];
	for (int i = 1; i <= n; i++){ //1번, 1+2번, 1+2+3번 순서로 확인
		for (int j = 1; j <= k; j++){ // 무게가 j만큼 남았다고 가정
			if (j - w[i] >= 0) { 
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]); // j무게일때 i-1번째 가치와 i번째를 담고 남은 무게(j-w[i])름 담은 가치 비교
			}
			else dp[i][j] = dp[i - 1][j]; // i번째 물건이 안담기면 그냥 전꺼까지 담음
		}
	}

	cout << dp[n][k];

}