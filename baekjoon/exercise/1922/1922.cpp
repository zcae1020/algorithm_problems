#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

struct s
{
    int a, b, c;
    bool operator<(s &tmp)
    {
        return c < tmp.c;
    }
};

int n, m, par[1001], ans;
vector<s> v;

int find(int u)
{
    return par[u] == u ? u : par[u] = find(par[u]);
}

bool merge(int u, int v)
{
    u = find(u), v = find(v);

    par[u] = v;

    return u != v;
}

void Solution()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        par[i] = i;

    for (int i = 0; i < m; i++)
    {
        s tmp;
        cin >> tmp.a >> tmp.b >> tmp.c;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    for (auto t : v)
        if (merge(t.a, t.b))
            ans += t.c;

    cout << ans;
}

int main()
{
    FASTIO
    Solution();
}