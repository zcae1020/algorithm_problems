//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//int T, N, M;
//vector<vector<int>> graph;
//vector<int> indegree, order;
//bool isQuestionmark;
//
//void Input() {
//	cin >> N;
//	
//	isQuestionmark = false;
//
//	graph.clear();
//	indegree.clear();
//
//	graph.resize(N + 1);
//	indegree.resize(N + 1);
//
//	vector<int> t;
//	
//	for (int i = 0; i < N; i++) {
//		int a;
//		cin >> a;
//		t.push_back(a);
//	}
//
//	for (int i = 0; i < N; i++) {
//		for (int j = i + 1; j < N; j++) {
//			graph[t[i]].push_back(t[j]);
//			indegree[t[j]]++;
//		}
//	}
//
//	cin >> M;
//	
//	for (int i = 0; i < M; i++) {
//		int t1, t2;
//		bool isOrder = false;
//		cin >> t1 >> t2;
//
//		for (int j = 0; j < graph[t2].size(); j++) {
//			if (graph[t2][j] == t1) {
//				isOrder = true;
//				graph[t2].erase(graph[t2].begin() + j);
//				indegree[t1]--;
//				graph[t1].push_back(t2);
//				indegree[t2]++;
//				break;
//			}
//		}
//		if (isOrder == false) {
//			for (int j = 0; j < graph[t1].size(); j++) {
//				if (graph[t1][j] == t2) {
//					isOrder = true;
//					graph[t1].erase(graph[t1].begin() + j);
//					indegree[t2]--;
//					graph[t2].push_back(t1);
//					indegree[t1]++;
//					break;
//				}
//			}
//		}
//	}
//}
//
//void BFS() {
//	queue<int> q;
//	
//	order.clear();
//
//	for (int i = 1; i <= N; i++) {
//		if (indegree[i] == 0)
//			q.push(i);
//	}
//
//	while (!q.empty()) {
//		if (q.size() > 1) {
//			isQuestionmark = true;
//			return;
//		}
//
//		int cur = q.front(); q.pop();
//
//		order.push_back(cur);
//
//		for (auto a : graph[cur]) {
//			if (--indegree[a] == 0) {
//				q.push(a);
//			}
//		}
//	}
//}
//
//void Solution() {
//	BFS();
//
//	if (order.size() < N - 1) cout << "IMPOSSIBLE" << endl;
//	else if (isQuestionmark) cout << "?" << endl;
//	else {
//		for (auto a : order)
//			cout << a << ' ';
//		cout << endl;
//	}
//}
//
//int main() {
//	cin >> T;
//
//	while (T--) {
//		Input();
//		Solution();
//	}
//}