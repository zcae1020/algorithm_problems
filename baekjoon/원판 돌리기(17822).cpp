//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//int N, M, T, map[51][51];
//
//int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
//
//void Input() {
//	cin >> N >> M >> T;
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= M; j++) {
//			cin >> map[i][j];
//		}
//	}
//}
//
//void rotateClock(int x, int d, int k) {
//	if (d) k = M - k;
//
//	while (k--) {
//		for (int i = x; i <= N; i += x) {
//			int tmp[51] = { 0 };
//			tmp[1] = map[i][M];
//			for (int j = 1; j < M; j++) {
//				tmp[j + 1] = map[i][j];
//				map[i][j] = tmp[j];
//			}
//			map[i][M] = tmp[M];
//		}
//	}
//}
//
//int findAdjAndDel() {
//	int visited[51][51] = { 0 }, ret = 0;
//
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= M; j++) {
//
//			if (visited[i][j] == 0 && map[i][j]) {
//
//				int cn = map[i][j];
//				queue<int> qx, qy;
//				qx.push(i), qy.push(j);
//				visited[i][j] = 1;
//
//				while (!qx.empty()) {
//					int cx = qx.front(), cy = qy.front();
//					qx.pop(), qy.pop();
//
//					for (int k = 0; k < 4; k++) {
//						int nx = cx + dx[k], ny = cy + dy[k];
//
//						if (ny < 1) ny = M;
//						else if (ny > M) ny = 1;
//
//						if (nx<1 || nx>N || visited[nx][ny]) continue;
//
//						if (map[nx][ny] == cn) {
//							map[cx][cy] = map[nx][ny] = 0;
//							qx.push(nx), qy.push(ny);
//							visited[nx][ny] = 1;
//							ret++;
//						}
//					}
//				}
//			}
//		}
//	}
//
//	return ret;
//}
//
//double getAverage() {
//	double son = 0, cnt = 0;
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= M; j++) {
//			if (map[i][j]) {
//				cnt++;
//				son += map[i][j];
//			}
//		}
//	}
//	if (cnt) return son / cnt;
//	else return 0;
//}
//
//void notAdj() {
//	double A = getAverage();
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= M; j++) {
//			if (map[i][j]) {
//				if ((double)map[i][j] > A) map[i][j]--;
//				else if ((double)map[i][j] < A) map[i][j]++;
//			}
//		}
//	}
//}
//
//void print() {
//	int ans = 0;
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= M; j++) {
//			if (map[i][j]) ans += map[i][j];
//		}
//	}
//	cout << ans;
//}
//
//void Solution() {
//	while (T--) {
//		int x, d, k;
//		cin >> x >> d >> k;
//		rotateClock(x, d, k);
//		if (findAdjAndDel() == 0)
//			notAdj();
//	}
//	print();
//}
//
//int main() {
//	Input();
//	Solution();
//}