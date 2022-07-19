#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

struct ss
{
    int a, b, c;
};

bool cmp(ss a, ss b)
{
    return a.c < b.c;
}

const int maxv = 1e4 + 10;

int v, e, ans, par[maxv];
vector<ss> ve;

int find(int u)
{
    return u == par[u] ? u : par[u] = find(par[u]);
}

void merge(int u, int v)
{
    u = find(u), v = find(v);

    par[u] = v;
}

void Solution()
{
    cin >> v >> e;
    for (int i = 1; i <= v; i++)
        par[i] = i;
    for (int i = 0; i < e; i++)
    {
        ss tmp;
        cin >> tmp.a >> tmp.b >> tmp.c;
        ve.push_back(tmp);
    }

    sort(ve.begin(), ve.end(), cmp);

    for (auto t : ve)
    {
        auto [a, b, c] = t;
        if (find(a) == find(b))
            continue;
        ans += c;
        merge(a, b);
    }

    cout << ans;
}

int main()
{
    FASTIO
    Solution();
}