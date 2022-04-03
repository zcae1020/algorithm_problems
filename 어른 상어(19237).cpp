//#include <iostream>
//#include <vector>
//#define pii pair<int,int>
//
//using namespace std;
//
//struct s {
//	int x, y, d;
//	bool alive;
//} shark[401];
//
//int N, M, k, prior[401][5][4], rS, T;
//pii map[20][20]; //smell map
//
//int dx[5] = { 0,-1,1,0,0 }, dy[5] = { 0,0,0,-1,1 };
//
//void Input() {
//	cin >> N >> M >> k;
//	rS = M, T = 0;
//
//	int a;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> a;
//			if (a) {
//				shark[a].x = i;
//				shark[a].y = j;
//				shark[a].alive = true;
//				map[i][j] = { a,k };
//			}
//		}
//	}
//
//	for (int i = 1; i <= M; i++) {
//		cin >> a;
//		shark[i].d = a;
//	}
//
//	for (int i = 1; i <= M; i++) {
//		for (int j = 1; j <= 4; j++) {
//			for (int k = 0; k < 4; k++) {
//				cin >> prior[i][j][k];
//			}
//		}
//	}
//}
//
//void sharkMove() {
//	vector<pii> np;
//	bool m;
//	int nx, ny, nd, ex, ey, ed;
//
//	for (int i = 1; i <= M; i++) {
//
//		if (shark[i].alive) {
//
//			struct s cur = shark[i];
//			m = false;
//			ex = ey = ed = -1;
//
//			for (int j = 0; j < 4; j++) {
//
//				nd = prior[i][cur.d][j], nx = cur.x + dx[nd], ny = cur.y + dy[nd];
//
//				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
//
//				if (map[nx][ny].second == 0) {
//					shark[i] = { nx,ny,nd,true };
//					m = true;
//					break;
//				}
//
//				if (ex == -1 && map[nx][ny].second && map[nx][ny].first == i)
//					ex = nx, ey = ny, ed = nd;
//			}
//
//			if (m == false) shark[i] = { ex,ey,ed,true };
//
//		}
//
//	}
//}
//
//void delShark() {
//	vector<pii> v;
//	for (int i = 1; i <= M; i++) {
//		if (shark[i].alive) {
//			for (auto a : v) {
//				if (a == make_pair(shark[i].x, shark[i].y)) {
//					shark[i].alive = false;
//					rS--;
//					break;
//				}
//			}
//
//			if (shark[i].alive) v.push_back({ shark[i].x,shark[i].y });
//		}
//	}
//}
//
//void weakenSmell() {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			if (map[i][j].second > 0) map[i][j].second--;
//		}
//	}
//}
//
//void makeSmell() {
//	for (int i = 1; i <= M; i++) {
//		if (shark[i].alive) {
//			map[shark[i].x][shark[i].y] = { i,k };
//		}
//	}
//}
//
//void Solution() {
//	while (T <= 1000) {
//
//		if (rS == 1) {
//			cout << T;
//			return;
//		}
//
//		sharkMove();
//		delShark();
//		weakenSmell();
//		makeSmell();
//		
//		T++;
//	}
//
//	cout << -1;
//}
//
//int main() {
//	ios::sync_with_stdio(0);
//	Input();
//	Solution();
//}