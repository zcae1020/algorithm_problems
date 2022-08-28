#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

int n, arr[1000], dp[1000], mx;

void Solution()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
    {
        mx = 0;
        for (int j = 0; j < i; j++)
            if (arr[i] < arr[j])
                mx = mx < dp[j] ? dp[j] : mx;
        dp[i] = ++mx;
    }

    mx = 0;
    for (int i = 0; i < n; i++)
        mx = mx < dp[i] ? dp[i] : mx;

    cout << mx;
}

int main()
{
    FASTIO
    Solution();
}