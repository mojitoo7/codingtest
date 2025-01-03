#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int* list = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> list[i];
	}

	int max = 0;
	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				int sum = list[i] + list[j] + list[k];
				if (sum <= m && sum > max) // 제한치보다 작고 최대값 경신
				{
					max = sum;
				}
			}
		}
	}

	cout << max << endl;

	delete[] list;
	return 0;
}