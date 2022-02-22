#include <iostream>
#include <algorithm>

using namespace std;

int N, M, H;
bool map[31][11];
int ans = 5;

int move(int idx) {
	int i = idx;
	for (int h = 1;h <= H;h++) {
		if (map[h][i])
			i++;
		else if (map[h][i - 1])
			i--;
	}
	return i;
}

bool isitoi() {
	for (int i = 1;i <= N;i++)
		if (i != move(i))
			return false;
	return true;
}

void dfs(int h, int n, int cnt) {
	if (isitoi())
		ans = min(ans, cnt);
	if (cnt >= 3)
		return;
	for (int j = n + 1;j < N;j++) {
		if (!map[h][j] && !map[h][j + 1] && !map[h][j - 1]) {
			map[h][j] = true;
			dfs(h, j + 1, cnt + 1);
			map[h][j] = false;
		}
	}
	for (int i = h + 1;i <= H;i++) {
		for (int j = 1;j < N;j++) {
			if (!map[i][j] && !map[i][j + 1] && !map[i][j - 1]) {
				map[i][j] = true;
				dfs(i, j + 1, cnt + 1);
				map[i][j] = false;
			}
		}
	}
}

int main() {
	cin >> N >> M >> H;
	for (int i = 0;i < M;i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = true;
	}
	dfs(1, 0, 0);
	ans = ans == 5 ? -1 : ans;
	cout << ans;
}