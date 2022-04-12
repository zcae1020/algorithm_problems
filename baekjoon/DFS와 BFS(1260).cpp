//#include <iostream>
//#include <vector>
//#include <queue>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//int N, M, V, visited[1001] = { 0 };
//vector<int> v[1001];
//
//void dfs(int cur) {
//	cout << cur << ' ';
//	visited[cur] = 1;
//	for (int i = 0;i < v[cur].size();i++) {
//		int next = v[cur][i];
//		if (visited[next])
//			continue;
//		dfs(next);
//	}
//}
//
//void bfs() {
//	queue<int> q;
//	q.push(V);
//
//	while (!q.empty()) {
//		int cur = q.front();
//		q.pop();
//		if (visited[cur])
//			continue;
//		visited[cur] = 1;
//		cout << cur << ' ';
//		for (int i = 0;i < v[cur].size();i++) {
//			int next = v[cur][i];
//			if (visited[next])
//				continue;
//			q.push(next);
//		}
//	}
//}
//
//int main() {
//	cin >> N >> M >> V;
//	for (int i = 0;i < M;i++) {
//		int a, b;
//		cin >> a >> b;
//		v[a].emplace_back(b);
//		v[b].emplace_back(a);
//	}
//
//	for (int i = 0;i < N;i++) {
//		if (v[i].size() > 1)
//			sort(v[i].begin(), v[i].end());
//	}
//	dfs(V);
//	cout << endl;
//	memset(visited, 0, sizeof(visited));
//	bfs();
//}