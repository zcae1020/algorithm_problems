//#include <iostream>
//#include <algorithm>
//#include <queue>
//#include <cstring>
//#include <tuple>
//#define pii pair<int,int>
//
//using namespace std;
//
//int N, M;
//bool visited[50][50][64];
//char map[51][51];
//queue<pair<pii, pii>> q;
//pii z;
//
//int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
//
//void Input() {
//	cin >> N >> M;
//	for (int i = 0; i < N; i++) {
//		cin >> map[i];
//		for (int j = 0; j < M; j++) {
//			if (map[i][j] == '0') {
//				z = make_pair(j, i);
//				map[i][j] = '.';
//			}
//		}
//	}
//}
//
//bool haveKey(int k, char d) {
//	int dtoi = 1 << (d - 'A');
//	return k & dtoi;
//}
//
//int bfs() {
//	q.push(make_pair(z, make_pair(0, 0)));
//	visited[z.second][z.first][0] = true;
//
//	while (!q.empty()) {
//		pii cur = q.front().first;
//		int cnt = q.front().second.first;
//		int key = q.front().second.second;
//		q.pop();
//
//		for (int i = 0; i < 4; i++) {
//			int nx = cur.first + dx[i], ny = cur.second + dy[i];
//			
//			if (nx < 0 || ny < 0 || nx >= M || ny >= N)
//				continue;
//
//			if (!visited[ny][nx][key]) {
//				
//				if (map[ny][nx] == '1')
//					return cnt + 1;
//				
//				if (map[ny][nx] == '.') {
//					visited[ny][nx][key] = true;
//					q.push(make_pair(make_pair(nx, ny), make_pair(cnt + 1, key)));
//				}
//
//				if (map[ny][nx] >= 'A' && map[ny][nx] <= 'F') {
//					if (haveKey(key, map[ny][nx])) {
//						visited[ny][nx][key] = true;
//						q.push(make_pair(make_pair(nx, ny), make_pair(cnt + 1, key)));
//					}
//				}
//
//				if (map[ny][nx] >= 'a' && map[ny][nx] <= 'f') {
//					int tmpK = key | (1 << (map[ny][nx] - 'a'));
//					visited[ny][nx][tmpK] = true;
//					q.push(make_pair(make_pair(nx, ny), make_pair(cnt + 1, tmpK)));
//				}
//			}
//		}
//	}
//	return -1;
//}
//
//int main() {
//	Input();
//	cout << bfs();
//}