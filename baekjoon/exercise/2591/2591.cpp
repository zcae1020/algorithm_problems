#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

string s;
int dp[40];

int dfs(int idx)
{
    int ret = 0;
    if (idx < 0)
        return 1;

    if (dp[idx])
        return dp[idx];

    if (s[idx] != '0')
        ret += dfs(idx - 1);
    if (idx > 0 && s[idx - 1] != '0')
    {
        int n = (s[idx - 1] - '0') * 10 + s[idx] - '0';
        if (n < 35)
            ret += dfs(idx - 2);
    }

    return dp[idx] = ret;
}

void Solution()
{
    cin >> s;

    dfs(s.size() - 1);

    cout << dp[s.size() - 1];
}

int main()
{
    FASTIO
    Solution();
}