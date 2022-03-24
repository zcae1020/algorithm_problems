#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int T, N, K, W;
vector<int> D, indegree, startTime;
vector<vector<int>> edge;

void Input() {
	cin >> N >> K;

	D.clear();
	indegree.clear();
	startTime.clear();
	edge.clear();

	D.resize(N + 1);
	indegree.resize(N + 1);
	startTime.resize(N + 1);
	edge.resize(N + 1);

	for (int i = 1; i <= N; i++)
		cin >> D[i];

	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		indegree[b]++;
	}

	cin >> W;
}

void BFS() {
	queue<int> q;
	for (int i = 1; i <= N; i++)
		if (indegree[i] == 0) q.push(i);

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		if (cur == W) return;

		for (auto next : edge[cur]) {
			
			startTime[next] = max(startTime[next], startTime[cur] + D[cur]);

			if (--indegree[next] == 0) q.push(next);
		}
	}
}

void Solution() {
	BFS();
	cout << startTime[W] + D[W] << endl;
}

int main() {
	ios::sync_with_stdio(NULL);

	cin >> T;
	while (T--) {
		Input();
		Solution();
	}
}