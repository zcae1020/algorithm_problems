//#include <iostream>
//#include <vector>
//#include <queue>
//#include <cstring>
//#include <algorithm>
//#define pii pair<int,int>
//
//using namespace std;
//
//int N, Q;
//vector<vector<pii>> edge;
//
//int main() {
//	cin >> N >> Q;
//	edge.resize(N + 1);
//	for (int i = 0;i < N - 1;i++) {
//		int p, q, r;
//		cin >> p >> q >> r;
//		edge[p].emplace_back(q, r);
//		edge[q].emplace_back(p, r);
//	}
//
//	for (int i = 0;i < Q;i++) {
//		vector<bool> visited(N + 1, false);
//		int k, v, ans = 0;
//		cin >> k >> v;
//		queue<pii> q;
//		visited[v] = 1;
//		for (int j = 0;j < edge[v].size();j++) {
//			if (k > edge[v][j].second)
//				continue;
//			q.push(edge[v][j]);
//			visited[edge[v][j].first] = 1;
//			ans++;
//		}
//		while (!q.empty()) {
//			pii cur = q.front();
//			q.pop();
//			for (int j = 0;j < edge[cur.first].size();j++) {
//				pii next = edge[cur.first][j];
//				if (visited[next.first] || next.second < k)
//					continue;
//				int mn = min(cur.second, next.second);
//				visited[next.first] = 1;
//				q.push({ next.first, mn });
//				ans++;
//			}
//		}
//		cout << ans << endl;
//	}
//}