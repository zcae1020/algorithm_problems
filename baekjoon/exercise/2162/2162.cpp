#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

fdsfd
//nonsolving

typedef struct L
{
    pii p1;
    pii p2;
} L;

int n, par[3001];
vector<L> v;

int find(int u)
{
    return u == par[u] ? u : par[u] = find(par[u]);
}

void merge(int u, int v)
{
    u = find(u), v = find(v);

    if (u < v)
        swap(u, v);
    par[u] = v;
}

int ccw(pii p1, pii p2, pii p3)
{
    int cross_product = (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);

    if (cross_product > 0)
        return 1;
    else if (cross_product < 0)
        return -1;
    else
        return 0;
}

int lineIntersection(L l1, L l2)
{
    int l1_l2 = ccw(l1.p1, l1.p2, l2.p1) * ccw(l1.p1, l1.p2, l2.p2);
    int l2_l1 = ccw(l2.p1, l2.p2, l1.p1) * ccw(l2.p1, l2.p2, l1.p2);

    if (l1_l2 == 0 && l2_l1)
    {
        if (l1.p1 < l1.p2)
            swap(l1.p1, l1.p2);
        if (l2.p1 < l2.p2)
            swap(l2.p1, l2.p2);

        return l2.p1 <= l1.p2 && l1.p1 <= l2.p2;
    }

    return (l1_l2 <= 0) && (l2_l1 <= 0);
}

void Solution()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        par[i] = i;
        L t;
        cin >> t.p1.x >> t.p1.y >> t.p2.x >> t.p2.y;
        v.push_back(t);

        for (int j = 0; j < i; j++)
            if (lineIntersection(v[i], v[j]))
                merge(i, j);
    }

    int mx = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
        mx = max(mx, (int)++m[par[i]]);

    cout << m.size() << '\n'
         << mx;
}

int main()
{
    FASTIO
    Solution();
}