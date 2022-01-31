#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define pii pair<int,int>

using namespace std;

int N, M, D, ori[15][15], map[15][15], visited[15][15];
vector<pii> k;
int dx[3] = { -1,0,1 }, dy[3] = { 0,-1,0 };

void mapCopy() {
	for (int i = 0;i < N;i++)
		for (int j = 0;j < M;j++)
			map[i][j] = ori[i][j];
}

bool gameover() {
	for (int i = 0;i < N;i++)
		for (int j = 0;j < M;j++)
			if (map[i][j])
				return false;
	return true;
}

void bfs(int x, int y) {
	for (int i = 0;i < N;i++)
		for (int j = 0;j < M;j++)
			visited[i][j] = 0;

	if (map[y][x]) {
		k.emplace_back(x, y);
		return;
	}

	queue<int> qx, qy;
	qx.push(x), qy.push(y);
	visited[y][x] = 1;
	while (!qx.empty()) {
		int cx = qx.front(), cy = qy.front();
		qx.pop(), qy.pop();
		for (int i = 0;i < 3;i++) {
			int nx = cx + dx[i], ny = cy + dy[i];
			int d = abs(x - nx) + abs(y - ny) + 1;
			if (visited[ny][nx] || nx < 0 || ny < 0 || nx >= M || ny >= N)
				continue;
			if (d > D)
				return;
			if (map[ny][nx]) {
				k.emplace_back(nx, ny);
				return;
			}
			qx.push(nx), qy.push(ny);
			visited[ny][nx] = 1;
		}
	}
}

void moveE() {
	vector<pii> e;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			if (map[i][j]) {
				if (i + 1 < N)
					e.emplace_back(j, i + 1);
				map[i][j] = 0;
			}
	for (int i = 0;i < e.size();i++)
		map[e[i].second][e[i].first] = 1;
}

int main() {
	cin >> N >> M >> D;
	for (int i = 0;i < N;i++)
		for (int j = 0;j < M;j++)
			cin >> ori[i][j];
	
	int ans = 0;
	for (int a = 0;a < M;a++) {
		for (int b = a + 1;b < M;b++) {
			for (int c = b + 1;c < M;c++) {
				mapCopy();
				int score = 0;
				while (!gameover()) {
					k.clear();
					bfs(a, N - 1);
					bfs(b, N - 1);
					bfs(c, N - 1);
					for (int i = 0;i < k.size();i++) {
						if (map[k[i].second][k[i].first]) {
							score++;
							map[k[i].second][k[i].first] = 0;
						}
					}
					moveE();
				}
				ans = max(ans, score);
			}
		}
	}
	cout << ans;
}