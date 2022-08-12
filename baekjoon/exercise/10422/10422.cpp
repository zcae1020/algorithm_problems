#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

const ll maxl = 5010, MOD = 1e9 + 7;

/*
i=2: 1
i=4: 1 1
i=6: 1 2 1
i=8: 1 3 3 1
i=10: 1 4 6 4 1
    .
    .
    .

*/

int t;
ll dp[maxl][maxl], rdp[maxl];

void Solution()
{
    for (int i = 2; i <= 5000; i += 2)
    {
        dp[i][0] = dp[i][(i - 1) / 2] = 1;
        for (int j = 1; j < (i - 1) / 2; j++)
            dp[i][j] = (dp[i - 2][j - 1] + dp[i - 2][j]) % MOD;
        for (int j = 0; j <= (i - 1) / 2; j++)
            rdp[i] = (rdp[i] + dp[i][j]) % MOD;
    }

    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        cout << rdp[x] << '\n';
    }
}

int main()
{
    FASTIO
    Solution();
}