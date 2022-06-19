#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;
//using namespace __gnu_pbds;

//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

const int maxn = 1e5 + 10;

int n, q, xcnt[maxn], ycnt[maxn];
// ordered_set sx, sy;

class segtree
{
public:
    bool tree[4 * maxn] = {false};
    bool update(int node, int s, int e, int target, bool diff)
    {
        if (target < s || e < target)
            return tree[node];
        if (s == e)
            return tree[node] = diff;
        int mid = (s + e) / 2;
        bool left = update(2 * node, s, mid, target, diff),
             right = update(2 * node + 1, mid + 1, e, target, diff);

        return tree[node] = left && right;
    }
    bool getAns(int node, int s, int e, int l, int r)
    {
        if (e < l || r < s)
            return true;
        if (l <= s && e <= r)
            return tree[node];
        int mid = (s + e) / 2;
        bool left = getAns(2 * node, s, mid, l, r),
             right = getAns(2 * node + 1, mid + 1, e, l, r);
        return left && right;
    }
} segx, segy;

void Solution()
{
    cin >> n >> q;
    while (q--)
    {
        int t, x1, x2, y1, y2;
        cin >> t;
        if (t == 1)
        {
            cin >> x1 >> y1;
            if (xcnt[x1] == 0)
                segx.update(1, 1, n, x1, 1);
            if (ycnt[y1] == 0)
                segy.update(1, 1, n, y1, 1);
            xcnt[x1]++;
            ycnt[y1]++;
        }
        else if (t == 2)
        {
            cin >> x1 >> y1;
            xcnt[x1]--;
            ycnt[y1]--;
            if (xcnt[x1] == 0)
                segx.update(1, 1, n, x1, 0);
            if (ycnt[y1] == 0)
                segx.update(1, 1, n, x1, 0);
        }
        else
        {
            cin >> x1 >> y1 >> x2 >> y2;

            if (segx.getAns(1, 1, n, x1, x2) || segy.getAns(1, 1, n, y1, y2))
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
}

int main()
{
    FASTIO
    Solution();
}