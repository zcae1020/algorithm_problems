#include <iostream>

using namespace std;

int n, k, ans;

void Input()
{
    cin >> n >> k;
}

void Solution()
{
    int l = 1, r = k, m;
    while (l <= r)
    {
        long long cnt = 0;
        m = (l + r) / 2;
        for (int i = 1; i <= n; i++)
            cnt += min(m / i, n);
        if (cnt < k)
            l = m + 1;
        else
            ans = m, r = m - 1;
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Input();
    Solution();
}