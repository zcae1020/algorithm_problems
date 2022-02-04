#include <iostream>
#include <vector>
#include <queue>
#define pii pair<int,int>

using namespace std;

int n, m, a, b, visited[101] = { 0 };
vector<vector<int>> v;
queue<pii> q;

int main() {
	cin >> n >> a >> b >> m;
	v.resize(n + 1);
	for (int i = 0;i < m;i++) {
		int x, y;
		cin >> x >> y;
		v[x].emplace_back(y);
		v[y].emplace_back(x);
	}

	q.push({ 0, a });
	visited[a] = 1;
	while (!q.empty()) {
		pii cur = q.front();
		q.pop();
		for (int i = 0;i < v[cur.second].size();i++) {
			pii next = { cur.first + 1,v[cur.second][i] };
			if (next.second == b) {
				cout << next.first;
				exit(0);
			}
			if (visited[next.second])
				continue;
			q.push(next);
			visited[next.second] = 1;
		}
	}
	cout << -1;
}