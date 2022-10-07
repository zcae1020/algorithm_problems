#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int N, A[1000], dp[1000], ans;

void Solution()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        dp[i] = A[i];
    }

    for (int i = 0; i < N; i++)
    {
        int mx = 0;
        for (int j = 0; j < i; j++)
        {
            if (A[i] > A[j])
                mx = max(mx, dp[j]);
        }
        dp[i] += mx;
        ans = max(ans, dp[i]);
    }

    cout << ans;
}

int main()
{
    FASTIO
    Solution();
}