#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct unit {
	int x, y, d;
} u[10];

int n, k, map[12][12], nextT, nx, ny;
vector<int> umap[12][12], nextu;

int dx[4] = { 0,0,-1,1 }, dy[4] = { 1,-1,0,0 };

void Input() {
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	for (int i = 0; i < k; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		u[i] = { x - 1,y - 1,d - 1 };
		umap[x - 1][y - 1].push_back(i);
	}
}

void getNext(int idx) {
	struct unit cur = u[idx];
	nx = cur.x + dx[cur.d], ny = cur.y + dy[cur.d];

	if (nx < 0 || ny < 0 || nx >= n || ny >= n) nextT = 2;
	else nextT = map[nx][ny];

	int order;
	for (int i = 0; i < umap[cur.x][cur.y].size(); i++) {
		if (umap[cur.x][cur.y][i] == idx) {
			order = i;
			break;
		}
	}

	for (int i = order; i < umap[cur.x][cur.y].size(); i++) {
		nextu.push_back(umap[cur.x][cur.y][i]);
		umap[cur.x][cur.y].erase(umap[cur.x][cur.y].begin() + i--);
	}
}

void Solution() {
	int turn = 0;
	bool gameover = false;
	while (!gameover && turn <= 1000) {

		turn++;

		for (int i = 0; i < k; i++) {
			getNext(i);

			if (nextT == 1)
				reverse(nextu.begin(), nextu.end());
			else if (nextT == 2) {
				if (u[i].d < 2) u[i].d = u[i].d == 1 ? 0 : 1;
				else u[i].d = u[i].d == 3 ? 2 : 3;

				nx = u[i].x + dx[u[i].d], ny = u[i].y + dy[u[i].d];

				if (nx < 0 || ny < 0 || nx >= n || ny >= n || map[nx][ny] == 2)
					nx = u[i].x, ny = u[i].y;
				else if (map[nx][ny] == 1)
					reverse(nextu.begin(), nextu.end());
			}

			if (umap[nx][ny].size() + nextu.size() >= 4) {
				gameover = true;
				break;
			}

			umap[nx][ny].insert(umap[nx][ny].end(), nextu.begin(), nextu.end());
			for (auto a : nextu) u[a] = { nx,ny,u[a].d };

			nextu.clear();
		}
	}
	if (turn <= 1000) cout << turn;
	else cout << -1;
}

int main() {
	Input();
	Solution();
}