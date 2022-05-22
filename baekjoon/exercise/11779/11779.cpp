#include <iostream>
#include <queue>
#include <vector>
#define pii pair<int, int>
#define MAX 1000000000

using namespace std;

int n, m, s, e;
vector<vector<pii>> edge;
vector<pii> d;

void Input()
{
    cin >> n >> m;
    edge.resize(n + 1);
    d.resize(n + 1);
    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
    }
    cin >> s >> e;
    for (int i = 1; i <= n; i++)
        d[i].second = MAX;
}

void Solution()
{
    priority_queue<pii> pq;
    pq.push({s, 0});
    d[s].second = 0;

    while (!pq.empty())
    {
        int cur = pq.top().first, dist = -pq.top().second;
        pq.pop();

        if (d[cur].second < dist)
            continue;

        for (auto a : edge[cur])
        {
            int next = a.first, ndist = a.second + dist;

            if (d[next].second > ndist)
            {
                d[next] = {cur, ndist};
                pq.push({next, -ndist});
            }
        }
    }

    vector<int> route;
    route.push_back(e);
    while (route.back())
        route.push_back(d[route.back()].first);
    cout << d[e].second << '\n'
         << route.size() - 1 << '\n';
    for (int i = route.size() - 2; i >= 0; i--)
        cout << route[i] << ' ';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Input();
    Solution();
}