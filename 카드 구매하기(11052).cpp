#include <iostream>

using namespace std;

int N, P[1003], dp[1003];

int main() {
	cin >> N;
	for (int i = 1;i <= N;i++)
		cin >> P[i];

	dp[0] = 0;
	int mx;
	for (int w = 1;w <= N;w++) {
		mx = 0;
		for (int i = 1;i <= w;i++) {
			int inc = dp[w - i] + P[i];
			if (mx < inc)
				mx = inc;
		}
		dp[w] = mx;
	}
	cout << dp[N];
}