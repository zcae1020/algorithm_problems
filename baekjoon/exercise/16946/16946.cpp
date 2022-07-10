#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

int n, m, MAP[1001][1001], ans[1001][1001], visited[1001][1001];
string M[1001];
vector<int> CNT;

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

void Solution()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> M[i];

    int idx = -1, cnt;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && M[i][j] == '0')
            {
                idx++;
                cnt = 0;
                queue<pii> q;
                q.push({i, j});
                visited[i][j] = 1;

                while (q.size())
                {
                    pii c = q.front();
                    q.pop();

                    MAP[c.first][c.second] = idx;
                    cnt++;

                    for (int k = 0; k < 4; k++)
                    {
                        int nx = c.first + dx[k], ny = c.second + dy[k];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny] || M[nx][ny] == '1')
                            continue;

                        q.push({nx, ny});
                        visited[nx][ny] = 1;
                    }
                }

                CNT.push_back(cnt);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (M[i][j] == '1')
            {
                unordered_set<int> s;
                ans[i][j] = 1;
                for (int k = 0; k < 4; k++)
                {
                    int nx = i + dx[k], ny = j + dy[k];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m || M[nx][ny] == '1' || s.count(MAP[nx][ny]))
                        continue;

                    s.insert(MAP[nx][ny]);
                    ans[i][j] += CNT[MAP[nx][ny]];
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << ans[i][j] % 10;
        cout << '\n';
    }
}

int main()
{
    FASTIO
    Solution();
}