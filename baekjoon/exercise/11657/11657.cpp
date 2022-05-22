#include <iostream>
#include <vector>
#include <queue>
#define MAX 1e9

using namespace std;

struct edge
{
    int from, to, cost;
};

int N, M;
long long dist[500];
vector<edge> v;

void Input()
{
    cin >> N >> M;
    int a, b, c;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> c;
        a--, b--;
        v.push_back({a, b, c});
    }
}

void Solution()
{
    for (int i = 0; i < N; i++)
        dist[i] = MAX;

    dist[0] = 0;

    for (int i = 1; i < N; i++)
        for (int i = 0; i < M; i++)
            if (dist[v[i].from] != MAX)
                if (dist[v[i].to] > dist[v[i].from] + v[i].cost)
                    dist[v[i].to] = dist[v[i].from] + v[i].cost;

    for (int i = 0; i < M; i++)
        if (dist[v[i].from] != MAX)
            if (dist[v[i].to] > dist[v[i].from] + v[i].cost)
            {
                cout << -1;
                return;
            }

    for (int i = 1; i < N; i++)
    {
        if (dist[i] == MAX)
            cout << -1 << '\n';
        else
            cout << dist[i] << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Input();
    Solution();
}