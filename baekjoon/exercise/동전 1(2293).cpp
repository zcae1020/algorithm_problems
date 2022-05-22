//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//
//int n, k, v[102], dp[10004] = { 0 };
//int main() {
//	cin >> n >> k;
//	for (int i = 0;i < n;i++)
//		cin >> v[i];
//
//	sort(v, v + n);
//
//	dp[0] = 1;
//	for (int i = 0;i < n;i++) {
//		for (int j = v[i];j <= k;j++) {
//			dp[j] = dp[j] + dp[j - v[i]];
//		}
//	}
//	cout << dp[k];
//}