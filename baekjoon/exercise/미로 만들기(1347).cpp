//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//char map[200][200], input[51];
//int N, ltx, lty, rbx, rby, cx, cy, cd = 0;
//int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
//
//int main() {
//	for (int i = 0;i < 200;i++)
//		for (int j = 0;j < 200;j++)
//			map[i][j] = '#';
//	map[100][100] = '.';
//	ltx = lty = rbx = rby = cx = cy = 100;
//	cin >> N;
//	cin >> input;
//	int nx, ny;
//	for (int i = 0;i < N;i++) {
//		switch (input[i]) {
//		case 'F':
//			nx = cx + dx[cd], ny = cy + dy[cd];
//			map[ny][nx] = '.';
//			ltx = min(ltx, nx), lty = min(lty, ny);
//			rbx = max(rbx, nx), rby = max(rby, ny);
//			cx = nx, cy = ny;
//			break;
//		case 'L':
//			cd += 1;
//			cd %= 4;
//			break;
//		case 'R':
//			cd -= 1;
//			if (cd < 0)
//				cd = 3;
//			break;
//		}
//	}
//
//	for (int i = lty;i <= rby;i++) {
//		for (int j = ltx;j <= rbx;j++) {
//			cout << map[i][j];
//		}
//		cout << endl;
//	}
//}