#include <iostream>
#include <algorithm>

using namespace std;

int T, n, map[2][100005], dp[2][100005];

int main() {
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0;i < 2;i++) {
			for (int j = 0;j < n;j++) {
				cin >> map[i][j];
			}
		}
		dp[0][0] = map[0][0], dp[1][0] = map[1][0];
		for (int i = 1;i < n;i++) {
			dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + map[0][i]);
			dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] + map[1][i]);
		}
		cout << max(dp[0][n - 1], dp[1][n - 1]) << endl;
	}
}