#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pii pair<int,int>

using namespace std;

int N, M, SC, EC, briAns;
vector<vector<pii>> edge;
vector<vector<int>> route, route2;
vector<int> indegree, ans;
vector<bool> bri;

void Input() {
	cin >> N >> M;

	edge.resize(N + 1);
	indegree.resize(N + 1);
	route.resize(N + 1);
	route2.resize(N + 1);
	ans.resize(N + 1);
	bri.resize(M);

	for (int i = 0; i < M; i++) {
		int s, e, d;
		cin >> s >> e >> d;
		edge[s].push_back({ e,d });
		indegree[e]++;
	}

	cin >> SC >> EC;
}

void BFS() {
	queue<int> q;

	for (int i = 1; i <= N; i++) if (indegree[i] == 0) q.push(i);

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		for (auto a : edge[cur]) {
			if (--indegree[a.first] == 0) q.push(a.first);

			if (ans[a.first] < ans[cur] + a.second) {
				ans[a.first] = ans[cur] + a.second;
				route[a.first].clear();
			}

			if(ans[a.first] == ans[cur] + a.second)
				route[a.first].push_back(cur);
		}
	}
}

void briBFS() {
	queue<int> q;
	q.push(EC);

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (auto a : route[cur]) {
			bool flag = true;

			for (auto b : route2[cur]) {
				if (a == b) {
					flag = false;
					break;
				}
			}

			if (flag) {
				briAns++;
				route2[cur].push_back(a);
				q.push(a);
			}
		}
	}
}

void Solution() {
	BFS();
	briBFS();
	cout << ans[EC] << '\n' << briAns;
}

int main() {
	Input();
	Solution();
}