#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n, m, a, b, ans;
vector<int> v[2][501];
queue<pii> q;

void Solution() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[0][a].push_back(b);
        v[1][b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        bool visited[501] = {0};
        int cnt = 1;
        visited[i] = 1;

        for (int j = 0; j < 2; j++) {
            for (auto next : v[j][i]) {
                q.push({j, next});
                visited[next] = 1;
            }
        }

        while (!q.empty()) {
            int type = q.front().fs;
            int cur = q.front().sd;
            q.pop();
            cnt++;

            for (auto next : v[type][cur]) {
                if (!visited[next]) {
                    q.push({type, next});
                    visited[next] = 1;
                }
            }
        }

        ans += cnt == n;
    }

    cout << ans;
}

int main() {
    FASTIO
    Solution();
}
