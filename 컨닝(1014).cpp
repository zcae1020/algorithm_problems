//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//int C, N, M;
//int dp[10][10];
//char map[10][11];
//bool visited[10][10];
//
//int dx[4] = { 1,1,-1,-1 }, dy[4] = { 0,-1,0,-1 };
//
//void changeVisit(int x, int y, vector<pair<int, int>> *point, int type) {
//	if (type == 0) {
//		for (auto p : *point) {
//			visited[p.second][p.first] = false;
//		}
//		point->clear();
//	}
//	else {
//		visited[y][x] = true;
//		point->push_back(make_pair(x, y));
//
//		for (int i = 0; i < 4; i++) {
//			int nx = x + dx[i], ny = y + dy[i];
//			if (visited[ny][nx] || nx < 0 || ny < 0 || nx >= M || ny >= N)
//				continue;
//			visited[ny][nx] = true;
//			point->push_back(make_pair(nx, ny));
//		}
//	}
//}
//
//int dfs(int cx, int cy) {
//	if (dp[cy][cx] != -1)
//		return dp[cy][cx];
//	int ret = 0;
//	vector<pair<int, int>> p;
//	for (int i = cx; i < M; i++) {
//		if (visited[cy][i] || map[cy][i] == 'x')
//			continue;
//
//		changeVisit(i, cy, &p, 1);
//		ret = max(ret, dfs(i, cy));
//		changeVisit(i, cy, &p, 0);
//	}
//	for (int i = cy - 1; i >= 0; i--) {
//		for (int j = 0; j < M; j++) {
//			if (visited[i][j] || map[i][j] == 'x')
//				continue;
//
//			changeVisit(j, i, &p, 1);
//			ret = max(ret, dfs(j, i));
//			changeVisit(j, i, &p, 0);
//		}
//	}
//	return dp[cy][cx] = ret + 1;
//}
//
//void init() {
//	cin >> N >> M;
//	for (int i = 0; i < N; i++)
//		cin >> map[i];
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			visited[i][j] = false;
//			dp[i][j] = -1;
//		}
//	}
//}
//
//int main() {
//	cin >> C;
//
//	while (C--) {
//		init();
//		dfs(0, N - 1);
//		cout << dp[N - 1][0] - 1 << endl;
//	}
//}