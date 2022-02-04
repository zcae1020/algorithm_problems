#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, ans = 0, visited[101] = { 0 };
vector<vector<int>> v;
queue<int> q;

int main() {
	cin >> N >> M;
	v.resize(N + 1);
	for (int i = 0;i < M;i++) {
		int a, b;
		cin >> a >> b;
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	q.push(1);
	visited[1] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0;i < v[cur].size();i++) {
			int next = v[cur][i];
			if (visited[next])
				continue;
			ans++;
			visited[next] = 1;
			q.push(next);
		}
	}
	cout << ans;
}