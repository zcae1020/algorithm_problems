//#include <iostream>
//#include <queue>
//#include <cstring>
//#define pii pair<int,int>
//
//using namespace std;
//
//int M, N, sx, sy, sd, ex, ey, ed, map[101][101], visited[5][101][101];
//
//queue<pair<pii, int>> q;
//
//int dx[5] = { 0,1,-1,0,0 }, dy[5] = { 0,0,0,1,-1 };
//int di[4] = { 4,1,3,2 };
//
//void Input() {
//	
//	cin >> M >> N;
//	
//	for (int i = 1; i <= M; i++) {
//		for (int j = 1; j <= N; j++) {
//			cin >> map[i][j];
//		}
//	}
//
//	cin >> sy >> sx >> sd;
//	cin >> ey >> ex >> ed;
//
//	memset(visited, -1, sizeof(visited));
//}
//
//void go(int x, int y, int d, int c) {
//}
//
//void BFS() {
//	q.push(make_pair(make_pair(sx, sy), sd));
//	visited[sd][sy][sx] = 0;
//
//	while (!q.empty()) {
//		int x = q.front().first.first;
//		int y = q.front().first.second;
//		int d = q.front().second;
//		int c = visited[d][y][x];
//		q.pop();
//
//		if (visited[ed][ey][ex] != -1) {
//			cout << visited[ed][ey][ex];
//			return;
//		}
//
//		if (d < 3) { //1,2
//			if (visited[3][y][x] == -1) {
//				visited[3][y][x] = c + 1;
//				q.push(make_pair(make_pair(x, y), 3));
//			}
//			if (visited[4][y][x] == -1) {
//				visited[4][y][x] = c + 1;
//				q.push(make_pair(make_pair(x, y), 4));
//			}
//		}
//		else { //3,4
//			if (visited[1][y][x] == -1) {
//				visited[1][y][x] = c + 1;
//				q.push(make_pair(make_pair(x, y), 1));
//			}
//			if (visited[2][y][x] == -1) {
//				visited[2][y][x] = c + 1;
//				q.push(make_pair(make_pair(x, y), 2));
//			}
//		}
//
//		for (int i = 1; i <= 3; i++) {
//			int nx = x + dx[d] * i, ny = y + dy[d] * i;
//			if (nx<1 || ny<1 || nx>N || ny>M || map[ny][nx]) break;
//
//			if (visited[d][ny][nx] == -1) {
//				visited[d][ny][nx] = c + 1;
//				q.push(make_pair(make_pair(nx, ny), d));
//			}
//		}
//	}
//}
//
//int main() {
//	Input();
//	BFS();
//}