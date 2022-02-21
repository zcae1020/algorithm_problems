#include <iostream>
#include <algorithm>
#define pii pair<int,int>

using namespace std;

int n, m;
char map[11][11];
pii R, B;
pii OUT = { -1,-1 };

int dx[4] = { 0,0,1,-1 }, dy[4] = { -1,1,0,0 };

pii nextP(pii P, int type) {
	pii cp = P;
	cp.first = cp.first + dx[type], cp.second = cp.second + dy[type];
	while (map[cp.second][cp.first] != '#') {
		if (map[cp.second][cp.first] == 'O')
			return { -1,-1 };
		cp.first = cp.first + dx[type], cp.second = cp.second + dy[type];
	}
	cp.first = cp.first - dx[type], cp.second = cp.second - dy[type];
	return cp;
}

int incline(pii cR, pii cB, int type) {
	pii nR, nB;
	nR = nextP(cR, type);
	nB = nextP(cB, type);
	if (nR == OUT) {
		if (nB == OUT)
			return -1;
		return 1;
	}
	if (nB == OUT)
		return -1;

	if (nR == nB) {
		switch (type) {
		case 0:
			if (cR.second > cB.second)
				nR.second++;
			else
				nB.second++;
			break;
		case 1:
			if (cR.second > cB.second)
				nB.second--;
			else
				nR.second--;
			break;
		case 2:
			if (cR.first > cB.first)
				nB.first--;
			else
				nR.first--;
			break;
		case 3:
			if (cR.first > cB.first)
				nR.first++;
			else
				nB.first++;
			break;
		}
	}

	map[cR.second][cR.first] = map[cB.second][cB.first] = '.';
	map[nR.second][nR.first] = 'R';
	map[nB.second][nB.first] = 'B';
	R = nR, B = nB;
	return 0;
}

void reset(pii curR, pii curB) {
	map[R.second][R.first] = map[B.second][B.first] = '.';
	map[curR.second][curR.first] = 'R';
	map[curB.second][curB.first] = 'B';
}

int dfs(int cnt) {
	if (cnt > 10)
		return 100;

	int ret = 100;
	pii curR = R, curB = B;
	for (int i = 0;i < 4;i++) {
		int in = incline(curR, curB, i);
		if (in == -1)
			continue;
		else if (in)
			return cnt;

		ret = min(ret, dfs(cnt + 1));

		reset(curR, curB);
	}
	return ret;
}

int main() {
	cin >> n >> m;
	for (int i = 0;i < n;i++)
		cin >> map[i];

	for (int i = 1;i < n;i++)
		for (int j = 1;j < m;j++)
			if (map[i][j] == 'R')
				R.first = j, R.second = i;
			else if (map[i][j] == 'B')
				B.first = j, B.second = i;

	int d = dfs(1);
	if (d == 100)
		cout << -1;
	else
		cout << d;
}