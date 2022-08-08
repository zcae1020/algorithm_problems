#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

const int maxn = 2010;

int n, arr[1000][4], ans;
bool m[maxn][maxn], visited[maxn][maxn];

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

void bfs(pii p)
{
    queue<pii> q;
    q.push(p);
    visited[p.x][p.y] = 1;
    while (q.size())
    {
        pii cur = q.front();
        q.pop();
        for (int j = 0; j < 4; j++)
        {
            int nx = cur.x + dx[j], ny = cur.y + dy[j];
            if (nx < 0 || ny < 0 || nx > 2000 || ny > 2000 || visited[nx][ny] || !m[nx][ny])
                continue;

            q.push({nx, ny});
            visited[nx][ny] = 1;
        }
    }
}

void Solution()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> arr[i][j];
            arr[i][j] += 500;
            arr[i][j] *= 2;
        }

        int x1 = arr[i][0], x2 = arr[i][2], y1 = arr[i][1], y2 = arr[i][3];

        for (int j = x1; j <= x2; j++)
        {
            m[j][y1] = 1;
            m[j][y2] = 1;
        }
        for (int j = y1; j <= y2; j++)
        {
            m[x1][j] = 1;
            m[x2][j] = 1;
        }
    }

    if (m[1000][1000])
        ans--;

    for (int i = 0; i < n; i++)
    {
        if (!visited[arr[i][0]][arr[i][1]])
        {
            ans++;
            bfs({arr[i][0], arr[i][1]});
        }
    }

    cout << ans;
}

int main()
{
    FASTIO
    Solution();
}