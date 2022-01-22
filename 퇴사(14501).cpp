#include <iostream>
#include <algorithm>

using namespace std;

int N, dp[20], T[20], P[20];

int main() {
	cin >> N;
	for (int i = 1;i <= N;i++) {
		cin >> T[i] >> P[i];
		dp[i] = 0;
	}
	dp[0] = 0;

	int mx, n;
	for (int i = 1;i <= N;i++) {
		mx = 0;
		for (int j = 1;j <= 5;j++) {
			int curi = i - j + 1;
			if (curi <= 0)
				break;
			n = dp[curi - 1];
			if (T[curi] <= j)
				n += P[curi];
			mx = max(mx, n);
		}
		dp[i] = mx;
	}
	cout << dp[N];
}