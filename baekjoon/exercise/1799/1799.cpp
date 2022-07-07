#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

int n, m[10][10], sel[10][10], ans;
vector<vector<pii>> v;

bool check(pii p)
{
    int dx[4] = {1, 1, -1, -1}, dy[4] = {1, -1, 1, -1};

    for (int i = 0; i < 4; i++)
        for (int x = p.first, y = p.second; x >= 0 && y >= 0 && x < n && y < n; x += dx[i], y += dy[i])
            if (sel[x][y])
                return false;

    return true;
}

void dfs(int idx, int cnt)
{
    if (ans >= v.size() - idx + cnt)
        return;

    if (idx == v.size())
    {
        ans = max(ans, cnt);
        return;
    }

    dfs(idx + 1, cnt);

    for (auto a : v[idx])
    {
        if (check(a))
        {
            sel[a.first][a.second] = 1;
            dfs(idx + 1, cnt + 1);
            sel[a.first][a.second] = 0;
        }
    }
}

void Solution()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> m[i][j];

    for (int i = 0, j = 0; i < n; i++)
    {
        vector<pii> tmp;
        for (int ii = i, jj = j; ii < n && jj < n; ii++, jj++)
            if (m[ii][jj])
                tmp.push_back({ii, jj});
        v.push_back(tmp);
    }
    for (int i = 0, j = 1; j < n; j++)
    {
        vector<pii> tmp;
        for (int ii = i, jj = j; ii < n && jj < n; ii++, jj++)
            if (m[ii][jj])
                tmp.push_back({ii, jj});
        v.push_back(tmp);
    }

    dfs(0, 0);

    cout << ans;
}

int main()
{
    FASTIO
    Solution();
}