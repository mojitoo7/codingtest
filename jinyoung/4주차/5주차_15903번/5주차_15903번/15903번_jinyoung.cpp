#include <stdio.h>  
#include <stdlib.h>

int compare(void* first, void* second)
{
	long long int* a = (long long int*)first;
	long long int* b = (long long int*)second;
	if (*a > *b)
		return 1;
	else if (*a < *b)
		return -1;
	else
		return 0;
}


int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	long long int arr[1001];
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &arr[i]);
	}

	for (int i = 0; i < m; i++)
	{
		
		qsort(arr, n, sizeof(long long int), compare);
		long long int sum = arr[0] + arr[1];
		arr[0] = arr[1] = sum;
	}

	long long int ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += arr[i];
	}
	printf("%lld", ans);

	return 0;
}