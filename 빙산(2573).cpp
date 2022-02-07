//#include <iostream>
//#include <vector>
//#include <queue>
//#define pii pair<int,int>
//
//using namespace std;
//
//int N, M, map[302][302], visited[302][302] = { 0 };
//int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
//vector<pii> ice;
//vector<int> w;
//queue<int> qx, qy;
//
//int main() {
//	cin >> N >> M;
//	for (int i = 0;i < N;i++) {
//		for (int j = 0;j < M;j++) {
//			cin >> map[i][j];
//			if (map[i][j]) {
//				pii p = { j,i };
//				ice.emplace_back(p);
//			}
//		}
//	}
//
//	int year = 0;
//	while (!ice.empty()) {
//		year++;
//		for (int i = 0;i < ice.size();i++) {
//			int water = 0;
//			for (int j = 0;j < 4;j++) {
//				int nx = ice[i].first + dx[j], ny = ice[i].second + dy[j];
//				if (nx < 0 || ny < 0 || nx >= M || ny >= N)
//					continue;
//				if (!map[ny][nx])
//					water++;
//			}
//			w.emplace_back(water);
//		}
//
//		for (int i = 0;i < ice.size();i++) {
//			int cx = ice[i].first, cy = ice[i].second;
//			if (map[cy][cx] <= w[i]) {
//				map[cy][cx] = 0;
//				ice.erase(ice.begin() + i);
//				w.erase(w.begin() + i);
//				i--;
//			}
//			else
//				map[cy][cx] -= w[i];
//		}
//		w.clear();
//
//		int cnt = 0;
//		for (int i = 0;i < ice.size();i++) {
//			if (!visited[ice[i].second][ice[i].first]) {
//				if (cnt) {
//					cout << year;
//					exit(0);
//				}
//				cnt = 1;
//				qx.push(ice[i].first), qy.push(ice[i].second);
//				visited[ice[i].second][ice[i].first] = 1;
//				while (!qx.empty()) {
//					int cx = qx.front(), cy = qy.front();
//					qx.pop(), qy.pop();
//					for (int k = 0;k < 4;k++) {
//						int nx = cx + dx[k], ny = cy + dy[k];
//						if (nx < 0 || ny < 0 || nx >= M || ny >= N || visited[ny][nx] || !map[ny][nx])
//							continue;
//						qx.push(nx), qy.push(ny);
//						visited[ny][nx] = 1;
//					}
//				}
//			}
//		}
//
//		for (int i = 0;i < N;i++) {
//			for (int j = 0;j < M;j++) {
//				visited[i][j] = 0;
//			}
//		}
//	}
//	cout << 0;
//}