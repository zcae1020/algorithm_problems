// #include <stdio.h>
// #include <algorithm>
// using namespace std;

// int arr[100001], m, n;
// int binarySearch(int *arr, int n, int m) {
// 	int l, r, mid;
// 	l = 0;
// 	r = n;
// 	while (l <= r)
// 	{
// 		mid = (l + r) / 2;
// 		if (arr[mid] < m)
// 		{
// 			l = mid + 1;
// 		}
// 		else if (arr[mid] > m)
// 		{
// 			r = mid - 1;
// 		}
// 		else
// 		{
// 			return 1;
// 		}
// 	}
// 	return 0;
// }
// int main()
// {
// 	int n, m, arr[100001];
// 	scanf("%d", &n);
// 	for (int i = 0;i < n;i++)
// 	{
// 		scanf("%d", &arr[i]);
// 	}
// 	sort(arr, arr + n);
// 	scanf("%d", &m);
// 	for (int i = 0;i < m;i++)
// 	{
// 		int x;
// 		scanf("%d", &x);
// 		printf("%d\n", binarySearch(arr, n, x));
// 	}
// }