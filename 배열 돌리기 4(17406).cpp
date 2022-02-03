#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct p {
	int r, c, s;
};

vector<p> v;
int N, M, K, map[50][50], visited[6] = { 0 };

void rotate(int r, int c, int s, int m[][50]) {
	int tmp[50][50] = { 0 };
	for (int i = 0;i < s;i++) {
		int sy = r - s + i, sx = c - s + i;
		for (int j = 0;j < 4;j++) {
			for (int k = 0;k < (s - i) * 2;k++) {
				switch (j) {
				case 0:
					sx++;
					tmp[sy][sx] = m[sy][sx - 1];
					break;
				case 1:
					sy++;
					tmp[sy][sx] = m[sy - 1][sx];
					break;
				case 2:
					sx--;
					tmp[sy][sx] = m[sy][sx + 1];
					break;
				case 3:
					sy--;
					tmp[sy][sx] = m[sy + 1][sx];
					break;
				}
			}
		}
	}
	tmp[r][c] = m[r][c];
	int sy = r - s, sx = c - s;
	for (int i = 0;i < 2 * s + 1;i++) {
		for (int j = 0;j < 2 * s + 1;j++) {
			m[sy + i][sx + j] = tmp[sy + i][sx + j];
		}
	}
}

int findMin(int m[][50]) {
	int t[50][50];
	for (int j = 0;j < N;j++) {
		for (int k = 0;k < M;k++) {
			t[j][k] = m[j][k];
		}
	}
	int mn = 5001, sum;
	for (int i = 0;i < N;i++) {
		sum = 0;
		for (int j = 0;j < M;j++) {
			sum += m[i][j];
		}
		mn = min(mn, sum);
	}
	return mn;
}

int dfs(int cycle, int m[][50]) {
	if (cycle == K) {
		return findMin(m);
	}
	int t[50][50];
	int mn = 5001;
	for (int i = 0;i < K;i++) {
		for (int j = 0;j < N;j++) {
			for (int k = 0;k < M;k++) {
				t[j][k] = m[j][k];
			}
		}
		if (visited[i])
			continue;
		visited[i] = 1;
		rotate(v[i].r - 1, v[i].c - 1, v[i].s, t);
		mn = min(mn,dfs(cycle + 1, t));
		visited[i] = 0;
	}
	return mn;
}

int main() {
	cin >> N >> M >> K;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> map[i][j];
		}
	}

	int r, c, s;
	for (int i = 0;i < K;i++) {
		cin >> r >> c >> s;
		struct p p;
		p.r = r, p.c = c, p.s = s;
		v.emplace_back(p);
	}

	cout << dfs(0, map);
}