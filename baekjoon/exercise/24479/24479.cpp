#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n, m, r, cnt = 1, visited[100001];
vector<int> v[100001];

void dfs(int cur) {
    visited[cur] = cnt++;
    for (auto next : v[cur]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}

void Solution() {
    cin >> n >> m >> r;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        sort(v[i].begin(), v[i].end());
    }

    dfs(r);

    for (int i = 1; i <= n; i++) {
        cout << visited[i] << '\n';
    }
}

int main() {
    FASTIO
    Solution();
}
