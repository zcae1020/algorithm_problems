#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int N, M, L, ans = 1e9;
vector<int> hu, dist;

void dfs(int idx, int prevSize, int remain, int mx)
{
    if (idx == -1)
    {
        ans = min(ans, mx);
        return;
    }
    for (int i = remain; i >= 0; i--)
    {
        if (i <= prevSize)
        {
            int nmx = max(mx, dist[idx] / (i + 1) + (dist[idx] % (i + 1) > 0));
            dfs(idx - 1, i, remain - i, nmx);
        }
    }
}

void Solution()
{
    cin >> N >> M >> L;

    hu.push_back(0);
    hu.push_back(L);
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        hu.push_back(x);
    }

    sort(hu.begin(), hu.end());

    for (int i = 1; i < N + 2; i++)
        dist.push_back(hu[i] - hu[i - 1]);

    sort(dist.begin(), dist.end());

    dfs(dist.size() - 1, M, M, 0);

    cout << ans;
}

int main()
{
    FASTIO
    Solution();
}
