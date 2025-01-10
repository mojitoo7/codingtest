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
	for (int i = 1; i <= n; i++){ //1��, 1+2��, 1+2+3�� ������ Ȯ��
		for (int j = 1; j <= k; j++){ // ���԰� j��ŭ ���Ҵٰ� ����
			if (j - w[i] >= 0) { 
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]); // j�����϶� i-1��° ��ġ�� i��°�� ��� ���� ����(j-w[i])�� ���� ��ġ ��
			}
			else dp[i][j] = dp[i - 1][j]; // i��° ������ �ȴ��� �׳� �������� ����
		}
	}

	cout << dp[n][k];

}