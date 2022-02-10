#include <iostream>

using namespace std;

int N, M, map[502][502], visited[502][502];
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };

int dfs(int x, int y) {
	if (x == M - 1 && y == N - 1)
		return 1;
	int ret = visited[y][x];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = 0;i < 4;i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= M || ny >= N)
			continue;
		if (map[y][x] > map[ny][nx]) {
			visited[ny][nx] = dfs(nx, ny);
			ret += visited[ny][nx];
		}
	}
	return ret;
}

int main() {
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> map[i][j];
			visited[i][j] = -1;
		}
	}

	cout << dfs(0, 0);
}