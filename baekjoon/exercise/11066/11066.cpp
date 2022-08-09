#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

int tc, K, arr[501], psum[501], dp[501][501];

void Solution()
{
    cin >> tc;
    while (tc--)
    {
        cin >> K;
        for (int i = 1; i <= K; i++)
        {
            cin >> arr[i];
            psum[i] = psum[i - 1] + arr[i];
        }

        for (int i = 1; i < K; i++)
            dp[i][i + 1] = arr[i] + arr[i + 1];

        for (int l = 2; l < K; l++)
        {
            for (int s = 1; s + l <= K; s++)
            {
                int mn = 1e9;
                for (int d = 0; d < l; d++)
                    mn = min(mn, dp[s][s + d] + dp[s + d + 1][s + l]);
                dp[s][s + l] = psum[s + l] - psum[s - 1] + mn;
            }
        }

        cout << dp[1][K] << '\n';
    }
}

int main()
{
    FASTIO
    Solution();
}