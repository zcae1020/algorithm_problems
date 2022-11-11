#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

const int maxn = 20;

ll n, m, k, x, y, z, seg[4 * maxn];

ll sum(ll s, ll e, ll node, ll l, ll r)
{
    if (e < l || r < s)
        return 0;
    if (l <= s && e <= r)
        return seg[node];
    ll mid = (s + e) / 2;
    return sum(s, mid, 2 * node, l, r) + sum(mid + 1, e, 2 * node + 1, l, r);
}

ll update(ll s, ll e, ll node, ll target, ll num)
{
    if (target < s || e < target)
        return seg[node];
    if (s == e)
        return seg[node] = num;
    ll mid = (s + e) / 2;
    return seg[node] = update(s, mid, 2 * node, target, num) + update(mid + 1, e, 2 * node + 1, target, num);
}

void Solution()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        update(1, n, 1, i, x);
    }

    for (int i = 0; i < m + k; i++)
    {
        cin >> x >> y >> z;
        if (x == 1)
            update(1, n, 1, y, z);
        else
            cout << sum(1, n, 1, y, z) << '\n';
    }
}

int main()
{
    FASTIO
    Solution();
}

// high = 1; // high는 자식노드 첫번째 index: segtree는 1부터 시작되기 때문
// while(high <n) high <<= 1;
// for(int i=0;i<n;i++) {
//     cin>>tree+high+i;
// }