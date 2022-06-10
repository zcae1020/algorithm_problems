#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

const int maxn = 1e5 + 10, inf = INT_MAX;

int n, m, tree[4 * maxn];

int update(int pos, int val, int cur, int s, int e)
{
    if (pos < s || e < pos)
        return tree[cur];
    if (s == e)
        return tree[cur] = val;
    int mid = (s + e) / 2;
    return tree[cur] = min(update(pos, val, 2 * cur, s, mid), update(pos, val, 2 * cur + 1, mid + 1, e));
}

int getAns(int cur, int s, int e, int l, int r)
{
    if (e < l || r < s)
        return inf;
    if (l <= s && e <= r)
        return tree[cur];
    int mid = (s + e) / 2;
    return min(getAns(2 * cur, s, mid, l, r), getAns(2 * cur + 1, mid + 1, e, l, r));
}

void Solution()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        update(i, x, 1, 1, n);
    }

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << getAns(1, 1, n, x, y) << '\n';
    }
}

int main()
{
    FASTIO
    Solution();
}