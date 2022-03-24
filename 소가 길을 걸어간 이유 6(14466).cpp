//#include <iostream>
//#include <vector>
//#include <queue>
//#define pii pair<int,int>
//
//using namespace std;
//
//int N, K, R, ans;
//bool map[101][101];
//vector<pii> cowList, road[101][101];
//
//int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
//
//void Input() {
//	cin >> N >> K >> R;
//	for (int i = 0; i < R; i++) {
//		int r1, c1, r2, c2;
//		cin >> r1 >> c1 >> r2 >> c2;
//
//		road[r1][c1].push_back({ r2,c2 });
//		road[r2][c2].push_back({ r1,c1 });
//	}
//	for (int i = 0; i < K; i++) {
//		int r, c;
//		cin >> r >> c;
//		map[r][c] = true;
//		cowList.push_back({ r,c });
//	}
//}
//
//void Solution() {
//	for (int i = 0; i < K; i++) {
//		int metCow = 1;
//		bool visit[101][101] = { false };
//		queue<pii> q;
//
//		q.push({ cowList[i] });
//		visit[cowList[i].first][cowList[i].second] = true;
//
//		while (!q.empty()) {
//			pii cur = q.front();
//			q.pop();
//
//			for (int i = 0; i < 4; i++) {
//				int nx = cur.first + dx[i], ny = cur.second + dy[i];
//
//				if (nx <= 0 || ny <= 0 || nx > N || ny > N || visit[nx][ny]) continue;
//
//				bool onRoad = false;
//				for (auto a : road[cur.first][cur.second]) {
//					if (a == make_pair(nx, ny)) {
//						onRoad = true;
//						break;
//					}
//				}
//
//				if (onRoad) continue;
//
//				if (map[nx][ny]) metCow++;
//				q.push({ nx,ny });
//				visit[nx][ny] = true;
//			}
//		}
//
//		ans += (K - metCow);
//	}
//
//	cout << ans / 2;
//}
//
//int main() {
//	Input();
//	Solution();
//}