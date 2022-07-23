#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

const int maxn = 500;

bool visited[maxn][maxn];
int n, m[maxn][maxn], dp[maxn][maxn], ans;

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

int dfs(pii cur)
{
    if (dp[cur.x][cur.y] != -1)
        return dp[cur.x][cur.y];

    int mx = 0;
    visited[cur.x][cur.y] = 1;

    for (int i = 0; i < 4; i++)
    {
        pii next = {cur.x + dx[i], cur.y + dy[i]};
        if (next.x < 0 || next.y < 0 || next.x >= n || next.y >= n ||
            visited[next.x][next.y] || m[cur.x][cur.y] >= m[next.x][next.y])
            continue;
        mx = max(mx, dfs(next));
    }

    visited[cur.x][cur.y] = 0;
    return dp[cur.x][cur.y] = mx + 1;
}

void Solution()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
            dp[i][j] = -1;
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dfs({i, j});

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans = max(ans, dp[i][j]);

    cout << ans;
}

int main()
{
    FASTIO
    Solution();
}