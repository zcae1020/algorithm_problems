//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <set>
//#include <tuple>
//#define pii pair<int,int>
//
//using namespace std;
//
//set<pii> t;
//vector<int> age[11][11];
//vector<int> e[11][11];
//int map[11][11];
//
//int dx[8] = { 0,0,1,1,1,-1,-1,-1 }, dy[8] = { 1,-1,1,-1,0,1,-1,0 };
//
//int N, M, K;
//int A[11][11];
//
//void ss() {
//	int d, x, y;
//	vector<int> tmp;
//	for (pii p : t) {
//		tie(x, y) = p;
//		if (age[y][x].empty())continue;
//
//		d = 0;
//		tmp.clear();
//		sort(age[y][x].begin(), age[y][x].end());
//
//		for (int i = 0;i < age[y][x].size();i++) {
//			if (map[y][x] >= age[y][x][i]) {
//				map[y][x] -= age[y][x][i];
//				tmp.emplace_back(age[y][x][i] + 1);
//			}
//			else
//				d += (age[y][x][i] / 2);
//		}
//
//		map[y][x] += d;
//		age[y][x].clear();
//		for (int a : tmp)
//			age[y][x].emplace_back(a);
//	}
//}
//
//void autumn() {
//	int x, y;
//	for (pii p : t) {
//		tie(x, y) = p;
//		for (int a : age[y][x]) {
//			if (a % 5 == 0) {
//				int nx, ny;
//				for (int i = 0;i < 8;i++) {
//					nx = x + dx[i], ny = y + dy[i];
//					if (nx<1 || ny<1 || nx>N || ny>N)
//						continue;
//					age[ny][nx].emplace_back(1);
//					t.insert({ nx,ny });
//				}
//			}
//		}
//	}
//}
//
//void winter() {
//	for (int i = 1;i <= N;i++) {
//		for (int j = 1;j <= N;j++) {
//			map[i][j] += A[i][j];
//		}
//	}
//}
//
//int treeNum() {
//	int ret = 0, x, y;
//	for (pii p : t) {
//		tie(x, y) = p;
//		ret += age[y][x].size();
//	}
//	return ret;
//}
//
//int main() {
//	cin >> N >> M >> K;
//	for (int i = 1;i <= N;i++) {
//		for (int j = 1;j <= N;j++) {
//			cin >> A[i][j];
//			map[i][j] = 5;
//		}
//	}
//	for (int i = 0;i < M;i++) {
//		int x, y, a;
//		cin >> x >> y >> a;
//		pii p = { y,x };
//		t.insert(p);
//		age[x][y].emplace_back(a);
//	}
//
//	for (int i = 0;i < K;i++) {
//		ss();
//		autumn();
//		winter();
//	}
//
//	cout << treeNum();
//}
