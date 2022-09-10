#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

pii s;
int N, M, xcnt;
string m[50];
bool visited[50][50][1 << 5];

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

void Solution()
{
    cin >> M >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> m[i];
        for (int j = 0; j < M; j++)
        {
            if (m[i][j] == 'X')
                m[i][j] = '0' + xcnt++;
            if (m[i][j] == 'S')
                s = {i, j};
        }
    }

    queue<pair<pii, pii>> q;
    q.push({s, {0, 0}});
    visited[s.fs][s.sd][0] = 1;

    while (!q.empty())
    {
        pii cur = q.front().fs;
        int cnt = q.front().sd.fs;
        int v = q.front().sd.sd;
        q.pop();

        if (m[cur.fs][cur.sd] == 'E')
        {
            if (v == ((1 << xcnt) - 1))
                cout << cnt;
            continue;
        }

        for (int i = 0; i < 4; i++)
        {
            pii next = {cur.fs + dx[i], cur.sd + dy[i]};
            int mnext = m[next.fs][next.sd] - '0';
            int nv = (mnext >= 0 && mnext < 5) ? v | (1 << mnext) : v;

            if (m[next.fs][next.sd] != '#' && !visited[next.fs][next.sd][nv])
            {
                q.push({next, {cnt + 1, nv}});
                visited[next.fs][next.sd][nv] = 1;
            }
        }
    }
}

int main()
{
    FASTIO
    Solution();
}