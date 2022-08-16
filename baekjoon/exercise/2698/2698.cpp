#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

int tc, dp[102][101][2]; //[n][k][f]

int getAns(int n, int k, int f)
{
    if (k < 0)
        return 0;

    if (n == 2)
    {
        if (f == 1)
        {
            if (k < 2)
                return 1;
        }
        else
        {
            if (k == 0)
                return 2;
        }
        return 0;
    }

    if (dp[n][k][f] != -1)
        return dp[n][k][f];

    if (f)
        return dp[n][k][f] = getAns(n - 1, k - 1, 1) + getAns(n - 1, k, 0);
    else
        return dp[n][k][f] = getAns(n - 1, k, 1) + getAns(n - 1, k, 0);
}

void Solution()
{
    cin >> tc;
    memset(dp, -1, sizeof(dp));

    while (tc--)
    {
        int n, k;
        cin >> n >> k;
        cout << getAns(n + 1, k, 0) << '\n';
    }
}

int main()
{
    FASTIO
    Solution();
}