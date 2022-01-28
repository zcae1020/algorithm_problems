#include <iostream>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int N, L, R, map[50][50], visited[50][50];
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };

bool isDone() {
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			for (int k = 0;k < 4;k++) {
				int nx = j + dx[k], ny = i + dy[k];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N)
					continue;
				int sub = abs(map[i][j] - map[ny][nx]);
				if (L <= sub && sub <= R)
					return false;
			}
		}
	}
	return true;
}

int dfs(int day) {
	if (isDone())
		return day;

	memset(visited, 0, sizeof(visited));
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (visited[i][j])
				continue;
			int num = 0, sum = 0;
			queue<int> qx, qy;
			vector<int> vx, vy;
			qx.push(j), qy.push(i);
			vx.emplace_back(j), vy.emplace_back(i);
			visited[i][j] = 1;
			num++, sum+=map[i][j];

			while (!qx.empty()) {
				int cx = qx.front(), cy = qy.front();
				qx.pop(), qy.pop();

				for (int k = 0;k < 4;k++) {
					int nx = cx + dx[k], ny = cy + dy[k];
					if (nx < 0 || ny < 0 || nx >= N || ny >= N)
						continue;
					int sub = abs(map[cy][cx] - map[ny][nx]);
					if (!visited[ny][nx] && L <= sub && sub <= R) {
						num++, sum += map[ny][nx];
						visited[ny][nx] = 1;
						qx.push(nx), qy.push(ny);
						vx.emplace_back(nx), vy.emplace_back(ny);
					}
				}
			}
			int value = sum / num;
			for (int i = 0;i < vx.size();i++) {
				map[vy[i]][vx[i]] = value;
			}
		}
	}
	return dfs(day + 1);
}

int main() {
	cin >> N >> L >> R;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> map[i][j];
		}
	}

	cout << dfs(0);
}