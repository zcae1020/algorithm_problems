#include <iostream>
#define REST 1000000007

using namespace std;

int N, L, R;
long long dp[101][101][101] = { 0 };

int main() {
	dp[1][1][1] = dp[2][1][2] = dp[2][2][1] = 1;
	cin >> N >> L >> R;
	for (int i = 3;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			for (int k = 1;k <= N;k++) {
				dp[i][j][k] = (dp[i - 1][j][k - 1] + dp[i - 1][j - 1][k] + dp[i - 1][j][k] * (i - 2)) % REST;
			}
		}
	}
	cout << dp[N][L][R];
}