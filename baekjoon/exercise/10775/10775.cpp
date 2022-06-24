#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

const int maxg = 1e5 + 10;

int G, P, ans, parent[maxg];

int find(int u)
{
    if (parent[u] == u)
        return u;

    return parent[u] = find(parent[u]);
}

void merge(int u, int v)
{
    u = find(u), v = find(v);
    parent[u] = v;
}

void Solution()
{
    cin >> G >> P;

    for (int i = 1; i <= G; i++)
        parent[i] = i;

    for (int i = 0; i < P; i++)
    {
        int x, xp;
        cin >> x;
        xp = find(x);
        if (xp == 0)
            break;
        else
        {
            merge(xp, xp - 1);
            ans++;
        }
    }
    cout << ans;
}

int main()
{
    FASTIO
    Solution();
}