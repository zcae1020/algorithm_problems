#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

const int maxn = 1e5 + 10;

int n, dp[maxn];

void Solution()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        dp[i] = i;
        for (int j = 1; j * j <= i; j++)
            dp[i] = min(dp[i], dp[i - j * j] + 1);
    }

    cout << dp[n];
}

int main()
{
    FASTIO
    Solution();
}