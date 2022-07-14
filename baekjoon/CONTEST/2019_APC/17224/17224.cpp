#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

int n, l, k, ans, acnt, bcnt;

void Solution()
{
    cin >> n >> l >> k;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (b <= l)
            bcnt++;
        if (a <= l)
            acnt++;
    }

    if (bcnt >= k)
        ans = k * 140;
    else if (acnt >= k)
        ans = bcnt * 140 + (k - bcnt) * 100;
    else
        ans = bcnt * 140 + (acnt - bcnt) * 100;

    cout << ans;
}

int main()
{
    FASTIO
    Solution();
}