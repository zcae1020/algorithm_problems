#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> graph;
vector<int> indegree;

void Input() {
	cin >> N >> M;

	graph.resize(N + 1);
	indegree.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		indegree[b]++;
		graph[a].push_back(b);
	}
}

void BFS() {
	queue<int> q;
	vector<bool> visit;

	visit.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			q.push(i);
			visit[i] = true;
			break;
		}
	}

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		cout << cur << ' ';

		for (auto a : graph[cur]) indegree[a]--;
		for (int i = 1; i <= N; i++) {
			if (visit[i] == false && indegree[i] == 0) {
				q.push(i);
				visit[i] = true;
				break;
			}
		}
	}
}

void Solution() {
	BFS();
}

int main() {
	Input();
	Solution();
}