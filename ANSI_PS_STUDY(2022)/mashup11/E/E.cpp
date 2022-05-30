#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

const int maxn = 2e5 + 10;

int n;
vector<vector<int>> v(maxn);
vector<int> dp(maxn);

int dfs(int cur, int pre)
{
    for (auto next : v[cur])
    {
        if (next == pre)
            continue;
        int d = dfs(next, cur);
        dp[cur] += max(d, 0);
    }
    return dp[cur];
}

void dfs2(int cur, int pre)
{
    if (pre)
        dp[cur] += max(dp[pre] - max(dp[cur], 0), 0);
    for (auto next : v[cur])
    {
        if (next == pre)
            continue;
        dfs2(next, cur);
    }
}

void Solution()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        dp[i] = a ? 1 : -1;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1, 0);
    dfs2(1, 0);

    for (int i = 1; i <= n; i++)
        cout << dp[i] << ' ';
}

int main()
{
    FASTIO
    Solution();
}