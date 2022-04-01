#include <iostream>
#include <algorithm>
#define pii pair<int,int>

using namespace std;

typedef struct fish {
	int num, dist;
	bool die = false;
} FISH;

FISH map[4][4];
pii F[17];
int ans;
int dx[9] = { 0,-1,-1,0,1,1,1,0,-1 }, dy[9] = { 0,0,-1,-1,-1,0,1,1,1 };

void Input() {
	int a, b;
	for (int i = 0; i < 16; i++) {
		cin >> a >> b;
		map[i / 4][i % 4] = { a,b };
		F[a] = { i / 4,i % 4 };
	}
}

void stateCopy(FISH m1[][4], FISH m2[][4], pii f1[], pii f2[]) {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			m1[i][j] = m2[i][j];

	for (int i = 0; i < 17; i++) f1[i] = f2[i];
}

void oneFishMove(int sx, int sy, int idx, int cnt) {
	if (cnt == 8) return;

	int cx = F[idx].first, cy = F[idx].second, cd = map[cx][cy].dist;
	int nx = cx + dx[cd], ny = cy + dy[cd];

	if ((nx == sx && ny == sy) || nx < 0 || ny < 0 || nx >= 4 || ny >= 4) {
		map[cx][cy].dist++;
		if (map[cx][cy].dist == 9) map[cx][cy].dist = 1;
		oneFishMove(sx, sy, idx, cnt + 1);
	}
	else {
		int nIdx = map[nx][ny].num;
		pii Ftmp = F[idx];
		F[idx] = F[nIdx];
		F[nIdx] = Ftmp;

		FISH Mtmp = map[cx][cy];
		map[cx][cy] = map[nx][ny];
		map[nx][ny] = Mtmp;
	}
}

void fishMove(int sx, int sy) {
	for (int i = 1; i <= 16; i++) {
		if (map[F[i].first][F[i].second].die == false)
			oneFishMove(sx, sy, i, 0);
	}
}

int DFS(int x, int y, int d) {
	FISH omap[4][4];
	pii oF[17];
	stateCopy(omap, map, oF, F);

	int ret = 0, nx = x, ny = y;

	while (true) {

		nx += dx[d], ny += dy[d];

		if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) break;

		if (map[nx][ny].die == false) {
			map[nx][ny].die = true;
			fishMove(nx, ny);

			ret = max(ret, omap[nx][ny].num + DFS(nx, ny, omap[nx][ny].dist));

			stateCopy(map, omap, F, oF);
		}
	}

	return ret;
}

void Solution() {
	map[0][0].die = true;
	ans += map[0][0].num;

	fishMove(0, 0);
	ans += DFS(0, 0, map[0][0].dist);

	cout << ans;
}

int main() {
	ios::sync_with_stdio(0);
	Input();
	Solution();
}