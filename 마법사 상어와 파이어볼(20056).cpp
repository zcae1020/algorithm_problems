#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

typedef struct fireBall {
	int m, s, d;
} FB;

int N, M, K;
vector<FB> map[51][51], tmp[51][51];

int dx[8] = { -1,-1,0,1,1,1,0,-1 }, dy[8] = { 0,1,1,1,0,-1,-1,-1 };

void Input() {
	cin >> N >> M >> K;

	for (int i = 0; i < M; i++) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		map[r][c].push_back({ m, s, d });
	}
}

void mapCopy(vector<FB> m1[][51], vector<FB> m2[][51]) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			m1[i][j].clear();
			for (auto a : m2[i][j]) m1[i][j].push_back(a);
		}
	}
}

void moveFireBall() {
	for (int i = 1; i <= N; i++)for (int j = 1; j <= N; j++)tmp[i][j].clear();

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {

			for (auto a : map[i][j]) {

				int s = a.s % N;
				int nx = i + s * dx[a.d], ny = j + s * dy[a.d];

				if (nx < 1) nx = N + nx;
				else if (nx > N) nx = nx - N;
				if (ny < 1)ny = N + ny;
				else if (ny > N) ny = ny - N;

				tmp[nx][ny].push_back(a);

			}
		}
	}

	mapCopy(map, tmp);
}

void divideFireBall() {
	for (int i = 1; i <= N; i++)for (int j = 1; j <= N; j++)tmp[i][j].clear();

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {

			if (map[i][j].size() > 1) {

				int msum = 0, ssum = 0, nm, ns;
				bool isAllOdd = true, isAllEven = true;

				for (auto a : map[i][j]) {

					if (a.d % 2) isAllEven = false;
					else isAllOdd = false;

					msum += a.m;
					ssum += a.s;

				}

				nm = msum / 5;
				ns = ssum / map[i][j].size();

				if (nm == 0) continue;
				else {
					if (isAllOdd||isAllEven) {
						tmp[i][j].push_back({ nm,ns,0 });
						tmp[i][j].push_back({ nm,ns,2 });
						tmp[i][j].push_back({ nm,ns,4 });
						tmp[i][j].push_back({ nm,ns,6 });
					}
					else {
						tmp[i][j].push_back({ nm,ns,1 });
						tmp[i][j].push_back({ nm,ns,3 });
						tmp[i][j].push_back({ nm,ns,5 });
						tmp[i][j].push_back({ nm,ns,7 });
					}
				}
			}
			else if(map[i][j].size() == 1) tmp[i][j].push_back(map[i][j][0]);
		}
	}

	mapCopy(map, tmp);
}

void print() {
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (auto a : map[i][j]) ans += a.m;
		}
	}
	cout << ans;
}

void Solution() {
	while (K--) {
		moveFireBall();
		divideFireBall();
	}
	print();
}

int main() {
	Input();
	Solution();
}