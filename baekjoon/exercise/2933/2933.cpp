#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int R, C, N, turn;
map<int, int> m;
int heightArr[100];
int diff;
string M[100];

int dx[] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

vector<pii> getCluster(pii s)
{
    vector<pii> ret;
    bool visited[100][100] = {false};

    queue<pii> q;
    q.push(s);
    visited[s.fs][s.sd] = true;

    while (!q.empty())
    {
        pii cur = q.front();
        q.pop();

        ret.push_back(cur);
        m[cur.sd] = max(m[cur.sd], cur.fs);

        for (int i = 0; i < 4; i++)
        {
            pii next = {cur.fs + dx[i], cur.sd + dy[i]};
            if (next.fs >= 0 && next.sd >= 0 && next.fs < R && next.sd < C &&
                !visited[next.fs][next.sd] && M[next.fs][next.sd] == 'x')
            {
                visited[next.fs][next.sd] = true;
                q.push(next);
            }
        }
    }

    return ret;
}

void gravity(int r, int c)
{
    vector<pii> v;
    string newM[100];

    for (int i = 0; i < R; i++)
    {
        newM[i] = M[i];
    }

    diff = 1000;

    for (auto a : m)
    {
        if (a.sd == R - 1)
        {
            diff = 0;
            break;
        }
        for (int i = R - 1; i > a.sd; i--)
        {
            if (M[i][a.fs] == '.')
            {
                diff = min(diff, i - a.sd);
                break;
            }
        }
    }

    diff = diff == 1000 ? 0 : diff;

    for (auto p : v)
    {
        newM[p.fs][p.sd] = '.';
    }

    for (auto p : v)
    {
        newM[p.fs + diff][p.sd] = 'x';
    }

    for (int i = 0; i < R; i++)
    {
        M[i] = newM[i];
    }
}

void attack(int height)
{
    if (turn)
    { // r->l
        for (int i = C - 1; i >= 0; i--)
        {
            if (M[height][i] == 'x')
            {
                M[height][i] = '.';
                for(int j=0;j<4;j++) {
                    pii near = {r + dx[jh, c + dy[j]};

                    if (M[near.fs][near.sd] == 'x')
                    {
                        m.clear();
                        v = getCluster(near);
                        gravity(v);
                    }
                }
                break;
            }
        }
    }
    else
    { // l->r
        for (int i = 0; i < C; i++)
        {
            if (M[height][i] == 'x')
            {
                M[height][i] = '.';
                for(int j=0;j<4;j++) {
                    pii near = {r + dx[jh, c + dy[j]};

                    if (M[near.fs][near.sd] == 'x')
                    {
                        m.clear();
                        v = getCluster(near);
                        gravity(v);
                    }
                }
                break;
            }
        }
    }
}

void Solution()
{
    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        cin >> M[i];
    }

    cin >> N;
    while (N--)
    {
        int height;
        cin >> height;
        attack(R - height);
        turn = turn ? 0 : 1;
    }

    for (int i = 0; i < R; i++)
    {
        cout << M[i] << '\n';
    }
}

int main()
{
    FASTIO
    Solution();
}