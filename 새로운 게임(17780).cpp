//#include <iostream>
//#include <vector>
//#include <algorithm>
//#define pii pair<int,int>
//
//using namespace std;
//
//int N, K, map[12][12];
//pair<pii, int>u[10];
//vector<int> umap[12][12];
//
//int dx[4] = { 0,0,-1,1 }, dy[4] = { 1,-1,0,0 };
//
//void Input() {
//	cin >> N >> K;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> map[i][j];
//		}
//	}
//
//	for (int i = 0; i < K; i++) {
//		int x, y, d;
//		cin >> x >> y >> d;
//		umap[x - 1][y - 1].push_back(i);
//		u[i] = { {x - 1,y - 1},d - 1 };
//	}
//}
//
//int changeD(int d) {
//	if (d == 0)d = 1;
//	else if (d == 1)d = 0;
//	else if (d == 2)d = 3;
//	else if (d == 3)d = 2;
//	return d;
//}
//
//pii move(int uIdx) {
//	pair<pii, int> *cur = &u[uIdx];
//	pii cp = cur->first;
//	pii np = { cur->first.first + dx[cur->second], cur->first.second + dy[cur->second] };
//
//	if (np.first < 0 || np.second < 0 || np.first >= N || np.second >= N || map[np.first][np.second] == 2) {
//		u[uIdx].second = changeD(u[uIdx].second);
//		np = { cp.first + dx[cur->second],cp.second + dy[cur->second] };
//
//		if (np.first >= 0 && np.second >= 0 && np.first < N && np.second < N && map[np.first][np.second] != 2) return move(uIdx);
//		return cp;
//	}
//	else if (map[np.first][np.second] == 1)
//		reverse(umap[cp.first][cp.second].begin(), umap[cp.first][cp.second].end());
//
//	for (auto a : umap[cp.first][cp.second]) {
//		u[a] = { {np.first,np.second},u[a].second };
//		umap[np.first][np.second].push_back(a);
//	}
//	umap[cp.first][cp.second].clear();
//	return np;
//}
//
//void Solution() {
//	int turn = 0;
//	while (turn <= 1000) {
//		turn++;
//		for (int i = 0; i < K; i++) {
//			pair<pii, int> cur = u[i];
//			if (umap[cur.first.first][cur.first.second][0] == i) {
//				pii p = move(i);
//				if (umap[p.first][p.second].size() >= 4) {
//					cout << turn;
//					return;
//				}
//			}
//		}
//	}
//	cout << -1;
//}
//
//int main() {
//	Input();
//	Solution();
//}