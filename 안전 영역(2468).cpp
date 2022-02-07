//#include <iostream>
//#include <algorithm>
//#include <queue>
//
//using namespace std;
//
//int N, vmx, map[102][102], visited[102][102] = { 0 };
//int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
//queue<int> qx, qy;
//
//int main() {
//	vmx = 0;
//	cin >> N;
//	for (int i = 0;i < N;i++) {
//		for (int j = 0;j < N;j++) {
//			cin >> map[i][j];
//			vmx = max(vmx, map[i][j]);
//		}
//	}
//
//	int ans = 0;
//	for (int h = 0;h <= vmx;h++) {
//		int cnt = 0;
//		for (int i = 0;i < N;i++) {
//			for (int j = 0;j < N;j++) {
//				if (h >= map[i][j])
//					visited[i][j] = 1;
//			}
//		}
//		for (int i = 0;i < N;i++) {
//			for (int j = 0;j < N;j++) {
//				if (visited[i][j])
//					continue;
//				cnt++;
//				qx.push(j), qy.push(i);
//				visited[i][j] = 1;
//				while (!qx.empty()) {
//					int cx = qx.front(), cy = qy.front();
//					qx.pop(), qy.pop();
//					for (int k = 0;k < 4;k++) {
//						int nx = cx + dx[k], ny = cy + dy[k];
//						if (nx < 0 || ny < 0 || nx >= N || ny >= N || visited[ny][nx])
//							continue;
//						qx.push(nx), qy.push(ny);
//						visited[ny][nx] = 1;
//					}
//				}
//			}
//		}
//		for (int i = 0;i < N;i++) {
//			for (int j = 0;j < N;j++) {
//				visited[i][j] = 0;
//			}
//		}
//		ans = max(ans, cnt);
//	}
//	cout << ans;
//}