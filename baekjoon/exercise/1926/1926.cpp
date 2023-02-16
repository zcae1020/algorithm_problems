#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n, m, cnt, mx;
bool MAP[500][500], visited[500][500];

int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

void bfs(pii start) {
    int s = 0;
    queue<pii> q;

    q.push(start);
    visited[start.fs][start.sd] = 1;

    while (!q.empty()) {
        pii cur = q.front();
        s++;

        q.pop();

        for (int i = 0; i < 4; i++) {
            pii next = {cur.fs + dx[i], cur.sd + dy[i]};

            if (next.fs >= 0 && next.sd >= 0 && next.fs < n && next.sd < m &&
                MAP[next.fs][next.sd] && !visited[next.fs][next.sd]) {
                q.push(next);
                visited[next.fs][next.sd] = 1;
            }
        }
    }

    mx = max(mx, s);
}

void Solution() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> MAP[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (MAP[i][j] && !visited[i][j]) {
                cnt++;
                bfs({i, j});
            }
        }
    }

    cout << cnt << '\n' << mx;
}

int main() {
    FASTIO
    Solution();
}