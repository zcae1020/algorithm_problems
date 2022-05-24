#include <iostream>
#include <queue>
#include <cstring>
#define pii pair<int, int>

using namespace std;

bool map[50][50], visit[50][50];
int N, M, K;

void Input()
{
    memset(map, 0, sizeof(map));
    memset(visit, 0, sizeof(visit));

    cin >> M >> N >> K;

    for (int i = 0; i < K; i++)
    {
        int a, b;
        cin >> a >> b;
        map[b][a] = 1;
    }
}

void Solution()
{
    int ans = 0;
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
    queue<pii> q;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!visit[i][j] && map[i][j])
            {
                ans++;
                q.push({i, j});
                visit[i][j] = 1;
                while (!q.empty())
                {
                    pii cur = q.front();
                    q.pop();

                    for (int i = 0; i < 4; i++)
                    {
                        int nx = cur.first + dx[i], ny = cur.second + dy[i];
                        if (nx < 0 || ny < 0 || nx >= N || ny >= M || visit[nx][ny] || !map[nx][ny])
                            continue;

                        visit[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--)
    {
        Input();
        Solution();
    }
}