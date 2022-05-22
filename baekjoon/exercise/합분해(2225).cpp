//#include <iostream>
//#define rest 1000000000
//
//using namespace std;
//
//int main() {
//	int n, k;
//	long long dp[202][202] = { 0 }; //dp[k][n]
//	cin >> n >> k;
//	for (int i = 0;i <= k;i++) {
//		dp[i][0] = 1;
//	}
//	for (int i = 0;i <= n;i++) {
//		dp[1][i] = 1;
//	}
//	for (int i = 2;i <= k;i++) {
//		for (int j = 1;j <= n;j++) {
//			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//			dp[i][j] %= rest;
//		}
//	}
//	cout << dp[k][n];
//}