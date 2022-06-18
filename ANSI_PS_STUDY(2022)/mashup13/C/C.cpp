#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

const int maxn = 10;

int n;

void Solution()
{
    ll ans = 0;
    pii input[maxn];
    int arr[maxn] = {0};
    vector<vector<int>> edge;

    cin >> n;
    edge.resize(n + 10);
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        input[i] = pii(a, b);
    }

    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    priority_queue<pii> pq;
    for (int i = 1; i <= n; i++)
        pq.push(pii(edge[i].size(), i));

    while (pq.size())
    {
        int cur = pq.top().second;
        pq.pop();

        if (arr[cur])
            continue;

        ll f = 0, s = 0;
        for (auto a : edge[cur])
        {
            if (arr[a])
                f += abs(input[cur].first - arr[a]);
            else
                f += max(abs(input[cur].first - input[a].first), abs(input[cur].first - input[a].second));
        }
        for (auto a : edge[cur])
        {
            if (arr[a])
                s += abs(input[cur].second - arr[a]);
            else
                s += max(abs(input[cur].second - input[a].first), abs(input[cur].second - input[a].second));
        }

        arr[cur] = f > s ? input[cur].first : input[cur].second;

        for (auto a : edge[cur])
        {
            if (arr[a] == 0)
            {
                if (abs(arr[cur] - input[a].first) > abs(arr[cur] - input[a].second))
                    arr[a] = input[a].first;
                else
                    arr[a] = input[a].second;
            }
            ans += abs(arr[cur] - arr[a]);
        }
    }

    cout << ans << '\n';
}

int main()
{
    FASTIO
    int tc;
    cin >> tc;
    while (tc--)
        Solution();
}