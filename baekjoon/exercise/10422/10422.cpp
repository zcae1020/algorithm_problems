#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

const ll maxl = 5010, MOD = 1e9 + 7;

int t;
ll dp[maxl];

void Solution()
{
    dp[0] = dp[2] = 1;
    for (int i = 4; i <= 5000; i += 2)
        for (int j = 0; j <= i - 2; j += 2)
            dp[i] = (dp[i] + dp[i - 2 - j] * dp[j]) % MOD;

    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        cout << dp[x] << '\n';
    }
}

int main()
{
    FASTIO
    Solution();
}