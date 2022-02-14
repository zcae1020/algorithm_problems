//#include <iostream>
//
//using namespace std;
//
//int N, M, fix[41] = { 0 }, dp[41];
//
//int main() {
//	cin >> N >> M;
//	for (int i = 0;i < M;i++) {
//		int x;
//		cin >> x;
//		fix[x] = 1;
//	}
//
//	dp[1] = 1;
//	if (fix[1] || fix[2])
//		dp[2] = 1;
//	else
//		dp[2] = 2;
//	for (int i = 3;i <= N;i++) {
//		if (fix[i - 1] || fix[i])
//			dp[i] = dp[i - 1];
//		else
//			dp[i] = dp[i - 1] + dp[i - 2];
//	}
//	cout << dp[N];
//}