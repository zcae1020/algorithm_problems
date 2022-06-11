#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

const int maxn = 1e5 + 10;

int n, m;
pii tree[4 * maxn];

pii update(int node, int s, int e, int pos, int val)
{
    if (pos < s || e < pos)
        return tree[node] == pii(0, 0) ? pii(1e9, 0) : tree[node];
    if (s == e)
        return tree[node] = pii(val, val);

    int mid = (s + e) / 2;
    pii a = update(2 * node, s, mid, pos, val);
    a = a == pii(0, 0) ? pii(1e9, 0) : a;
    pii b = update(2 * node + 1, mid + 1, e, pos, val);
    b = b == pii(0, 0) ? pii(1e9, 0) : b;

    return tree[node] = pii(min(a.first, b.first), max(a.second, b.second));
}

pii getAns(int node, int s, int e, int l, int r)
{
    if (e < l || r < s)
        return pii(1e9, 0);
    if (l <= s && e <= r)
        return tree[node];

    int mid = (s + e) / 2;
    pii a = getAns(2 * node, s, mid, l, r);
    pii b = getAns(2 * node + 1, mid + 1, e, l, r);

    return pii(min(a.first, b.first), max(a.second, b.second));
}

void Solution()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        update(1, 1, n, i, x);
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        pii ans = getAns(1, 1, n, a, b);
        cout << ans.first << ' ' << ans.second << '\n';
    }
}

int main()
{
    FASTIO
    Solution();
}