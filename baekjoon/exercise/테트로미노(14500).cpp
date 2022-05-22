//#include <iostream>
//#include <algorithm>
//#define pii pair<int,int>
//
//using namespace std;
//
//int N, M, map[500][500], visited[500][500] = { 0 };
//int dx[3] = { 0,1,-1 }, dy[3] = { 1,0,0 };
//int fdx[4] = { 0,0,-1,1 }, fdy[4] = { 1,-1,0,0 };
//
//int dfs(int x, int y, int n) {
//	if (n == 3)
//		return map[y][x];
//
//	int mx = 0, ret = map[y][x];
//	for (int i = 0;i < 3;i++) {
//		int nx = x + dx[i], ny = y + dy[i];
//		if (visited[ny][nx] || nx<0 || ny<0 || nx>=M || ny>=N)
//			continue;
//		visited[ny][nx] = 1;
//		mx = max(mx, dfs(nx, ny, n + 1));
//		visited[ny][nx] = 0;
//	}
//	return ret + mx;
//}
//
//int main() {
//	cin >> N >> M;
//	for (int i = 0;i < N;i++)
//		for (int j = 0;j < M;j++)
//			cin >> map[i][j];
//
//	int mx = 0;
//	for (int i = 0;i < N;i++) {
//		for (int j = 0;j < M;j++) {
//			visited[i][j] = 1;
//			mx = max(mx, dfs(j, i, 0));
//			visited[i][j] = 0;
//
//			for (int k = 0;k < 4;k++) {
//				int f = map[i][j];
//				for (int l = 0;l < 4;l++) {
//					if (l == k)
//						continue;
//					int nx = j + fdx[l], ny = i + fdy[l];
//					if (nx<0 || ny<0 || nx>=M || ny>=N) {
//						f = -1;
//						break;
//					}
//					f += map[ny][nx];
//				}
//				mx = max(mx, f);
//			}
//		}
//	}
//	cout << mx;
//}