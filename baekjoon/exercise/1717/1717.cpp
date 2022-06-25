#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

const int maxn = 1e6 + 10;

int n, m, par[maxn];

int find(int u)
{
    if (par[u] == u)
        return u;

    return par[u] = find(par[u]);
}

void merge(int u, int v)
{
    u = find(u), v = find(v);
    par[u] = v;
}

void Solution()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        par[i] = i;

    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0)
            merge(b, c);
        else
        {
            if (find(b) == find(c))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}

int main()
{
    FASTIO
    Solution();
}