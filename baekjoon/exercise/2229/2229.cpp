#include <iostream>
#include <cmath>

using namespace std;

int N, arr[1000], dp[1000], group[1000];

void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
}

void Solution()
{
    dp[0] = 0;
    dp[1] = abs(arr[0] - arr[1]);
    int mx, mn;
    for (int i = 1; i < N; i++)
    {
        dp[i] = dp[i - 1];
        mx = arr[i], mn = arr[i];
        for (int j = i - 1; j >= 0; j--)
        {
            mx = max(mx, arr[j]), mn = min(mn, arr[j]);
            dp[i] = max(dp[i], dp[j - 1] + abs(mx - mn));
        }
    }
    cout << dp[N - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Input();
    Solution();
}