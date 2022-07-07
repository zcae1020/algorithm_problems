#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

int n;
vector<vector<pii>> v;

pii bfs(int s)
{
    pii ret = {0, 0};
    vector<bool> visited(n + 1, 0);
    queue<pii> q;
    q.push({s, 0});
    visited[s] = 1;

    while (q.size())
    {
        pii cur = q.front();
        q.pop();

        if (cur.second > ret.second)
            ret = cur;

        for (auto next : v[cur.first])
            if (!visited[next.first])
            {
                q.push({next.first, cur.second + next.second});
                visited[next.first] = 1;
            }
    }

    return ret;
}

void Solution()
{
    cin >> n;
    v.resize(n + 1);

    for (int i = 1; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    pii tmp = bfs(1);

    cout << bfs(tmp.first).second;
}

int main()
{
    FASTIO
    Solution();
}