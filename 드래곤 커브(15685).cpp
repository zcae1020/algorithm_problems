#include <iostream>
#include <vector>

using namespace std;

int N;
bool map[101][101];
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,-1,0,1 };

void draw(int x, int y, int d, int g) {
	vector<int> di;
	int cx = x + dx[d], cy = y + dy[d];
	di.emplace_back(d);
	map[y][x] = 1;
	map[cy][cx] = 1;
	for (int i = 1;i <= g;i++) {
		for (int j = di.size() - 1;j >= 0;j--) {
			int cd = (di[j] + 1) % 4;
			cx += dx[cd], cy += dy[cd];
			map[cy][cx] = 1;
			di.emplace_back(cd);
		}
	}
}

int square() {
	int ret = 0;
	for (int i = 0;i < 100;i++) {
		for (int j = 0;j < 100;j++) {
			if (map[i][j] && map[i][j + 1] && map[i + 1][j] && map[i + 1][j + 1])
				ret++;
		}
	}
	return ret;
}

int main() {
	cin >> N;
	for (int i = 0;i < N;i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		draw(x, y, d, g);
	}
	cout << square();
}