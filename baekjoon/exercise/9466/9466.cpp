#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

const int maxn = 1e5 + 10;

int tc, n, a[maxn], visited[maxn], color, ans;

int dfs1(int cur, int dist)
{
    if (cur == dist)
        return 1;
    return dfs1(a[cur], dist) + 1;
}

void dfs(int cur, int pre)
{
    if (visited[cur])
    {
        if (visited[cur] == color)
            ans += dfs1(cur, pre);
        return;
    }

    visited[cur] = color;
    dfs(a[cur], cur);
}

void Solution()
{
    cin >> tc;
    while (tc--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                color++;
                dfs(i, i);
            }
        }

        cout << n - ans << '\n';

        color = ans = 0;
        memset(visited, 0, sizeof(visited));
    }
}

int main()
{
    FASTIO
    Solution();
}