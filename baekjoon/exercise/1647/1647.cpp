#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

const int maxn = 1e5 + 1;
priority_queue<pair<int, pii>> pq;
int n, m, par[maxn], mx, ans;

int find(int u) { return par[u] == u ? u : par[u] = find(par[u]); }

bool merge(int u, int v) {
    u = find(u), v = find(v);
    par[u] = v;

    return u != v;
}

void Solution() {
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        par[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        pq.push({-c, {a, b}});
    }

    while (!pq.empty()) {
        int cost = -pq.top().fs;
        pii p = pq.top().sd;
        pq.pop();

        if (merge(p.fs, p.sd)) {
            ans += cost;
            mx = max(mx, cost);
        }
    }

    cout << ans - mx;
}

int main() {
    FASTIO
    Solution();
}