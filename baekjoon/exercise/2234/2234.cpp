#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int N, M, wall[50][50], area[50][50], color;
int areaSize[3000];

unordered_set<int> conn[3000];

int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};

void Solution()
{
    cin >> M >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> wall[i][j];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!area[i][j])
            {
                int cnt = 1;

                queue<pii> q;
                q.push({i, j});
                area[i][j] = ++color;

                while (!q.empty())
                {
                    pii cur = q.front();
                    q.pop();

                    for (int i = 0; i < 4; i++)
                    {
                        pii next = {cur.fs + dx[i], cur.sd + dy[i]};
                        if (!(wall[cur.fs][cur.sd] & (1 << i)) && !area[next.fs][next.sd])
                        {
                            area[next.fs][next.sd] = color;
                            cnt++;
                            q.push(next);
                        }
                        else if (wall[cur.fs][cur.sd] & (1 << i) && area[next.fs][next.sd] && area[next.fs][next.sd] != area[cur.fs][cur.sd])
                        {
                            conn[color].insert(area[next.fs][next.sd]);
                        }
                    }
                }

                areaSize[color] = cnt;
            }
        }
    }

    int mx = 0, mxConn = 0;
    for (int i = 1; i <= color; i++)
        mx = max(mx, areaSize[i]);

    for (int i = 1; i <= color; i++)
    {
        for (auto a : conn[i])
        {
            mxConn = max(mxConn, areaSize[i] + areaSize[a]);
        }
    }

    cout << color << '\n'
         << mx << '\n'
         << mxConn;
}

int main()
{
    FASTIO
    Solution();
}