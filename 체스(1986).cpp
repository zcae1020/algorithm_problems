#include <iostream>

using namespace std;

int N, M, map[1000][1000];
bool visited[1000][1000];

int qx[8] = { 0,0,1,-1,1,1,-1,-1 }, qy[8] = { 1,-1,0,0,1,-1,1,-1 };
int kx[8] = { 1,1,2,2,-1,-1,-2,-2 }, ky[8] = { -2,2,-1,1,-2,2,-1,1 };

void input() {
	cin >> N >> M;
	int n, x, y;
	for (int i = 1; i <= 3; i++) {
		cin >> n;
		while (n--) {
			cin >> y >> x;
			map[y - 1][x - 1] = i;
		}
	}
}



void draw() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			switch (map[i][j]) {
			case 1:
				visited[i][j] = true;
				for (int k = 0; k < 8; k++) {
					int cx = j, cy = i;
					while (true) {
						cx += qx[k], cy += qy[k];
						if (map[cy][cx] || cx < 0 || cy < 0 || cx >= M || cy >= N)
							break;
						visited[cy][cx] = true;
					}
				}
				break;
			case 2:
				visited[i][j] = true;
				for (int k = 0; k < 8; k++) {
					int cx = j + kx[k], cy = i + ky[k];
					if (map[cy][cx] || cx < 0 || cy < 0 || cx >= M || cy >= N)
						continue;
					visited[cy][cx] = true;
				}
				break;
			case 3:
				visited[i][j] = true;
				break;
			}
		}
	}
}

int getSafety() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] == false)
				ret++;
		}
	}
	return ret;
}

int main() {
	input();
	draw();
	cout << getSafety();
}