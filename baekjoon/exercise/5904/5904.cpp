#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

bool ans = true;
int n;

void dq(int cnt, ll l, ll r)
{
    if (cnt < 3)
    {
        ans = false;
        return;
    }

    ll m1 = l + (r - l - cnt + 1) / 2, m2 = m1 + cnt;
    if (n == m1)
        return;

    if (l <= n && n < m1)
        dq(cnt - 1, l, m1);
    else if (m1 <= n && n < m2)
        dq(cnt - 1, m1, m2);
    else
        dq(cnt - 1, m2, r);
}

void Solution()
{
    ll cnt = 3, mx = 0;
    cin >> n;

    for (; mx <= n; mx = 2 * mx + cnt, cnt++);
    dq(cnt - 1, 1, mx + 1);

    if (ans)
        cout << 'm';
    else
        cout << 'o';
}

int main()
{
    FASTIO
    Solution();
}