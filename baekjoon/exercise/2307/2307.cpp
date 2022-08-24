#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

const int maxt = 2e9, maxM = 5000, maxN = 1001;

int N, M, road[maxM][3];
vector<pii> edge[maxN];

int dist[maxN], mnDist[maxN];

bool check(int a, int b, int c, int d)
{
    return ((a == c) && (b == d)) || ((a == d) && (b == c));
}

void mset()
{
    for (int i = 1; i <= N; i++)
        dist[i] = maxt;
}

int dijkstra(int a, int b)
{
    priority_queue<pii> pq;
    pq.push({0, 1});
    dist[1] = 0;

    while (pq.size())
    {
        int d = -pq.top().first, cur = pq.top().second;
        pq.pop();

        if (dist[cur] < d)
            continue;

        for (auto p : edge[cur])
        {
            if (!check(a, b, cur, p.first) && dist[p.first] > p.second + d)
            {
                if (a == b)
                    mnDist[p.first] = cur;
                dist[p.first] = p.second + d;
                pq.push({-dist[p.first], p.first});
            }
        }
    }

    return dist[N];
}

void Solution()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < 3; j++)
            cin >> road[i][j];
        edge[road[i][0]].push_back({road[i][1], road[i][2]});
        edge[road[i][1]].push_back({road[i][0], road[i][2]});
    }

    mset();
    int noPolice = dijkstra(0, 0), police = noPolice;

    for (int i = N; i != 1; i = mnDist[i])
    {
        mset();
        int dij = dijkstra(i, mnDist[i]);
        if (dij == maxt)
        {
            cout << -1;
            return;
        }
        police = max(police, dij);
    }

    cout << police - noPolice;
}

int main()
{
    FASTIO
    Solution();
}