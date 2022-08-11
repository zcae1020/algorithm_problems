#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

int n, m, r, t[101], ans;
vector<pii> v[101];

int bfs(int s)
{
    int ret = t[s], l[101] = {0};
    priority_queue<pii> pq;
    pq.push({0, s});
    l[s] = -1;

    while (pq.size())
    {
        int cur = pq.top().second;
        int len = -pq.top().first;
        pq.pop();

        for (auto next : v[cur])
        {
            if (l[next.first] && next.second + len < l[next.first])
            {
                pq.push({-(next.second + len), next.first});
                l[next.first] = next.second + len;
            }
            if (!l[next.first] && next.second + len <= m)
            {
                pq.push({-(next.second + len), next.first});
                l[next.first] = next.second + len;
                ret += t[next.first];
            }
        }
    }

    return ret;
}

void Solution()
{
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++)
        cin >> t[i];

    for (int i = 0; i < r; i++)
    {
        int a, b, l;
        cin >> a >> b >> l;
        v[a].push_back({b, l});
        v[b].push_back({a, l});
    }

    for (int i = 1; i <= n; i++)
        ans = max(ans, bfs(i));

    cout << ans;
}

int main()
{
    FASTIO
    Solution();
}