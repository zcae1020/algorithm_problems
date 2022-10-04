#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define pll pair<long long, long long>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

const int maxN = 1 << 3 + 10;

int N, M;
int par[maxN];
pll p[maxN];
double ans;

int find(int u)
{
    return (u == par[u] ? u : par[u] = find(par[u]));
}

void merge(int u, int v)
{
    u = find(u), v = find(v);

    par[u] = v;
}

double getDist(pll p1, pll p2)
{
    return sqrt((double)((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second)));
}

void Solution()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        int a, b;
        cin >> a >> b;
        p[i] = {a, b};
        par[i] = i;
    }
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }

    priority_queue<pair<double, pii>> pq;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j < i; j++)
        {
            pq.push({-getDist(p[i], p[j]), make_pair(i, j)});
        }
    }

    while (!pq.empty())
    {
        double d = -pq.top().first;
        int a = pq.top().sd.fs;
        int b = pq.top().sd.sd;
        pq.pop();

        if (find(a) != find(b))
        {
            ans += d;
            merge(a, b);
        }
    }

    printf("%.2lf", ans);
}

int main()
{
    FASTIO
    Solution();
}