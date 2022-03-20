#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define pii pair<int,int>

using namespace std;

int R, C, N, H, turn = 1;
char map[100][101];

vector<pii> cluster;

bool comp(pii a, pii b) {
	if (a.second == b.second) return a.first > b.first;
	return a.second < b.second;
}

pii destory() {
	int idx = R - H;
	if (turn == 0) {
		pii cur = { idx, 0 };
		while (cur.second < C) {
			if (map[cur.first][cur.second] == 'x') {
				map[cur.first][cur.second] = '.';
				return cur;
			}
			cur.second++;
		}
	}
	else {
		pii cur = { idx, C - 1 };
		while (cur.second >= 0) {
			if (map[cur.first][cur.second] == 'x') {
				map[cur.first][cur.second] = '.';
				return cur;
			}
			cur.second--;
		}
	}
	return { -1,-1 };
}

void down() {
	int flag;
	while (true) {
		flag = 0;

		for (pii p : cluster) map[p.first][p.second] = '.';

		for (pii p : cluster) 
			if (p.first == R - 1 || map[p.first + 1][p.second] == 'x') 
				flag = 1;
		if (flag) break;

		for (int i = 0; i < cluster.size(); i++) {
			cluster[i].first++;
			map[cluster[i].first][cluster[i].second] = 'x';
		}
	}
	for (pii p : cluster) map[p.first][p.second] = 'x';
}

void getClusterAndDown(pii des) {
	queue<pii> q;
	bool visit[100][100] = { false };
	int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };

	for (int i = 0; i < 4; i++) {

		pii n = { des.first + dx[i], des.second + dy[i] };

		if (n.first >= 0 && n.second >= 0 && n.first < R && n.second < C && visit[n.first][n.second] == 0 && map[n.first][n.second] == 'x') {

			cluster.push_back(n);
			q.push(n);
			visit[n.first][n.second] = true;
			bool isGround = false;

			while (!q.empty()) {
				pii cur = q.front();
				q.pop();

				for (int j = 0; j < 4; j++) {
					int nx = cur.first + dx[j], ny = cur.second + dy[j];

					if (nx >= 0 && ny >= 0 && nx < R && ny < C && visit[nx][ny] == false && map[nx][ny] == 'x') {
						cluster.push_back({ nx,ny });
						q.push({ nx,ny });
						visit[nx][ny] = true;
					}
				}
			}

			down();
			cluster.clear();
		}
	}
}

void print() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
}

void turnChange() {
	if (turn) turn = 0;
	else turn = 1;
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) cin >> map[i];
	cin >> N;

	while (N--) {
		turnChange();
		cin >> H;

		pii des = destory();

		if (des == make_pair(-1, -1)) continue;

		getClusterAndDown(des);
	}

	print();
}