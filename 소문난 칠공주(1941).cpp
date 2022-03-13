#include <iostream>
#include <vector>
#include <queue>
#define pii pair<int,int>

using namespace std;

int ans, visited[25];
char map[5][6];

int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };

void Input() {
	for (int i = 0; i < 5; i++)	cin >> map[i];
}

bool moreFour() {
	int s = 0;
	for (int i = 0; i < 25; i++) {
		if (visited[i]) {
			int cx = i % 5 , cy = i / 5;
			if (map[cy][cx] == 'S') s++;
		}
	}
	return s >= 4 ? true : false;
}

bool isAdj() {
	int v[5][5] = { 0 }, qv[5][5] = { 0 };
	queue<pii> q;
	for (int i = 0; i < 25; i++) {
		if (visited[i]) {
			int cx = i % 5, cy = i / 5;
			v[cy][cx] = 1;
			if (q.empty()) {
				qv[cy][cx] = 1;
				q.push(make_pair(cx, cy));
			}
		}
	}

	int cnt = 1;
	while (!q.empty()) {
		pii cur = q.front();
		q.pop();

		if (cnt == 7)
			return true;

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i], ny = cur.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
			if (v[ny][nx] && qv[ny][nx] == 0) {
				qv[ny][nx] = 1;
				q.push(make_pair(nx, ny));
				cnt++;
			}
		}
	}
	return false;
}

void DFS(int idx, int cnt) {
	if (cnt == 7) {
		if (moreFour() && isAdj())
			ans++;
		return;
	}
	
	for (int i = idx; i < 25; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			DFS(i, cnt + 1);
			visited[i] = 0;
		}
	}
}

void Solution() {
	DFS(0, 0);
	cout << ans;
}

int main() {
	Input();
	Solution();
}