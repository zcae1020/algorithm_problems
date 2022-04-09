//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int N, input[1000][3], dp[1000][3], ans=1000006;
//
//int main() {
//	cin >> N;
//	for (int i = 0; i < N; i++) cin >> input[i][0] >> input[i][1] >> input[i][2];
//	for (int i = 0; i < 3; i++) dp[0][i] = input[0][i];
//	for (int i = 1; i < N; i++) {
//		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + input[i][0];
//		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + input[i][1];
//		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + input[i][2];
//	}
//	for (int i = 0; i < 3; i++) ans = min(ans, dp[N - 1][i]);
//	cout << ans;
//}