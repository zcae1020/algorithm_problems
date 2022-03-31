#include <iostream>

using namespace std;

char map[200][201];
int cnt[200][201];
int R, C, N, T = 1;

void Input() {
	cin >> R >> C >> N;

	for (int i = 0; i < R; i++) {
		cin >> map[i];
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 'O') cnt[i][j] = 1;
		}
	}
}

void bomb() {
	int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
	bool flag[200][201] = { false };

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (cnt[i][j] == 3) flag[i][j]=true;
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (flag[i][j]) {
				map[i][j] = '.';
				cnt[i][j] = 0;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k], ny = j + dy[k];
					if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
					map[nx][ny] = '.';
					cnt[nx][ny] = 0;
				}
			}
		}
	}
}

void putBomb() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == '.') {
				map[i][j] = 'O';
				cnt[i][j] = 0;
			}
		}
	}
}

void time() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 'O') cnt[i][j]++;
		}
	}
}

void print() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
}

void Solution() {
	while (T++ < N) {
		if (T % 2) bomb();
		else putBomb();
		time();
	}
	print();
}

int main() {
	ios::sync_with_stdio(0);
	Input();
	Solution();
}