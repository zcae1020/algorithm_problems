#include <iostream>
#define MOD 1000000000
#define ALL (1<<10)-1

using namespace std;

int N, dp[101][10][1 << 10];
int dx[2] = { -1,1 };

int main() {
	
	cin >> N;
	for (int i = 1;i <= 9;i++)
		dp[1][i][1 << i] = 1;

	for (int i = 2;i <= N;i++) {
		for (int j = 0;j <= 9;j++) {
			for (int k = 1;k <= ALL;k++) {
				if (j == 0)
					dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j + 1][k]) % MOD;
				else if (j == 9)
					dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j - 1][k]) % MOD;
				else {
					dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j + 1][k]) % MOD;
					dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j - 1][k]) % MOD;
				}
			}
		}
	}

	int ans = 0;
	for (int j = 0;j <= 9;j++) {
		ans = (ans + dp[N][j][ALL]) % MOD;
	}
	cout << ans;
}