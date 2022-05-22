//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#define pii pair<int,int>
//
//using namespace std;
//
//struct client {
//	int clix, cliy, desx, desy;
//	bool isArrived;
//} Client[400];
//
//pii taxi;
//int map[21][21];
//int N, M, fuel;
//
//int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
//
//void Input() {
//	cin >> N >> M >> fuel;
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= N; j++) {
//			cin >> map[i][j];
//		}
//	}
//
//	cin >> taxi.first >> taxi.second;
//
//	for (int i = 0; i < M; i++) {
//		int a, b, c, d;
//		cin >> a >> b >> c >> d;
//		Client[i] = { a,b,c,d,false };
//		map[a][b] = 2 + i;
//	}
//}
//
//int BFS(int sx, int sy, int ex, int ey) {
//	
//	queue<int> qx, qy, qc;
//	int visit[21][21] = { 0 };
//
//	qx.push(sx), qy.push(sy), qc.push(0);
//	visit[sx][sy] = 1;
//
//	while (!qx.empty()) {
//		int cx = qx.front(), cy = qy.front(), cnt = qc.front();
//		qx.pop(), qy.pop(), qc.pop();
//
//		if (cx == ex && cy == ey) return cnt;
//
//		for (int i = 0; i < 4; i++) {
//			int nx = cx + dx[i], ny = cy + dy[i];
//			if (nx<1 || ny<1 || nx>N || ny>N || visit[nx][ny] || map[nx][ny] == 1) continue;
//
//			qx.push(nx), qy.push(ny), qc.push(cnt + 1);
//			visit[nx][ny] = 1;
//		}
//	}
//
//	return -1;
//}
//
//int nextClient() {
//	vector<int> idx;
//	queue<int> qx, qy, qc;
//	int visit[21][21] = { 0 }, length = 10000;
//
//	qx.push(taxi.first), qy.push(taxi.second), qc.push(0);
//	visit[taxi.first][taxi.second] = 1;
//
//	while (!qx.empty()) {
//		int cx = qx.front(), cy = qy.front(), cnt = qc.front();
//		qx.pop(), qy.pop(), qc.pop();
//
//		if (length < cnt) continue;
//
//		if (map[cx][cy] > 1) {
//			if (Client[map[cx][cy] - 2].isArrived == false) {
//				if (length > cnt) {
//					length = cnt;
//					idx.clear();
//					idx.push_back(map[cx][cy] - 2);
//				}
//				else if (length == cnt) idx.push_back(map[cx][cy] - 2);
//			}
//		}
//
//		for (int i = 0; i < 4; i++) {
//
//			int nx = cx + dx[i], ny = cy + dy[i];
//
//			if (nx<1 || ny<1 || nx>N || ny>N || visit[nx][ny] || map[nx][ny] == 1) continue;
//
//			qx.push(nx), qy.push(ny), qc.push(cnt + 1);
//			visit[nx][ny] = 1;
//		}
//	}
//
//	if (idx.empty()) return -1;
//
//	fuel -= length;
//	int ret = idx[0];
//
//	if (idx.size() == 1) return ret;
//	else {
//
//		for (int i = 1; i < idx.size(); i++) {
//
//			struct client rc = Client[ret], cc = Client[idx[i]];
//
//			if (rc.clix > cc.clix) {
//				ret = idx[i];
//			}
//			else if (rc.clix == cc.clix) {
//				if (rc.cliy > cc.cliy)
//					ret = idx[i];
//			}
//
//		}
//
//		return ret;
//	}
//}
//
//void startToEnd(int nC) {
//	Client[nC].isArrived = true;
//	struct client cur = Client[nC];
//
//	int length = BFS(cur.clix, cur.cliy, cur.desx, cur.desy);
//	if (length == -1) {
//		cout << -1;
//		exit(0);
//	}
//	taxi = { cur.desx,cur.desy };
//
//	if (fuel < length) fuel -= length;
//	else fuel += length;
//}
//
//void Solution() {
//	while (fuel >= 0) {
//		int nC = nextClient();
//
//		if (nC == -1) {
//			for (int i = 0; i < M; i++) {
//				if (Client[i].isArrived == false) {
//					cout << -1;
//					return;
//				}
//			}
//			cout << fuel;
//			return;
//		}
//
//		startToEnd(nC);
//	}
//	cout << -1;
//}
//
//int main() {
//	ios::sync_with_stdio(0);
//	Input();
//	Solution();
//}