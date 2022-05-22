//#include <iostream>
//#include <queue>
//#define pii pair<int,int>
//
//using namespace std;
//
//int N, M, visited[2][1000][1000];
//char map[1000][1001];
//
//int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
//
//void Input() {
//	cin >> N >> M;
//	for (int i = 0; i < N; i++) cin >> map[i];
//}
//
//void BFS() {
//	queue<pair<pii, pii>> q;
//	q.push(make_pair(make_pair(0, 0), make_pair(1, 1)));
//	visited[1][0][0] = 1;
//
//	while (!q.empty()) {
//		pii curp = q.front().first;
//		int curc = q.front().second.first;
//		int removeWall = q.front().second.second;
//		q.pop();
//
//		if (curp == make_pair(M - 1, N - 1)) {
//			cout << curc;
//			return;
//		}
//
//		for (int i = 0; i < 4; i++) {
//			int nx = curp.first + dx[i], ny = curp.second + dy[i], nrw = removeWall;
//
//			if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
//			if (map[ny][nx] == '0') {
//				if (visited[nrw][ny][nx]) continue;
//				visited[nrw][ny][nx] = 1;
//				q.push(make_pair(make_pair(nx, ny), make_pair(curc + 1, nrw)));
//			}
//			else { //1
//				if (nrw == 0) continue;
//				else {
//					nrw = 0;
//					if (visited[nrw][ny][nx]) continue;
//					visited[nrw][ny][nx] = 1;
//					q.push(make_pair(make_pair(nx, ny), make_pair(curc + 1, nrw)));
//				}
//			}
//		}
//	}
//	cout << -1;
//}
//
//int main() {
//	Input();
//	BFS();
//}