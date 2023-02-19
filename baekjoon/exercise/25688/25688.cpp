#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

const int n = 5;

int r, c, m[5][5];
bool visited[5][5][1 << 6];
queue<pair<pii, pii>> q;

int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

bool check(pii p) {
    return p.fs >= 0 && p.sd >= 0 && p.fs < n && p.sd < n && m[p.fs][p.sd] >= 0;
}

int bfs() {
    q.push({{r, c}, {0, 0}});

    while (!q.empty()) {
        pii cur = q.front().fs;
        int cnt = q.front().sd.fs;
        int bm = q.front().sd.sd;
        q.pop();

        if (bm == (1 << 6) - 1) {
            return cnt;
        }

        for (int i = 0; i < 4; i++) {
            pii next = {cur.fs + dx[i], cur.sd + dy[i]};
            int nbm = m[next.fs][next.sd] > 0 ? bm | (1 << (m[next.fs][next.sd] - 1)) : bm;

            if (check(next) && !visited[next.fs][next.sd][nbm]) {
                visited[next.fs][next.sd][nbm] = 1;
                q.push({next, {cnt + 1, nbm}});
            }
        }
    }

    return -1;
}

void Solution() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }
    cin >> r >> c;

    cout << bfs();
}

int main() {
    FASTIO
    Solution();
}