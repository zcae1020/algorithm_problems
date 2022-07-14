#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

int n, visited[100][100], ans[2];
string s[100];

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

void Solution()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                ans[0]++;
                queue<pii> q;
                q.push({i, j});
                visited[i][j] = 1;
                while (q.size())
                {
                    pii cur = q.front();
                    q.pop();

                    for (int k = 0; k < 4; k++)
                    {
                        int nx = cur.x + dx[k], ny = cur.y + dy[k];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= n || visited[nx][ny])
                            continue;
                        if (s[cur.x][cur.y] != s[nx][ny])
                            continue;

                        q.push({nx, ny});
                        visited[nx][ny] = 1;
                    }
                }
            }
        }
    }

    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                ans[1]++;
                queue<pii> q;
                q.push({i, j});
                visited[i][j] = 1;
                while (q.size())
                {
                    pii cur = q.front();
                    q.pop();

                    for (int k = 0; k < 4; k++)
                    {
                        int nx = cur.first + dx[k], ny = cur.second + dy[k];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= n || visited[nx][ny])
                            continue;
                        if ((s[cur.x][cur.y] != s[nx][ny]) && (s[cur.x][cur.y] == 'B' || s[nx][ny] == 'B'))
                            continue;

                        q.push({nx, ny});
                        visited[nx][ny] = 1;
                    }
                }
            }
        }
    }

    cout << ans[0] << ' ' << ans[1];
}

int main()
{
    FASTIO
    Solution();
}