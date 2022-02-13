#include <iostream>
#include <algorithm>
#define INF 2000000000

using namespace std;

int n, map[16][16], dp[16][1 << 16], VIS_ALL;

int dfs(int last, int visited) {
	if (visited == VIS_ALL)
		return map[last][0] ? map[last][0] : INF;

	if (dp[last][visited])
		return dp[last][visited];

	int mn = INF;
	for (int i = 1;i < n;i++) {
		if (visited & 1 << i || map[last][i] == 0)
			continue;
		mn = min(mn, dfs(i, visited | 1 << i) + map[last][i]);
	}
	dp[last][visited] = mn;
	return mn;
}

int main() {
	cin >> n;
	VIS_ALL = (1 << n) - 1;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			cin >> map[i][j];

	cout << dfs(0, 1);
}