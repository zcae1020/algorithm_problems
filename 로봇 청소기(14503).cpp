//#include <iostream>
//
//using namespace std;
//
//int N, M, r, c, d, map[50][50], clean[50][50] = { 0 };
//int dx[4] = { 0,1,0,-1 }, dy[4] = { -1,0,1,0 };
//
//void dfs(int x, int y, int di) {
//	int flag = 0;
//	if (!map[y][x])
//		clean[y][x] = 1;
//	for (int i = 0;i < 4;i++) {
//		int dir = di - 1 - i, nx, ny;
//		dir = dir < 0 ? dir + 4 : dir;
//		nx = x + dx[dir], ny = y + dy[dir];
//		if (!clean[ny][nx] && !map[ny][nx]) {
//			dfs(nx, ny, dir);
//			flag = 1;
//			break;
//		}
//	}
//	if (!flag && !map[y - dy[di]][x - dx[di]])
//		dfs(x - dx[di], y - dy[di], di);
//}
//
//int countClean() {
//	int ret = 0;
//	for (int i = 0;i < N;i++)
//		for (int j = 0;j < M;j++)
//			if (clean[i][j])
//				ret++;
//	return ret;
//}	
//
//int main() {
//	cin >> N >> M >> r >> c >> d;
//	for (int i = 0;i < N;i++) {
//		for (int j = 0;j < M;j++) {
//			cin >> map[i][j];
//		}
//	}
//	dfs(c, r, d);
//	cout << countClean();
//}