#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n, ans;
string MAP[50];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

bool bfs() {
    bool visited[50][50] = {0};
    queue<pii> q;
    q.push({0, 0});
    visited[0][0] = 1;

    while (!q.empty()) {
        pii cur = q.front();
        q.pop();

        if (cur == make_pair(n - 1, n - 1)) {
            return false;
        }

        for (int i = 0; i < 4; i++) {
            pii next = {cur.fs + dx[i], cur.sd + dy[i]};

            if (next.fs >= 0 && next.sd >= 0 && next.fs < n && next.sd < n &&
                !visited[next.fs][next.sd]) {
                visited[next.fs][next.sd] = 1;
                if (MAP[next.fs][next.sd] == '0') {
                    MAP[next.fs][next.sd] = '1';
                    continue;
                }
                q.push(next);
            }
        }
    }

    ans++;
    return true;
}

void Solution() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> MAP[i];
    }

    while (bfs());

    cout << ans;
}

int main() {
    FASTIO
    Solution();
}
