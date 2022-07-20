#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

int n, m, a[30][30], b[30][30];
bool v[30][30];

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

void Solution()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> b[i][j];

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] != b[i][j] && v[i][j] == 0)
            {
                if (++cnt > 1)
                {
                    cout << "NO";
                    return;
                }

                queue<pii> q;
                q.push({i, j});
                v[i][j] = 1;

                while (q.size())
                {
                    pii cur = q.front();
                    q.pop();

                    for (int k = 0; k < 4; k++)
                    {
                        pii next = {cur.first + dx[k], cur.second + dy[k]};
                        if (next.first < 0 || next.second < 0 || next.first >= n || next.second >= m ||
                            v[next.first][next.second] ||
                            a[next.first][next.second] != a[cur.first][cur.second])
                            continue;

                        if (b[i][j] != b[next.first][next.second])
                        {
                            cout << "NO";
                            return;
                        }

                        v[next.first][next.second] = 1;
                        q.push(next);
                    }
                }
            }
        }
    }

    cout << "YES";
}

int main()
{
    FASTIO
    Solution();
}