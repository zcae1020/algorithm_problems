#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

const int maxv = 1e5 + 10;

int v, node, mx;
vector<pii> edge[maxv];

void dfs(int pre, int cur, int dist)
{
    if (edge[cur].size() == 1 && edge[cur][0].first == pre)
    {
        if (mx < dist)
        {
            node = cur;
            mx = dist;
        }
        return;
    }
    
    for (auto a : edge[cur])
    {
        if (pre == a.first)
            continue;
        dfs(cur, a.first, dist + a.second);
    }
}

void Solution()
{
    cin >> v;
    for (int i = 0; i < v; i++)
    {
        int n;
        cin >> n;
        while (1)
        {
            int a, b;
            cin >> a;
            if (a == -1)
                break;
            cin >> b;
            edge[n].push_back(pii(a, b));
        }
    }

    dfs(1, 1, 0);
    mx = 0;
    dfs(node, node, 0);
    cout << mx;
}

int main()
{
    FASTIO
    Solution();
}