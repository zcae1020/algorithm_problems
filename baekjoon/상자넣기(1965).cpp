//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int N, bs[1003], dp[1003] = { 0 };
//
//int main() {
//	cin >> N;
//	for (int i = 0;i < N;i++)
//		cin >> bs[i];
//
//	int mx, ans = 1;
//	for (int i = 0;i < N;i++) {
//		mx = 0;
//		for (int j = bs[i] - 1;j > 0;j--) {
//			if (dp[j]) {
//				mx = max(mx, dp[j]);
//			}
//		}
//		if (mx) {
//			dp[bs[i]] = mx + 1;
//			ans = max(ans, dp[bs[i]]);
//		}
//		else
//			dp[bs[i]] = 1;
//	}
//	cout << ans;
//}