//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <queue>
//#include <cstring>
//#define MAX 10001
//#define pii pair<int,int>
//
//using namespace std;
//
//int N, M, A, B, MC, visited[MAX];
//vector<vector<pii>> v(MAX);
//
//void Input() {
//	cin >> N >> M;
//	for (int i = 0; i < M; i++) {
//		int a, b, c;
//		cin >> a >> b >> c;
//
//		MC = max(MC, c);
//		v[a].push_back(make_pair(b, c));
//		v[b].push_back(make_pair(a, c));
//	}
//	cin >> A >> B;
//}
//
//bool BFS(int cost) {
//	queue<int> q;
//	q.push(A);
//	visited[A] = true;
//
//	while (!q.empty()) {
//		int cur = q.front();
//		q.pop();
//
//		if (cur == B)
//			return true;
//
//		for (pii p : v[cur]) {
//			int to = p.first, w = p.second;
//			if (visited[to] || w < cost)
//				continue;
//
//			q.push(to);
//			visited[to] = true;
//		}
//	}
//	return false;
//}
//
//int BS() {
//	int l = 1, r = MC + 1, m;
//	while (l + 1 < r) {
//		memset(visited, 0, sizeof(visited));
//		m = (l + r) / 2;
//		if (BFS(m)) l = m;
//		else r = m;
//	}
//	return l;
//}
//
//int main() {
//	Input();
//	cout << BS();
//}