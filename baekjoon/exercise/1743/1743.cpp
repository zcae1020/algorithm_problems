#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n, m, k, r, c, ans;
bool MAP[100][100], visited[100][100];

int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

bool check(pii p) {
    return p.fs >= 0 && p.sd >= 0 && p.fs < n && p.sd < m &&
           !visited[p.fs][p.sd] && MAP[p.fs][p.sd];
}

int bfs(int x, int y) {
    int ret = 1;
    queue<pii> q;
    q.push({x, y});
    visited[x][y] = 1;

    while (!q.empty()) {
        pii cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            pii next = {cur.fs + dx[i], cur.sd + dy[i]};

            if (check(next)) {
                ret++;
                q.push(next);
                visited[next.fs][next.sd] = 1;
            }
        }
    }

    return ret;
}

void Solution() {
    cin >> n >> m >> k;
    while (k--) {
        cin >> r >> c;
        MAP[r - 1][c - 1] = true;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (MAP[i][j] && !visited[i][j]) {
                visited[i][j];
                ans = max(ans, bfs(i, j));
            }
        }
    }
    cout << ans;
}

int main() {
    FASTIO
    Solution();
}