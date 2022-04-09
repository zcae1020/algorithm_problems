#include <iostream>
#define R 1000000000

using namespace std;

int n, ans, dp[101][10];

int main() {
	cin >> n;
	for (int i = 1; i < 10; i++) dp[1][i] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < 9; j++) dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % R;
		dp[i][0] = dp[i - 1][1];
		dp[i][9] = dp[i - 1][8];
	}
	for (int i = 0; i < 10; i++) ans = (ans + dp[n][i]) % R;
	cout << ans;
}