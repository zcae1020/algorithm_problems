#include <iostream>
#include <vector>
#define pii pair<int,int>

using namespace std;

int N, M, x, y, K;
int map[22][22], insts[1000];
vector<int> dice(6);

/*
  3
4 0 5
  1
  2
*/

int up[4] = { 0,1,2,3 }, le[4] = { 0,4,2,5 };

void init() {
	for (int i = 0;i < 6;i++)
		dice[i] = 0;
	cin >> N >> M >> x >> y >> K;
	for (int i = 0;i <= N + 1;i++) {
		map[i][0] = -1;
		map[i][M + 1] = -1;
	}
	for (int i = 0;i <= M + 1;i++) {
		map[0][i] = -1;
		map[N + 1][i] = -1;
	}
	for (int i = 1;i <= N;i++)
		for (int j = 1;j <= M;j++)
			cin >> map[i][j];
	for (int i = 0;i < K;i++)
		cin >> insts[i];
}

pii roll(int inst, pii cur) {
	vector<int> tmp;
	vector<int> rot;
	switch (inst) {
	case 1:
		for (int i = 0;i < 4;i++)
			tmp.emplace_back(dice[le[i]]);
		rot.emplace_back(tmp[3]);
		for (int i = 0;i < 3;i++)
			rot.emplace_back(tmp[i]);
		cur.first++;
		break;
	case 2:
		for (int i = 0;i < 4;i++)
			tmp.emplace_back(dice[le[i]]);
		for (int i = 1;i < 4;i++)
			rot.emplace_back(tmp[i]);
		rot.emplace_back(tmp[0]);
		cur.first--;
		break;
	case 3:
		for (int i = 0;i < 4;i++)
			tmp.emplace_back(dice[up[i]]);
		rot.emplace_back(tmp[3]);
		for (int i = 0;i < 3;i++)
			rot.emplace_back(tmp[i]);
		cur.second--;
		break;
	case 4:
		for (int i = 0;i < 4;i++)
			tmp.emplace_back(dice[up[i]]);
		for (int i = 1;i < 4;i++)
			rot.emplace_back(tmp[i]);
		rot.emplace_back(tmp[0]);
		cur.second++;
		break;
	}
	if (map[cur.second][cur.first] == -1) {
		cur.first = -1, cur.second = -1;
		return cur;
	}
	if (inst > 2)
		for (int i = 0;i < 4;i++)
			dice[up[i]] = rot[i];
	else
		for (int i = 0;i < 4;i++)
			dice[le[i]] = rot[i];
	return cur;
}

int main() {
	init();
	pii cur = { x + 1, y + 1 };
	for (int i = 0;i < K;i++) {
		pii next = roll(insts[i], cur);
		if (next.first == -1 && next.second == -1)
			continue;
		cur = next;
		int curNum = map[cur.second][cur.first];
		if (curNum) {
			dice[0] = curNum;
			map[cur.second][cur.first] = 0;
		}
		else
			map[cur.second][cur.first] = dice[0];
		cout << dice[2] << endl;
	}
}