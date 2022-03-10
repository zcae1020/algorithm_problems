#include <iostream>
#include <cstring>
#define pii pair<int,int>

using namespace std;

int R, C, T, map[50][50], tmpm[50][50];
pii airCondition[2];

int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };

void spread(pii p) {
	int sub = 0;
	for (int i = 0; i < 4; i++) {
		int nx = p.first + dx[i], ny = p.second + dy[i];
		if (nx < 0 || ny < 0 || nx >= C || ny >= R || map[ny][nx] == -1) continue;
		tmpm[ny][nx] += (map[p.second][p.first] / 5);
		sub += (map[p.second][p.first] / 5);
	}
	tmpm[p.second][p.first] += (map[p.second][p.first] - sub);
}

void onAirCondition() {
	pii cur = airCondition[0];
	cur.second--;
	while (cur.second > 0) {
		map[cur.second][cur.first] = map[cur.second - 1][cur.first];
		cur.second--;
	}
	while (cur.first < C - 1) {
		map[cur.second][cur.first] = map[cur.second][cur.first + 1];
		cur.first++;
	}
	while (cur.second < airCondition[0].second) {
		map[cur.second][cur.first] = map[cur.second + 1][cur.first];
		cur.second++;
	}
	while (cur.first > 1) {
		map[cur.second][cur.first] = map[cur.second][cur.first - 1];
		cur.first--;
	}
	map[cur.second][cur.first] = 0;

	cur = airCondition[1];
	cur.second++;
	while (cur.second < R - 1) {
		map[cur.second][cur.first] = map[cur.second + 1][cur.first];
		cur.second++;
	}
	while (cur.first < C - 1) {
		map[cur.second][cur.first] = map[cur.second][cur.first + 1];
		cur.first++;
	}
	while (cur.second > airCondition[1].second) {
		map[cur.second][cur.first] = map[cur.second - 1][cur.first];
		cur.second--;
	}
	while (cur.first > 1) {
		map[cur.second][cur.first] = map[cur.second][cur.first - 1];
		cur.first--;
	}
	map[cur.second][cur.first] = 0;
}

void print() {
	int ans = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] && map[i][j] != -1)
				ans += map[i][j];
		}
	}
	cout << ans;
}

void Input() {
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				if (airCondition[0].first == 0 && airCondition[0].second == 0)
					airCondition[0] = make_pair(j, i);
				else
					airCondition[1] = make_pair(j, i);
			}
		}
	}
}

void Solution() {
	while (T--) {
		memset(tmpm, 0, sizeof(tmpm));
		tmpm[airCondition[0].second][airCondition[0].first] = -1;
		tmpm[airCondition[1].second][airCondition[1].first] = -1;

		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				if (map[i][j] && map[i][j] != -1) spread(make_pair(j, i));

		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				map[i][j] = tmpm[i][j];

		onAirCondition();
	}
	print();
}

int main() {
	Input();
	Solution();
}