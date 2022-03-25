#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> indegree, order;
vector<vector<int>> graph;
int N, M;

void Input() {
	cin >> N >> M;

	indegree.resize(N + 1);
	graph.resize(N + 1);

	for (int i = 0; i < M; i++) {
		vector<int> tmp;
		int L;
		cin >> L;
		for (int j = 0; j < L; j++) {
			int a;
			cin >> a;
			tmp.push_back(a);
		}
		for (int j = 0; j < tmp.size() - 1; j++) {
			graph[tmp[j]].push_back(tmp[j + 1]);
			indegree[tmp[j + 1]]++;
		}
	}
}

void BFS() {
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		order.push_back(cur);

		for (auto a : graph[cur]) {
			if (--indegree[a] == 0)
				q.push(a);
		}
	}
}

bool allVisit() {
	for (int i = 1; i <= N; i++)
		if (indegree[i]) return false;
	return true;
}

void Solution() {
	BFS();
	if (allVisit()) {
		for (auto a : order)
			cout << a << endl;
	}
	else
		cout << 0 << endl;
}

int main() {
	ios::sync_with_stdio(0);

	Input();
	Solution();
}