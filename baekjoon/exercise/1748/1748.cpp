#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

int n, ans;

void Solution()
{
    cin >> n;

    if (n < 10)
    {
        cout << n;
        return;
    }
    else
        ans = 9;

    for (int i = 100, j = 2; i < 1e9 + 10; i *= 10, j++)
    {
        if (n >= i)
        {
            ans += (i - i / 10) * j;
        }
        else
        {
            n -= (i / 10 - 1);
            ans += n * j;
            break;
        }
    }

    cout << ans;
}

int main()
{
    FASTIO
    Solution();
}