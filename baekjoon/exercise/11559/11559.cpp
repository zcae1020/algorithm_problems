#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

string m[12];
int t;
bool visited[12][6];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

char getColor(pii p)
{
    return m[p.first][p.second];
}

bool isValid(pii p)
{
    return !visited[p.first][p.second] && p.first >= 0 && p.first < 12 && p.second >= 0 && p.second < 6;
}

void boom(vector<pii> list)
{
    for (auto l : list)
    {
        m[l.first][l.second] = '.';
    }
}

bool bfs(pii p)
{
    int cnt = 0;
    vector<pii> list;
    queue<pii> q;
    q.push(p);

    while (!q.empty())
    {
        pii cur = q.front();
        q.pop();
        cnt++;
        list.push_back(cur);

        for (int i = 0; i < 4; i++)
        {
            pii next = {dx[i] + cur.first, dy[i] + cur.second};
            if (isValid(next) && getColor(p) == getColor(next))
            {
                visited[next.first][next.second] = 1;
                q.push(next);
            }
        }
    }

    if (cnt >= 4)
    {
        boom(list);
        return true;
    }

    return false;
}

bool isPuyo()
{
    bool ret = false;

    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            visited[i][j] = true;
            if (m[i][j] != '.')
            {
                ret = bfs({i, j}) || ret;
            }
        }
    }

    return ret;
}

void getDown()
{
    for (int i = 0; i < 6; i++)
    {
        string s;
        for (int j = 11; j >= 0; j--)
        {
            if (m[j][i] != '.')
            {
                s.push_back(m[j][i]);
            }
            m[j][i] = '.';
        }

        for (int j = 11, k = 0; j >= 0 && k < s.size(); j--, k++)
        {
            m[j][i] = s[k];
        }
    }
}

void Solution()
{
    for (int i = 0; i < 12; i++)
    {
        cin >> m[i];
    }

    while (isPuyo())
    {
        getDown();
        t++;
    }

    cout << t;
}

int main()
{
    FASTIO
    Solution();
}