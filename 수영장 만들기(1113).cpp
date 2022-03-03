#include <iostream>
#include <queue>

using namespace std;

bool visited[50][50];
int N, M, ans;
char map[50][51];
queue<int> qx, qy;

int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = false;
		}
	}
	while (!qx.empty())qx.pop();
	while (!qy.empty())qy.pop();
}

int bfs(int x, int y, int h) {
	int flag = 0, cnt = 1;

	int cx, cy, nx, ny;
	qx.push(x), qy.push(y);
	visited[y][x] = true;

	while (!qx.empty()) {

		cx = qx.front(), cy = qy.front();
		qx.pop(), qy.pop();

		for (int i = 0; i < 4; i++) {

			nx = cx + dx[i], ny = cy + dy[i];
			if (visited[ny][nx] || nx < 0 || ny < 0 || nx >= M || ny >= N || map[ny][nx] > ('0' + h))
				continue;
			if (nx <= 0 || ny <= 0 || nx >= M - 1 || ny >= N - 1) {
				flag = 1;
				continue;
			}

			cnt++;
			visited[ny][nx] = true;
			qx.push(nx), qy.push(ny);
		}
	}
	return flag ? 0 : cnt;
}

int main() {
	ans = 0;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> map[i];

	for (int h = 1; h <= 9; h++) {
		init();
		for (int y = 1; y < N - 1; y++) {
			for (int x = 1; x < M - 1; x++) {
				if (!visited[y][x] && map[y][x] <= ('0' + h)) {
					int cnt = bfs(x, y, h);
					ans += cnt;
				}
			}
		}
	}
	cout << ans;
}