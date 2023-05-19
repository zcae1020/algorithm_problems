#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n, m, ans;
string MAP[50];
bool visited[50][50];

int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

void bfs(pii p) {
    char c = MAP[p.fs][p.sd];
    queue<pii> q;
    q.push(p);
    visited[p.fs][p.sd] = 1;

    while (!q.empty()) {
        pii cur = q.front();
        q.pop();

        for (int i = (c == '-' ? 0 : 2); i < (c == '-' ? 2 : 4); i++) {
            pii next = {cur.fs + dx[i], cur.sd + dy[i]};

            if (next.fs >= 0 && next.sd >= 0 && next.fs < n && next.sd < m &&
                !visited[next.fs][next.sd] && MAP[next.fs][next.sd] == c) {
                q.push(next);
                visited[next.fs][next.sd] = 1;
            }
        }
    }
}

void Solution() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> MAP[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                bfs({i, j});
                ans++;
            }
        }
    }

    cout << ans;
}

int main() {
    FASTIO
    Solution();
}