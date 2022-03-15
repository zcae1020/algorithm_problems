//#include <iostream>
//#include <vector>
//#include <queue>
//#include <cstring>
//#include <algorithm>
//#define pii pair<int,int>
//
//using namespace std;
//
//int n, m, map[50][50], visited[50][50], vv[2500];
//vector<pii> v;
//vector<int> ans;
//
//int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
//
//void Input() {
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cin >> map[i][j];
//			if (map[i][j] == 2) v.push_back({ j,i });
//		}
//	}
//	memset(visited, -1, sizeof(visited));
//}
//
//bool spreadAll() {
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			if (visited[i][j] == -1 && map[i][j] == 0) return false;
//	return true;
//}
//
//void DFS(int idx, int cnt) {
//	if (cnt == m) {
//		int ret = 0;
//		memset(visited, -1, sizeof(visited));
//		queue<pair<pii, int>> q;
//		for (int i = 0; i < v.size(); i++){
//			if (vv[i]) {
//				visited[v[i].second][v[i].first] = 0;
//				q.push({ v[i],0 });
//			}
//		}
//		
//		while (!q.empty()) {
//			pii cur = q.front().first;
//			int cnt = q.front().second;
//			q.pop();
//
//			for (int i = 0; i < 4; i++) {
//				int nx = cur.first + dx[i], ny = cur.second + dy[i];
//				if (nx < 0 || ny < 0 || nx >= n || ny >= n || visited[ny][nx] != -1 || map[ny][nx] == 1) continue;
//
//				visited[ny][nx] = cnt + 1;
//				q.push(make_pair(make_pair(nx, ny), cnt + 1));
//			}
//		}
//
//		if (spreadAll()) {
//			for (int i = 0; i < n; i++)
//				for (int j = 0; j < n; j++) {
//					if (map[i][j] == 2) continue;
//					ret = max(ret, visited[i][j]);
//				}
//		}
//		else ret = -1;
//
//		ans.push_back(ret);
//	}
//
//	for (int i = idx; i < v.size(); i++) {
//		if (vv[i] == 0) {
//			vv[i] = 1;
//			DFS(i + 1, cnt + 1);
//			vv[i] = 0;
//		}
//	}
//}
//
//int main() {
//	Input();
//	DFS(0, 0);
//	sort(ans.begin(), ans.end());
//	for (auto a : ans) {
//		if (a == -1) continue;
//		cout << a;
//		return 0;
//	}
//	cout << -1;
//}