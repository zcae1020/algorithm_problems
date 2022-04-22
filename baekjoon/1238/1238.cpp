#include <iostream>
#include <vector>
#include <queue>
#define pii pair<int, int>
#define MAX 1000000009

using namespace std;

int n, m, x, ans;
vector<vector<pii>> edge;
vector<int> dist, x2Dist;

void Input()
{
    cin >> n >> m >> x;
    edge.resize(n);
    dist.resize(n);
    x2Dist.resize(n);

    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        edge[a - 1].push_back({b - 1, c});
    }
}

void getx2Dist()
{
    for (int i = 0; i < n; i++)
        x2Dist[i] = MAX;

    priority_queue<pii> pq;
    pq.push({x - 1, 0});
    x2Dist[x - 1] = 0;

    while (!pq.empty())
    {
        int cur = pq.top().first, curd = -pq.top().second;
        pq.pop();

        if (x2Dist[cur] < curd)
            continue;

        for (auto a : edge[cur])
        {
            int next = a.first, nextd = curd + a.second;

            if (x2Dist[next] > nextd)
            {
                x2Dist[next] = nextd;
                pq.push({next, -nextd});
            }
        }
    }
}

int dijkstra(int start)
{
    for (int i = 0; i < n; i++)
        dist[i] = MAX;

    priority_queue<pii> pq;
    pq.push({start, 0});
    dist[start] = 0;

    while (!pq.empty())
    {
        int cur = pq.top().first, curd = -pq.top().second;
        pq.pop();

        if (dist[cur] < curd)
            continue;

        for (auto a : edge[cur])
        {
            int next = a.first, nextd = curd + a.second;

            if (dist[next] > nextd)
            {
                dist[next] = nextd;
                pq.push({next, -nextd});
            }
        }
    }

    return x2Dist[start] + dist[x - 1];
}

void Solution()
{
    getx2Dist();
    for (int i = 0; i < n; i++)
        ans = max(ans, dijkstra(i));
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Input();
    Solution();
}