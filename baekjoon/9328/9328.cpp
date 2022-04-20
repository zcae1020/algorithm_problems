#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#define pii pair<int, int>

using namespace std;

int t, h, w, ans;
bool visit[102][102], key[26];
char map[102][102];

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

void init()
{
    memset(map, 0, sizeof(map));
    memset(key, 0, sizeof(key));
    memset(visit, 0, sizeof(visit));
    ans = 0;
}

void Input()
{
    cin >> h >> w;

    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            cin >> map[i][j];
        }
    }

    string first_key;
    cin >> first_key;
    if (first_key[0] != '0')
        for (auto a : first_key)
            key[a - 'a'] = true;
}

void bfs(int x, int y)
{
    queue<pii> q, door[26];
    q.push({x, y});
    visit[x][y] = true;

    while (!q.empty())
    {
        int cx = q.front().first, cy = q.front().second;
        q.pop();

        if (map[cx][cy] == '$')
            ans++;

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (nx < 0 || ny < 0 || nx > h + 1 || ny > w + 1 || visit[nx][ny] || map[nx][ny] == '*')
                continue;

            if (isupper(map[nx][ny]))
            {
                if (key[map[nx][ny] - 'A'])
                {
                    q.push({nx, ny});
                    visit[nx][ny] = true;
                }
                else
                    door[map[nx][ny] - 'A'].push({nx, ny});
            }
            else if (islower(map[nx][ny]))
            {
                key[map[nx][ny] - 'a'] = true;

                q.push({nx, ny});
                visit[nx][ny] = true;
                while (!door[map[nx][ny] - 'a'].empty())
                {
                    pii dcur = door[map[nx][ny] - 'a'].front();
                    q.push(dcur);
                    visit[dcur.first][dcur.second] = true;
                    door[map[nx][ny] - 'a'].pop();
                }
            }
            else
            {
                q.push({nx, ny});
                visit[nx][ny] = true;
            }
        }
    }
}

void Solution()
{
    bfs(0, 0);
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        init();
        Input();
        Solution();
    }
}