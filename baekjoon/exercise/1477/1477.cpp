#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int N, M, L, ans = 1000;
vector<int> hu, dist;

bool check(int len)
{
    int sum = 0;
    for (auto d : dist)
    {
        if (len <= d)
        {
            sum += d / len;
            sum += (d % len > 0);
            sum--;
        }
    }
    return sum <= M;
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

    int l = 1, r = 500;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            ans = min(ans, mid);
            r = mid - 1;
        }
        else
            l = mid + 1;
    }

    cout << ans;
}

int main()
{
    FASTIO
    Solution();
}
