#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, L, map[100][100], visited[100];

bool canMove(vector<int> v) {
	for (int i = 0;i < N - 1;i++) {
		if (v[i] != v[i + 1]) {
			int sub = v[i] - v[i + 1];
			if (sub == 1) {
				for (int j = 0;j < L;j++) {
					if (i + j + 1 >= N || visited[i + j + 1])
						return false;
					visited[i + j + 1] = 1;
				}
			}
			else if (sub == -1) {
				for (int j = 0;j < L;j++) {
					if (i - j < 0 || visited[i - j])
						return false;
					visited[i - j] = 1;
				}
			}
			else
				return false;
		}
	}
	return true;
}

int main() {
	cin >> N >> L;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> map[i][j];
		}
	}

	int ans = 0;
	vector<int> v;
	for (int i = 0;i < N;i++) {
		v.clear();
		memset(visited, 0, sizeof(visited));
		for (int j = 0;j < N;j++)
			v.emplace_back(map[i][j]);
		if (canMove(v))
			ans++;
		v.clear();
		memset(visited, 0, sizeof(visited));
		for (int j = 0;j < N;j++)
			v.emplace_back(map[j][i]);
		if (canMove(v))
			ans++;
	}

	cout << ans;
}