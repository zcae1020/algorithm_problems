#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define pii pair<int,int>

using namespace std;

struct bg {
	int r, c, cnt, rb;
};

int N, M, map[20][20], ans;
struct bg BG;

int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };

void Input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
}

void rainbowVisitClear(int visit[][20]) {
	for (int m = 0; m < N; m++) {
		for (int n = 0; n < N; n++) {
			if (map[m][n] == 0) visit[m][n] = 0;
		}
	}
}

bool isBigger(struct bg t, struct bg b) {
	if (t.cnt > b.cnt) return true;
	else if (t.cnt == b.cnt) {
		if (t.rb > b.rb) return true;
		else if (t.rb == b.rb) {
			if (t.r > b.r) return true;
			else if (t.r == b.r) {
				if (t.c > b.c) return true;
			}
		}
	}
	return false;
}

void getBG() {
	
	BG = { -1,-1,-1,-1 };
	int visit[20][20];
	queue<int> qx, qy;

	memset(visit, 0, sizeof(visit));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			if (visit[i][j] || map[i][j] < 1) continue;

			rainbowVisitClear(visit);

			struct bg tmp = { 0,0,0,0 };
			tmp.r = i, tmp.c = j, tmp.cnt = 0;
			qx.push(i), qy.push(j);
			visit[i][j] = 1;

			while (!qx.empty()) {
				int cx = qx.front(), cy = qy.front();
				qx.pop(), qy.pop();
				tmp.cnt++;
				if (map[cx][cy] == 0) tmp.rb++;

				for (int k = 0; k < 4; k++) {
					int nx = cx + dx[k], ny = cy + dy[k];
					if (nx < 0 || ny < 0 || nx >= N || ny >= N || visit[nx][ny]) continue;

					if (map[nx][ny] == 0 || map[nx][ny] == map[i][j]) {
						qx.push(nx), qy.push(ny);
						visit[nx][ny] = 1;
						if (map[nx][ny] == map[i][j]) {
							if (tmp.r > nx) tmp.r = nx, tmp.c = ny;
							else if (tmp.r == nx && tmp.c > ny) tmp.r = nx, tmp.c = ny;
						}
					}
				}
			}

			if (tmp.cnt > 1) {
				if (isBigger(tmp, BG)) BG = tmp;
			}
		}
	}
}

void removeBG() {
	int visit[20][20], BGcolor = map[BG.r][BG.c];
	queue<int> qx, qy;

	ans += BG.cnt * BG.cnt;
	memset(visit, 0, sizeof(visit));
	qx.push(BG.r), qy.push(BG.c);

	while (!qx.empty()) {
		int cx = qx.front(), cy = qy.front();
		qx.pop(), qy.pop();

		map[cx][cy] = -2;

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N || visit[nx][ny]) continue;

			if (map[nx][ny] == 0 || map[nx][ny] == BGcolor) {
				qx.push(nx), qy.push(ny);
				visit[nx][ny] = 1;
			}
		}
	}
}

void gravity() {
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] >= 0) {
				int nx = i;
				while (true) {
					if (nx + 1 >= N || map[nx + 1][j] >= -1) break;
					nx++;
				}
				int tmp = map[i][j];
				map[i][j] = -2;
				map[nx][j] = tmp;
			}
		}
	}
}

void turn() {
	int tmp[20][20];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			tmp[i][j] = map[j][N - 1 - i];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = tmp[i][j];
		}
	}
}

void Solution() {
	while (true) {
		getBG();
		if (BG.r == -1) break;

		removeBG();
		gravity();
		turn();
		gravity();
	}
	cout << ans;
}

int main() {
	Input();
	Solution();
}