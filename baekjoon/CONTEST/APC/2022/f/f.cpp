#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n, PX, PY;
char m[1000][1000];
bool visited[1000][1000];

int ans = 1e9;

int px[8] = {0, 0, 1, 1, 1, -1, -1, -1}, py[8] = {1, -1, 0, 1, -1, 0, 1, -1};
int lx[4] = {0, 0, 1, -1}, ly[4] = {1, -1, 0, 0};
int dx[4] = {1, 1, -1, -1}, dy[4] = {-1, 1, -1, 1};
int NX[8] = {-2, -2, -1, -1, 1, 1, 2, 2}, NY[8] = {1, -1, 2, -2, 2, -2, 1, -1};

bool valid(pii p)
{
    return p.first >= 0 && p.first < n && p.second >= 0 && p.second < n && !visited[p.first][p.second];
}

void bfs()
{
    queue<pair<pair<char, int>, pii>> q;
    set<int> ssss;
    q.push({{'P', 0}, {PX, PY}});
    visited[PX][PY] = 1;
    while (!q.empty())
    {
        char target = q.front().first.first;
        int cnt = q.front().first.second;
        pii cur = q.front().second;
        q.pop();

        if(target == 'K') {
            ans = min(ans, cnt);
            continue;
        }

        switch (target)
        {
        case 'P':
            for (int i = 0; i < 8; i++)
            {
                pii next = {cur.fs + px[i], cur.sd + py[i]};
                if (valid(next))
                {
                    if (m[next.first][next.second] != '0')
                    {
                        visited[next.first][next.second] = true;
                        q.push({{m[next.first][next.second], cnt + 1}, next});
                    }
                }
            }
            break;
        case 'Q':
            for (int j = 0; j < 8; j++)
            {
                for (int i = 1; i < n; i++)
                {
                    pii next = {cur.fs + px[j] * i, cur.sd + py[j] * i};
                    if (valid(next))
                    {
                        if (m[next.first][next.second] != '0')
                        {
                            visited[next.first][next.second] = true;
                            q.push({{m[next.first][next.second], cnt + i}, next});
                            break;
                        }
                    }
                    else
                        break;
                    ;
                }
            }
            break;
        case 'N':
            for (int i = 0; i < 8; i++)
            {
                pii next = {cur.fs + NX[i], cur.sd + NY[i]};
                if (valid(next))
                {
                    if (m[next.first][next.second] != '0')
                    {
                        visited[next.first][next.second] = true;
                        q.push({{m[next.first][next.second], cnt + 2}, next});
                    }
                }
            }
            break;
        case 'R':
            for (int j = 0; j < 4; j++)
            {
                for (int i = 1; i < n; i++)
                {
                    pii next = {cur.fs + lx[j] * i, cur.sd + ly[j] * i};
                    if (valid(next))
                    {
                        if (m[next.first][next.second] != '0')
                        {
                            visited[next.first][next.second] = true;
                            q.push({{m[next.first][next.second], cnt + i}, next});
                            break;
                        }
                    }
                    else
                        break;
                }
            }
            break;
        case 'B':
            for (int j = 0; j < 8; j++)
            {
                for (int i = 1; i < n; i++)
                {
                    pii next = {cur.fs + dx[j] * i, cur.sd + dy[j] * i};
                    if (valid(next))
                    {
                        if (m[next.first][next.second] != '0')
                        {
                            visited[next.first][next.second] = true;
                            q.push({{m[next.first][next.second], cnt + i}, next});
                            break;
                        }
                    }
                    else
                        break;
                }
            }
            break;
        }
    }
}

void Solution()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
            if (m[i][j] == 'P')
            {
                PX = i;
                PY = j;
            }
        }

    visited[PX][PY] = true;
    bfs();

    if (ans == 1e9)
    {
        cout << -1;
    }
    else
        cout << ans;
}

int main()
{
    FASTIO
    Solution();
}