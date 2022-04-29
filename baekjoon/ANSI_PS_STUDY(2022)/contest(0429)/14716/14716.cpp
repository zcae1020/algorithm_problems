#include <iostream>
#include <queue>

using namespace std;

int M, N, map[250][250], ans;
bool visit[250][250];

int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dy[8] = {-1, 0, 1, 1, -1, -1, 0, 1};

void Input()
{
    cin >> M >> N;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }
}

void BFS(int x, int y)
{
    queue<int> qx, qy;
    qx.push(x), qy.push(y);
    visit[x][y] = 1;

    while (!qx.empty())
    {
        int cx = qx.front(), cy = qy.front();
        qx.pop(), qy.pop();

        for (int i = 0; i < 8; i++)
        {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (nx < 0 || ny < 0 || nx >= M || ny >= N || visit[nx][ny] || !map[nx][ny])
                continue;
            visit[nx][ny] = 1;
            qx.push(nx), qy.push(ny);
        }
    }
}

void Solution()
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visit[i][j] && map[i][j])
            {
                ans++;
                BFS(i, j);
            }
        }
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Input();
    Solution();
}