//#include <iostream>
//#include <vector>
//#define pii pair<int,int>
//
//using namespace std;
//
//int n, m, k, board[101][101];
//vector<pii> P;
//
//void input() {
//	cin >> m >> n;
//	for (int i = 0; i <= m; i++) board[0][i] = board[n][i] = 1;
//	for (int i = 0; i <= n; i++) board[i][0] = board[i][m] = 1;
//
//	P.push_back({ 0,0 });
//	P.push_back({ 0,n });
//	P.push_back({ m,0 });
//	P.push_back({ m,n });
//
//	cin >> k;
//	for (int i = 0; i < k; i++) {
//		int a, b;
//		cin >> a >> b;
//		if (a)
//			for (int j = 0; j <= n; j++) {
//				if (board[j][b])
//					P.push_back({ b,j });
//				board[j][b] = 1;
//			}
//		else
//			for (int j = 0; j <= m; j++) {
//				if (board[b][j])
//					P.push_back({ j,b });
//				board[b][j] = 1;
//			}
//	}
//}
//
//pii findP(pii point) {
//	pii ret = make_pair(1000, 1000);
//	for (auto p : P) {
//		if (point.first < p.first && point.second < p.second) {
//			if (p.first < ret.first)
//				ret = p;
//			else if (p.first == ret.first) {
//				if (p.second < ret.second)
//					ret = p;
//			}
//		}
//	}
//	return ret;
//}
//
//void solution() {
//	int ans = 0, x, y;
//	pii np;
//	for (auto p : P) {
//		if (p.first == m || p.second == n) continue;
//		pii np = findP(p);
//		ans = max(ans, (np.first - p.first) * (np.second- p.second));
//	}
//	cout << ans;
//}
//
//int main() {
//	input();
//	solution();
//}