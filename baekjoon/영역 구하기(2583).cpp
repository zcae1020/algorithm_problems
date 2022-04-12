//#include <iostream>
//#include <queue>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int M, N, K, map[100][100] = { 0 }, visited[100][100] = { 0 };
//int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
//
//int main() {
//	cin >> M >> N >> K;
//	for (int i = 0;i < K;i++) {
//		int x1, y1, x2, y2;
//		cin >> x1 >> y1 >> x2 >> y2;
//		for (int j = y1;j < y2;j++) {
//			for (int k = x1;k < x2;k++) {
//				map[j][k] = 1;
//			}
//		}
//	}
//
//	queue<int> qx, qy;
//	vector<int> v;
//	for (int i = 0;i < M;i++) {
//		for (int j = 0;j < N;j++) {
//			if (visited[i][j] || map[i][j])
//				continue;
//			int block;
//			qx.push(j), qy.push(i);
//			visited[i][j] = 1;
//			block = 1;
//			while (!qx.empty()) {
//				int cx = qx.front(), cy = qy.front();
//				qx.pop(), qy.pop();
//				for (int k = 0;k < 4;k++) {
//					int nx = cx + dx[k], ny = cy + dy[k];
//					if (map[ny][nx] || visited[ny][nx] || nx < 0 || ny < 0 || nx >= N || ny >= M)
//						continue;
//					qx.push(nx), qy.push(ny);
//					visited[ny][nx] = 1;
//					block++;
//				}
//			}
//			v.emplace_back(block);
//		}
//	}
//	sort(v.begin(), v.end());
//	cout << v.size() << endl;
//	for (int i = 0;i < v.size();i++) {
//		cout << v[i] << ' ';
//	}
//}