//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//int N, M;
//vector<vector<int>> edge;
//vector<int> indegree;
//
//void Input() {
//	cin >> N >> M;
//
//	edge.resize(N + 1);
//	indegree.resize(N + 1);
//
//	for (int i = 0; i < M; i++) {
//		int a, b;
//		cin >> a >> b;
//
//		edge[a].push_back(b);
//		indegree[b]++;
//	}
//}
//
//void BFS() {
//	queue<int> q;
//	
//	for (int i = 1; i <= N; i++)
//		if (indegree[i] == 0) q.push(i);
//
//	while (!q.empty()) {
//		int cur = q.front(); q.pop();
//
//		cout << cur << ' ';
//
//		for (auto next : edge[cur]) {
//			if (--indegree[next] == 0) q.push(next);
//		}
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(NULL);
//	cin.tie(0), cout.tie(0);
//
//	Input();
//	BFS();
//}