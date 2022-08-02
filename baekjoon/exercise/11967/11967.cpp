#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

int N, M, ans = 1;
bool light[101][101], visited[101][101];
map<pii, vector<pii>> edge;
queue<pii> q;

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

bool check(pii p)
{
    return (p.x > 0 && p.y > 0 && p.x <= N && p.y <= N);
}

void Solution()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        edge[{a, b}].push_back({c, d});
    }

    q.push({1, 1});
    light[1][1] = 1;
    visited[1][1] = 1;

    while (q.size())
    {
        pii cur = q.front();
        q.pop();

        for (auto p : edge[cur])
        {
            if (!light[p.x][p.y])
                ans++;
            light[p.x][p.y] = 1;

            if (!visited[p.x][p.y])
            {
                for (int i = 0; i < 4; i++)
                {
                    pii next = {p.x + dx[i], p.y + dy[i]};
                    if (visited[next.x][next.y])
                    {
                        q.push(p);
                        visited[p.x][p.y] = 1;
                        break;
                    }
                }
            }
        }

        for (int i = 0; i < 4; i++)
        {
            pii next = {cur.x + dx[i], cur.y + dy[i]};
            if (check(next) && light[next.x][next.y] && !visited[next.x][next.y])
            {
                q.push(next);
                visited[next.x][next.y] = 1;
            }
        }
    }

    cout << ans;
}

int main()
{
    FASTIO
    Solution();
}