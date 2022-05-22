//#include <iostream>
//#include <algorithm>
//#define MAXN 1500001
//
//using namespace std;
//
//int N, T[MAXN], P[MAXN], dp[MAXN];
//
//int dfs(int idx) {
//	if (dp[idx] != -1)
//		return dp[idx];
//	if (idx == N + 1)
//		return 0;
//
//	if (T[idx] + idx <= N + 1)
//		return dp[idx] = max(P[idx] + dfs(T[idx] + idx), dfs(idx + 1));
//	else
//		return dp[idx] = dfs(idx + 1);
//}
//
//int main() {
//	cin >> N;
//	for (int i = 1;i <= N;i++) {
//		cin >> T[i] >> P[i];
//		dp[i] = -1;
//	}
//
//	cout << dfs(1);
//}