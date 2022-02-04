#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct p {
	int x;
	int y;
	int z;
};

int n, m, h, box[101][101][101];
int dx[6] = { 0,0,0,0,1,-1 }, dy[6] = { 0,0,1,-1,0,0 }, dz[6] = { 1,-1,0,0,0,0 };
queue<pair<int, p>> q;

bool ripeAll() {
	for (int i = 0;i < h;i++) {
		for (int j = 0;j < m;j++) {
			for (int k = 0;k < n;k++) {
				if (!box[i][j][k])
					return false;
			}
		}
	}
	return true;
}



int main() {
	cin >> n >> m >> h;
	int ripedA = 1;
	for (int i = 0;i < h;i++) {
		for (int j = 0;j < m;j++) {
			for (int k = 0;k < n;k++) {
				cin >> box[i][j][k];
				if (box[i][j][k] == 1) {
					struct p tmp;
					tmp.x = k, tmp.y = j, tmp.z = i;
					q.push({ 0,tmp });
				}
				else if (box[i][j][k] == 0) {
					ripedA = 0;
				}
			}
		}
	}
	if (ripedA) {
		cout << 0;
		exit(0);
	}
	if (q.size() == 0) {
		cout << -1;
		exit(0);
	}

	int ans = 0;
	while (!q.empty()) {
		pair<int, p> cur = q.front();
		q.pop();
		for (int i = 0;i < 6;i++) {
			pair<int, p> next = cur;
			next.first++;
			next.second.x += dx[i], next.second.y += dy[i], next.second.z += dz[i];
			if (box[next.second.z][next.second.y][next.second.x] ||
				next.second.x < 0 || next.second.y < 0 || next.second.z < 0 ||
				next.second.x >= n || next.second.y >= m || next.second.z >= h)
				continue;
			ans = max(ans, next.first);
			box[next.second.z][next.second.y][next.second.x] = 1;
			q.push(next);
		}
	}
	
	if (ripeAll()) {
		cout << ans;
	}
	else {
		cout << -1;
	}
}