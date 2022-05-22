#include <iostream>
#include <vector>
#include <queue>
#define pii pair<int, int>
#define MAX 1000000000

using namespace std;

int n, m, s, e;
vector<vector<pii>> route;
vector<int> Dist;

void Input()
{
    cin >> n >> m;
    route.resize(n);
    Dist.resize(n);
    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        route[a - 1].push_back({b - 1, c});
    }
    cin >> s >> e;
    s--, e--;
}

void Solution()
{
    for (int i = 0; i < n; i++)
        Dist[i] = MAX;

    priority_queue<pii> pq;
    pq.push({s, 0});

    while (!pq.empty())
    {
        int cur = pq.top().first, dist = -pq.top().second;
        pq.pop();

        if (Dist[cur] < dist)
            continue;

        for (auto a : route[cur])
        {
            int next = a.first, ndist = dist + a.second;

            if (Dist[next] > ndist)
            {
                Dist[next] = ndist;
                pq.push({next, -ndist});
            }
        }
    }

    cout << Dist[e];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Input();
    Solution();
}