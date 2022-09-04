#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int N, M;
string m[100];
int color[100][100];

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

bool check(pii p)
{
    return (p.fs >= 0 && p.sd >= 0 && p.fs < N && p.sd < M);
}

bool bfs(int cidx)
{
    bool visited[100][100] = {0};
    queue<pii> q;
    q.push({0, 0});
    visited[0][0] = 1;

    while (!q.empty())
    {
        pii cur = q.front();
        q.pop();

        if (cur == make_pair(N - 1, M - 1))
            return true;

        for (int i = 0; i < 4; i++)
        {
            pii next = {cur.fs + dx[i], cur.sd + dy[i]};

            if (check(next) && !visited[next.fs][next.sd])
            {
                if (color[next.fs][next.sd] == -1)
                    color[next.fs][next.sd] = cidx + 1;
                else if (color[next.fs][next.sd] <= cidx)
                    q.push(next);
                visited[next.fs][next.sd] = 1;
            }
        }
    }

    return false;
}

void Solution()
{
    memset(color, -1, sizeof(color));

    cin >> M >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> m[i];
        for (int j = 0; j < M; j++)
            if (m[i][j] == '0')
                color[i][j] = 0;
    }

    for (int i = 0; i < 300; i++)
    {
        if (bfs(i))
        {
            cout << i;
            break;
        }
    }
}

int main()
{
    FASTIO
    Solution();
}