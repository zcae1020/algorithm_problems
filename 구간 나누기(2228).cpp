//#include <iostream>
//#include <algorithm>
//#define MIN -3300000
//
//using namespace std;
//
//int N, M, arr[101], dp[51][101]; //dp[m][n]
//
//int dfs(int n, int m) {
//	if (m == 0)
//		return 0;
//	if (n <= 0)
//		return MIN;
//	if (dp[m][n] != -1)
//		return dp[m][n];
//
//	dp[m][n] = dfs(n - 1, m);
//
//	int sum = 0;
//	for (int i = n;i > 0;i--) {
//		sum += arr[i];
//
//		dp[m][n] = max(dp[m][n], dfs(i - 2, m - 1) + sum);
//	}
//	return dp[m][n];
//}
//
//int main() {
//	cin >> N >> M;
//	for (int i = 1;i <= N;i++)
//		cin >> arr[i];
//	
//	for (int i = 0;i <= M;i++) {
//		for (int j = 0;j <= N;j++) {
//			dp[i][j] = -1;
//		}
//	}
//
//	cout << dfs(N, M);
//}