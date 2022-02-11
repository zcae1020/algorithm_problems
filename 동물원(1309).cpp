#include <iostream>

using namespace std;

int N;
long long dp[100005][2] = { 0 };

int main() {
	cin >> N;
	for (int i = 0;i < 2;i++)
		dp[1][i] = 1;
	for (int i = 2;i <= N;i++) {
		dp[i][0] = dp[i - 1][0] + 2 * dp[i - 1][1];
		dp[i][0] %= 9901;
		dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] %= 9901;
	}
	cout << (dp[N][0] + 2 * dp[N][1]) % 9901;
}