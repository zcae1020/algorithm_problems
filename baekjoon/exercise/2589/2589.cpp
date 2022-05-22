#include <iostream>
#include <queue>
#include <cstring>
#define pii pair<int, int>

using namespace std;

int N, M, ans;
char map[100][100];

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

void Input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> map[i];
}

int BFS(pii t)
{
    int ret = 0;
    queue<pair<pii, int>> q;
    bool visit[100][100];
    memset(visit, 0, sizeof(visit));
    q.push(make_pair(t, 0));
    visit[t.first][t.second] = true;

    while (!q.empty())
    {
        pii cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (ret < cnt)
            ret = cnt;

        for (int i = 0; i < 4; i++)
        {
            pii next = {cur.first + dx[i], cur.second + dy[i]};
            if (next.first < 0 || next.second < 0 || next.first >= N || next.second >= M || visit[next.first][next.second] || map[next.first][next.second] == 'W')
                continue;

            visit[next.first][next.second] = true;
            q.push(make_pair(next, cnt + 1));
        }
    }

    return ret;
}

void Solution()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (map[i][j] == 'L')
                ans = max(ans, BFS({i, j}));
                
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Input();
    Solution();
}