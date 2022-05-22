#include <iostream>
#include <vector>
#include <cstring>
#define pii pair<int, int>
#define MAX 1e9

using namespace std;

struct road
{
    int s, e, t;
};

int TC, N, M, W;
int d[510];
vector<road> v;

void Input()
{
    cin >> N >> M >> W;
    v.clear();
    int a, b, c;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> c;
        a--, b--;
        v.push_back({a, b, c});
        v.push_back({b, a, c});
    }
    for (int i = 0; i < W; i++)
    {
        cin >> a >> b >> c;
        a--, b--;
        v.push_back({a, b, -c});
    }
}

void Solution()
{
    for (int i = 0; i < 510; i++)
        d[i] = MAX;

    for (int i = 0; i < N - 1; i++)
    {
        for (auto a : v)
        {
            if (d[a.s] + a.t < d[a.e])
                d[a.e] = d[a.s] + a.t;
        }
    }

    for (auto a : v)
    {
        if (d[a.s] + a.t < d[a.e])
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> TC;
    while (TC--)
    {
        Input();
        Solution();
    }
}