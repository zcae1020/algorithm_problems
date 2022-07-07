#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

int n, m[500][2], dp[501][501];

void Solution()
{
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> m[i][0] >> m[i][1];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; i + j < n; j++)
        {
            dp[j][i + j] = INT_MAX;
            for (int k = j; k < i + j; k++)
            {
                dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + m[j][0] * m[k][1] * m[i + j][1]);
            }
        }
    }

    cout << dp[0][n - 1];
}

int main()
{
    FASTIO
    Solution();
}