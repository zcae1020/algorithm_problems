#include <iostream>
#include <queue>
#include <vector>
#define pii pair<int, int>
#define ll long long

using namespace std;

int N, map[102][102];
ll dp[102][102];

int dx[2] = { 0,1}, dy[2] = { 1,0 };

int main() {
	cin >> N;
	for (int i = 0;i < N;i++)
		for (int j = 0;j < N;j++) {
			cin >> map[i][j];
			dp[i][j] = 0;
		}

	dp[0][0] = 1;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (dp[i][j]) {
				int move = map[i][j];
				if (move) {
					for (int k = 0;k < 2;k++) {
						int nx = j + dx[k] * move, ny = i + dy[k] * move;
						if (nx < N&&ny < N)
							dp[i + dy[k] * move][j + dx[k] * move] += dp[i][j];
					}
				}
			}
		}
	}

	cout << dp[N - 1][N - 1];
}