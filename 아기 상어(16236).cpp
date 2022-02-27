//#include <iostream>
//#include <vector>
//#include <tuple>
//#include <queue>
//#define pii pair<int,int>
//
//using namespace std;
//
//typedef struct shark {
//	pii p;
//	int eat = 0;
//	int size = 2;
//} Shark;
//
//int N, map[20][20], ans = 0;
//Shark s;
//vector<vector<pii>> f(7);
//
//int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
//
//pii nextP(pii p1, pii p2) {
//	if (p1.second == p2.second)
//		return p1.first < p2.first ? p1 : p2;
//	return p1.second < p2.second ? p1 : p2;
//}
//
//pair<int, pii> nextFish() {
//	bool visited[20][20] = { 0 };
//	int ret = 1000;
//	pii retp = { 20,20 };
//	queue<pair<int, pii>> q;
//	visited[s.p.second][s.p.first] = 1;
//	q.push(make_pair(0, s.p));
//	while (!q.empty()) {
//		pii t;
//		int cx, cy, d;
//		tie(d, t) = q.front();
//		tie(cx, cy) = t;
//		if (map[cy][cx] && map[cy][cx] != 9 && map[cy][cx] < s.size) {
//			if (ret == d)
//				retp = nextP(retp, t);
//			else if (ret > d) {
//				ret = d;
//				retp = t;
//			}
//		}
//		q.pop();
//		for (int i = 0;i < 4;i++) {
//			int nx = cx + dx[i], ny = cy + dy[i];
//			if (nx < 0 || ny < 0 || nx >= N || ny >= N || visited[ny][nx] || map[ny][nx]>s.size)
//				continue;
//			q.push(make_pair(d + 1, make_pair(nx, ny)));
//			visited[ny][nx] = 1;
//		}
//	}
//	return make_pair(ret, retp);
//}
//
//int main() {
//	cin >> N;
//	for (int i = 0;i < N;i++) {
//		for (int j = 0;j < N;j++) {
//			cin >> map[i][j];
//			if (map[i][j]) {
//				if (map[i][j] == 9)
//					s.p = { j,i };
//				else
//					f[map[i][j]].emplace_back(make_pair(j, i));
//			}
//		}
//	}
//
//	while (true) {
//		pair<int, pii> nf = nextFish();
//		if (nf.first == 1000) {
//			cout << ans;
//			exit(0);
//		}
//		s.eat++;
//		ans += nf.first;
//		map[s.p.second][s.p.first] = 0;
//		map[nf.second.second][nf.second.first] = 9;
//		s.p = nf.second;
//		if (s.eat == s.size) {
//			s.size++;
//			s.eat = 0;
//		}
//	}
//}