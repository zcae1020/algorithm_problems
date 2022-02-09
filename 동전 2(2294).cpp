//#include <iostream>
//#include <algorithm>
//#include <cstring>
//
//using namespace std;
//
//int n, k, coin[102], dp[10004];
//
//int main() {
//	cin >> n >> k;
//	for (int i = 0;i < n;i++)
//		cin >> coin[i];
//	for (int i = 1;i <= k;i++)
//		dp[i] = 10001;
//	dp[0] = 0;
//	for (int i = 1;i <= k;i++) {
//		for (int j = n - 1;j >= 0;j--) {
//			if (i >= coin[j])
//				dp[i] = min(dp[i], dp[i - coin[j]] + 1);
//		}
//	}
//	if (dp[k] == 10001)
//		cout << -1;
//	else
//		cout << dp[k];
//}