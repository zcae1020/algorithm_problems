#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

int n, edge[27][2];

void pretra(int cur)
{
    if (!edge[cur][0] && !edge[cur][1])
    {
        cout << char(cur + 'A' - 1);
        return;
    }

    cout << char(cur + 'A' - 1);
    if (edge[cur][0])
        pretra(edge[cur][0]);
    if (edge[cur][1])
        pretra(edge[cur][1]);
}

void midtra(int cur)
{
    if (!edge[cur][0] && !edge[cur][1])
    {
        cout << char(cur + 'A' - 1);
        return;
    }

    if (edge[cur][0])
        midtra(edge[cur][0]);
    cout << char(cur + 'A' - 1);
    if (edge[cur][1])
        midtra(edge[cur][1]);
}

void postra(int cur)
{
    if (!edge[cur][0] && !edge[cur][1])
    {
        cout << char(cur + 'A' - 1);
        return;
    }

    if (edge[cur][0])
        postra(edge[cur][0]);
    if (edge[cur][1])
        postra(edge[cur][1]);
    cout << char(cur + 'A' - 1);
}

void Solution()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char a, b, c;
        cin >> a >> b >> c;
        edge[a - 'A' + 1][0] = b == '.' ? 0 : b - 'A' + 1, edge[a - 'A' + 1][1] = c == '.' ? 0 : c - 'A' + 1;
    }

    pretra(1);
    cout << '\n';
    midtra(1);
    cout << '\n';
    postra(1);
}

int main()
{
    FASTIO
    Solution();
}