#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n, m, ans, MAP[100][100], outerAir[100][100];
vector<pii> willRemove;

int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

bool hasCheeze() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (MAP[i][j]) {
                return true;
            }
        }
    }
    return false;
}

bool check(pii p) {
    return p.fs >= 0 && p.sd >= 0 && p.fs < n && p.sd < m && !MAP[p.fs][p.sd];
}

void bfs() {
    queue<pii> q;
    bool visited[100][100] = {0};

    q.push({0, 0});
    visited[0][0] = 1;

    while (!q.empty()) {
        pii cur = q.front();
        q.pop();

        outerAir[cur.fs][cur.sd] = 1;

        for (int i = 0; i < 4; i++) {
            pii next = {cur.fs + dx[i], cur.sd + dy[i]};

            if (check(next) && !visited[next.fs][next.sd]) {
                q.push(next);
                visited[next.fs][next.sd] = 1;
            }
        }
    }
}

void Solution() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> MAP[i][j];
        }
    }

    while (hasCheeze()) {
        ans++;

        bfs();

        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (MAP[i][j]) {
                    int cnt = 0;
                    for (int k = 0; k < 4; k++) {
                        cnt += outerAir[i + dx[k]][j + dy[k]];
                    }

                    if (cnt > 1) {
                        willRemove.push_back({i, j});
                    }
                }
            }
        }

        for (auto p : willRemove) {
            MAP[p.fs][p.sd] = 0;
        }

        willRemove.clear();
    }

    cout << ans;
}

int main() {
    FASTIO
    Solution();
}