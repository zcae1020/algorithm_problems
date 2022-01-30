#include <iostream>

using namespace std;

int N, map[16][16], ans = 0;
int dx[3] = { 1,1,0 }, dy[3] = { 0,1,1 };


void dfs(int x, int y, int d) {
	if (x == N - 1 && y == N - 1) {
		ans++;
		return;
	}
	
	int i1, i2;
	switch (d) {
	case 0: //오른쪽
		i1 = 0, i2 = 2;
		break;
	case 1: //대각선
		i1 = 0, i2 = 3;
		break;
	case 2: //아래쪽
		i1 = 1, i2 = 3;
		break;
	}

	for (int i = i1;i < i2;i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N)
			continue;
		if (i == 1) {
			if (!(map[ny][nx] || map[ny - 1][nx] || map[ny][nx - 1]))
				dfs(nx, ny, i);
		}
		else {
			if (!map[ny][nx])
				dfs(nx, ny, i);
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0;i < N;i++)
		for (int j = 0;j < N;j++)
			cin >> map[i][j];

	dfs(1, 0, 0);
	cout << ans;
}