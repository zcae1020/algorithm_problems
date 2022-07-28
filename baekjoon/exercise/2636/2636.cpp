#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

int r, c, m[102][102], cheeze, ans, t = 1;
bool visited[102][102];

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

void Solution()
{
    cin >> r >> c;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
        {
            cin >> m[i][j];
            if (m[i][j])
                cheeze++;
        }

    while (cheeze)
    {
        queue<pii> q;
        memset(visited, 0, sizeof(visited));
        q.push({0, 0});
        t++;
        ans = cheeze;
        while (q.size())
        {
            pii cur = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = cur.x + dx[i], ny = cur.y + dy[i];

                if (nx < 0 || ny < 0 || nx > r || ny > c || visited[nx][ny] || m[nx][ny] == t)
                    continue;

                if (m[nx][ny] == 1)
                {
                    m[nx][ny] = t;
                    cheeze--;
                }
                else
                    q.push({nx, ny});
                visited[nx][ny] = 1;
            }
        }
    }

    cout << t - 1 << '\n'
         << ans;
}

int main()
{
    FASTIO
    Solution();
}