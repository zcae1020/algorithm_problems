#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

const int maxn = 125;
int n, MAP[maxn][maxn], dp[maxn][maxn];
bool visited[maxn][maxn];

int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

bool check(pii p) {
    return p.fs >= 0 && p.sd >= 0 && p.fs < n && p.sd < n &&
           dp[p.fs][p.sd] == -1;
}

void bfs() {
    priority_queue<pair<int, pii>> pq;

    pq.push({{-MAP[0][0]}, {0, 0}});
    dp[0][0] = MAP[0][0];
    while (!pq.empty()) {
        pii cur = pq.top().sd;
        int val = -pq.top().fs;
        pq.pop();

        for (int i = 0; i < 4; i++) {
            pii next = {cur.fs + dx[i], cur.sd + dy[i]};
            if (check(next)) {
                pq.push({-(val + MAP[next.fs][next.sd]), next});
                dp[next.fs][next.sd] = val + MAP[next.fs][next.sd];
            }
        }
    }
}

void Solution() {
    int t = 1;
    while (t) {
        cin >> n;

        memset(dp, -1, sizeof(dp));

        if (n == 0) {
            break;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> MAP[i][j];
            }
        }

        bfs();

        cout << "Problem " << t++ << ": " << dp[n - 1][n - 1] << '\n';
    }
}

int main() {
    FASTIO
    Solution();
}