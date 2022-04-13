#include <iostream>

using namespace std;

int n, dp[10], ans;

void Input()
{
    cin >> n;
    n--;
    for (int i = 0; i < 10; i++)
        dp[i] = 1;
}

void Solution()
{
    while (n--)
        for (int i = 9; i >= 0; i--)
            for (int j = i - 1; j >= 0; j--)
                dp[i] = (dp[i] + dp[j]) % 10007;
    for (int i = 0; i < 10; i++)
        ans = (ans + dp[i]) % 10007;
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Input();
    Solution();
}