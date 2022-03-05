#include <iostream>
#include <queue>
#define pii pair<int,int>

using namespace std;

int K, W, H, map[200][200], visited[31][200][200];
int dx[12] = { 0,0,1,-1,1,1,2,2,-1,-1,-2,-2 }, dy[12] = { 1,-1,0,0,2,-2,1,-1,2,-2,1,-1 };

int bfs() {
	queue<pair<pii, pii>> q;

	q.push(make_pair(make_pair(0, 0), make_pair(0, K)));
	visited[K][0][0] = 1;

	while (!q.empty()) {
		pii cur = q.front().first;
		int cnt = q.front().second.first;
		int k = q.front().second.second;
		q.pop();

		if (cur.first == W - 1 && cur.second == H - 1)
			return cnt;

		if (k) {
			for (int i = 0; i < 12; i++) {
				pii next;
				int nk = i > 3 ? k - 1 : k;
				next.first = cur.first + dx[i], next.second = cur.second + dy[i];
				
				if (visited[nk][next.second][next.first] || map[next.second][next.first] || next.first < 0 || next.second < 0 || next.first >= W || next.second >= H)
					continue;

				visited[nk][next.second][next.first] = true;
				q.push(make_pair(next, make_pair(cnt + 1, nk)));
			}
		}
		else {
			for (int i = 0; i < 4; i++) {
				pii next;
				next.first = cur.first + dx[i], next.second = cur.second + dy[i];

				if (visited[k][next.second][next.first] || map[next.second][next.first] || next.first < 0 || next.second < 0 || next.first >= W || next.second >= H)
					continue;

				visited[k][next.second][next.first] = true;
				q.push(make_pair(next, make_pair(cnt + 1, k)));
			}
		}
	}

	return -1;
}

int main() {
	cin >> K >> W >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
		}
	}

	cout << bfs();
}