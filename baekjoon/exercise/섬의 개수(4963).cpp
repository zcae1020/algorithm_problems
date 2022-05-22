//#include <iostream>
//#include <cstring>
//#include <queue>
//
//using namespace std;
//
//int W, H, map[50][50], visit[50][50], ans;
//
//int dx[8] = { 0,0,1,-1,-1,-1,1,1 }, dy[8] = { 1,-1,0,0,-1,1,-1,1 };
//
//void BFS() {
//	for (int i = 0; i < H; i++) {
//		for (int j = 0; j < W; j++) {
//			if (map[i][j] == 1 && visit[i][j] == 0) {
//				ans++;
//				queue<int> qx, qy;
//				visit[i][j] = 1;
//				qx.push(i), qy.push(j);
//
//				while (!qx.empty()) {
//					int cx = qx.front(), cy = qy.front();
//					qx.pop(), qy.pop();
//
//					for (int d = 0; d < 8; d++) {
//						int nx = cx + dx[d], ny = cy + dy[d];
//						if (nx < 0 || ny < 0 || nx >= H || ny >= W || visit[nx][ny] || map[nx][ny] == 0) continue;
//
//						visit[nx][ny] = 1;
//						qx.push(nx), qy.push(ny);
//					}
//				}
//			}
//		}
//	}
//}
//
//int main() {
//	while (true) {
//		cin >> W >> H;
//		if (W == 0 && H == 0) break;
//
//		ans = 0;
//		memset(visit, 0, sizeof(visit));
//		for (int i = 0; i < H; i++) {
//			for (int j = 0; j < W; j++) {
//				cin >> map[i][j];
//			}
//		}
//
//		BFS();
//		cout << ans << endl;
//	}
//}