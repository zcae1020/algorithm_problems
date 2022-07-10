#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

int n, m, par[500001], ans;

int find(int u)
{
    return par[u] == u ? u : par[u] = find(par[u]);
}

void merge(int u, int v)
{
    u = find(u), v = find(v);

    par[u] = v;
}

void Solution()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        par[i] = i;

    while (m--)
    {
        int a, b;
        ans++;
        cin >> a >> b;
        if (find(a) == find(b))
        {
            cout << ans;
            return;
        }
        merge(a, b);
    }

    cout << 0;
}

int main()
{
    FASTIO
    Solution();
}