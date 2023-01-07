#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int R, C, ans;
pii D, S;
vector<pii> water, posi;
string m[50];
bool visited[50][50];

int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

bool bfs()
{
    queue<pii> q;

    for (auto p : posi)
    {
        q.push(p);
    }

    posi.clear();

    while (!q.empty())
    {
        pii cur = q.front();
        q.pop();

        if (m[cur.fs][cur.sd] == '*')
        {
            continue;
        }

        for (int i = 0; i < 4; i++)
        {
            pii next = {cur.fs + dx[i], cur.sd + dy[i]};
            if (next.fs >= 0 && next.fs < R && next.sd >= 0 && next.sd < C &&
                !visited[next.fs][next.sd] && (m[next.fs][next.sd] == '.' || next == D))
            {
                if (next == D)
                {
                    return true;
                }
                visited[next.fs][next.sd] = true;
                posi.push_back(next);
            }
        }
    }

    return false;
}

void flooding()
{
    for (auto p : water)
    {
        for (int i = 0; i < 4; i++)
        {
            pii next = {p.fs + dx[i], p.sd + dy[i]};
            if (next.fs >= 0 && next.fs < R && next.sd >= 0 && next.sd < C && m[next.fs][next.sd] == '.')
            {
                m[next.fs][next.sd] = '*';
                water.push_back(next);
            }
        }
    }
}

void getAns()
{
    while (!posi.empty())
    {
        ans++;
        if (bfs())
        {
            return;
        }
        flooding();
    }

    ans = -1;
}

void Solution()
{
    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        cin >> m[i];
        for (int j = 0; j < C; j++)
        {
            if (m[i][j] == 'D')
            {
                D = {i, j};
            }
            if (m[i][j] == 'S')
            {
                S = {i, j};
            }
            if (m[i][j] == '*')
            {
                water.push_back({i, j});
            }
        }
    }

    posi.push_back(S);
    getAns();

    if (ans == -1)
    {
        cout << "KAKTUS";
        return;
    }

    cout << ans;
}

int main()
{
    FASTIO
    Solution();
}