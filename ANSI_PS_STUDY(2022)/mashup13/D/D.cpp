#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

const int maxn = 2e5 + 10;

void Solution()
{
    int n, k, cnt[31] = {0}, ans = 0;

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        for (int a = 1, b = 0; b < 31; a <<= 1, b++)
            cnt[b] += (x & a ? 1 : 0);
    }

    for (int i = 30; i >= 0; i--)
    {
        if (n - cnt[i] <= k)
        {
            k -= (n - cnt[i]);
            ans |= (1 << i);
        }
    }

    cout << ans << '\n';
}

int main()
{
    FASTIO
    int t;
    cin >> t;
    while (t--)
        Solution();
}