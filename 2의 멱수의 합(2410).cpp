#include <iostream>
#define MOD 1000000000

using namespace std;

int N, dp[1000001];

int main() {
	dp[1] = 1;
	cin >> N;

	for (int i = 2;i <= N;i++) {
		if (i % 2 == 0)
			dp[i] = (dp[i - 1] + dp[i / 2]) % MOD;
		else
			dp[i] = dp[i - 1];
	}

	cout << dp[N];
}