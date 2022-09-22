#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

const int maxM = 1e4;

int N, M, K, need;
int par[maxM], A[maxM];

int find(int u)
{
    return (u == par[u] ? u : par[u] = find(par[u]));
}

void merge(int u, int v)
{
    u = find(u), v = find(v);

    if (u != v)
    {
        if (A[u] < A[v])
            par[v] = u;
        else
            par[u] = v;
    }
}

void Solution()
{
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
        par[i] = i;

    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        merge(a - 1, b - 1);
    }

    for (int i = 0; i < N; i++)
        if (par[i] == i)
            need += A[i];

    if (need > K)
        cout << "Oh no";
    else
        cout << need;
}

int main()
{
    FASTIO
    Solution();
}