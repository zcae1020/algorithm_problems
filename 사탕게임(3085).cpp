//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int N, mx = 0;
//char map[50][51];
//int dx[2] = { 0,1 }, dy[2] = { 1,0 };
//int lx[4] = { 0,0,1,-1 }, ly[4] = { 1,-1,0,0 };
//
//int maxLength(int x, int y) {
//	int ret = 0;
//	int sum = 1, nx, ny;
//	for (int i = 0; i < 2; i++) {
//		nx = x, ny = y;
//		while (true) {
//			nx += lx[i], ny += ly[i];
//			if (map[ny][nx] != map[y][x] || nx < 0 || ny < 0 || nx >= N || ny >= N)
//				break;
//			sum++;
//		}
//	}
//	ret = max(ret, sum);
//
//	sum = 1;
//	for (int i = 2; i < 4; i++) {
//		nx = x, ny = y;
//		while (true) {
//			nx += lx[i], ny += ly[i];
//			if (map[ny][nx] != map[y][x] || nx < 0 || ny < 0 || nx >= N || ny >= N)
//				break;
//			sum++;
//		}
//	}
//	ret = max(ret, sum);
//
//	return ret;
//}
//
//int main() {
//	cin >> N;
//	for (int i = 0; i < N; i++)
//		cin >> map[i];
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			mx = max(mx, maxLength(j, i));
//		}
//	}
//	if (mx == N) {
//		cout << mx;
//		return 0;
//	}
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			for (int k = 0; k < 2; k++) {
//				int nx = j + dx[k], ny = i + dy[k];
//				if (map[i][j] == map[ny][nx] || nx >= N || ny >= N) continue;
//				
//				char tmp;
//				tmp = map[i][j], map[i][j] = map[ny][nx], map[ny][nx] = tmp;
//
//				mx = max(mx, max(maxLength(j, i), maxLength(nx, ny)));
//
//				tmp = map[i][j], map[i][j] = map[ny][nx], map[ny][nx] = tmp;
//			}
//		}
//	}
//	cout << mx;
//}